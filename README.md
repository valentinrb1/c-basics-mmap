# C Language Practices in GNU/Linux

## Date - 2022

This repository addresses the task of memory mapping in the context of a C language program running on GNU/Linux. The main objective is to access data in a binary file called `data`, coming from the RMA1 weather radar at Ciudad Universitaria (UNC). The program is expected to perform memory mapping, cast the data according to the structure provided, and solve some incremental activities.

### Authors:
- **Robledo, Valentín**

## Project Structure

The project is organized as follows:

- **inc/Lab6.h:** Header containing the RMA1 data structure and function declarations.
- **src/Lab6.c:** Source file that implements the functions to load the file and obtain samples.
- **main.c:** Main program that uses the functions implemented in Lab6.c.
- **Makefile:** File to compile and build the project.

## Compiling and Running

To compile the project, the following command can be used:

```bash
make
```

This command will generate the executable "lab6". The program can then be run with:

```bash
./lab6
```

## How the Program Works

The program performs the following actions:

1. Loads the binary file "data" using the `load_rawdata` function.
2. Obtains the samples using the `get_samples` function, which maps the file and returns an array of RMA1 structures.
3. Calculates the total number of samples and the mean of the variable `validSamples`.
4. Prints the results to the console.

## Additional Quizzes

### 1. What is the importance of memory mapping in this context?

Memory mapping is crucial in this context because it allows us to directly access the data stored in the binary file without having to read it explicitly. By mapping the file in memory, a correspondence is created between the program's memory and the file on disk. This facilitates efficient manipulation of large data sets and improves performance by avoiding multiple reads of the file.

### 2. How is the release of used memory handled?

Memory release is performed at the end of the program. Samples obtained using the `free(samples)` function are released. In addition, the `munmap` function is used to release the memory allocated to the file mapping.

## Conclusions

Using memory mapping provides an efficient way to access and manipulate data stored in files. The structure of the program makes it easy to understand and modify the code, and the organization in modules improves maintainability. Compiling with specific flags and the absence of errors and warnings guarantee the robustness of the code.
