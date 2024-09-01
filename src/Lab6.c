/**
 * @file lab6.h
 * @author Robledo, Valentín
 * @brief Source file that implements the functions to load the file and obtain samples.
 * @version 1.0
 * @date Noviembre de 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../inc/Lab6.h"

char* buffer;

int main(void)
{
    u_int8_t n;
    u_int32_t mapbytes;

    char* mapaddres = load_data("rawdata/datos", &mapbytes);
    RMA1** samples = get_samples(mapaddres, mapbytes, &n);

    u_int32_t sum = 0;
    
    for (u_int8_t i = 0; i < n; i++)
        sum += samples[i]->validSamples;

    printf("-> Total of samples: %d\n", n);
    printf("-> Prom of validSamples: %d\n", sum / n);
    
    free(samples);

    munmap(mapaddres, mapbytes);

    return EXIT_SUCCESS;

    return 0;
}

char* load_data(char* file, u_int32_t* mapbytes)
{
    char* mapaddres;
    struct stat stats_of_file; 
    int fd;

    if((fd = open(file, O_RDONLY)) < 0)
    {
        perror("Error trying to open file."); 
        exit(EXIT_FAILURE);
    }

    fstat(fd, &stats_of_file);

    mapaddres = (char*)mmap(NULL, stats_of_file.st_size, PROT_READ, MAP_SHARED, fd, 0);

    close(fd);

    if(mapaddres == MAP_FAILED)
    {
        fprintf(stderr, "ERROR: Cannot mapping file <%s> in RAM\n", file);
        exit(EXIT_FAILURE);
    }

    munmap(buffer, stats_of_file.st_size);

    *mapbytes = stats_of_file.st_size;

    return mapaddres;
}

RMA1** get_samples(char* mapaddres, u_int32_t mapbytes, u_int8_t* n)
{
    RMA1** samples = malloc(sizeof(RMA1*) * (sizeof(RMA1*) / mapbytes));
    u_int16_t offset = 0;
    
    *n = 0;

    while(offset < mapbytes)
    {
        samples[*n] = malloc(sizeof(RMA1*));
        samples[(*n)++] = (RMA1*)(mapaddres + offset);
        offset = (*n) * sizeof(RMA1);
    }

    return samples;
}