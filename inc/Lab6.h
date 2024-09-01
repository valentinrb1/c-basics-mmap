/**
 * @file lab6.h
 * @author Robledo, Valentín
 * @brief Header containing the RMA1 data structure and function declarations.
 * @version 1.0
 * @date Noviembre de 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __LAB6_H__
#define __LAB6_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

typedef u_int8_t boolean;
enum {false, true};

typedef struct Lab6
{
    u_int16_t   version;
    u_int16_t   drxVersion;
    u_int8_t    reserved_1[4];
    double      initCW;
    float       azimuth;
    float       elevation;
    u_int16_t   idVolumen;
    u_int16_t   idBarrido;
    u_int16_t   idConjunto;
    u_int16_t   idGrupo;
    u_int16_t   idPulso;
    boolean     iniBarrido;
    boolean     finBarrido;
    boolean     finGrupo;
    boolean     inhibido;
    u_int16_t   validSamples;
    u_int16_t   nroAdquisicion;
    u_int8_t    reserved_2[2];
    u_int32_t   nroSecuencia;
    u_int64_t   readTime_high;
    u_int64_t   readTime_low;
    u_int8_t    reserved_3[64];
} RMA1;

char* load_data(char* file, u_int32_t* mapbytes);
RMA1** get_samples(char* mapaddres, u_int32_t mapbytes, u_int8_t* n);

#endif