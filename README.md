# Optimizing-Performance
Comparing speed of algorithms, data structures, CPU and GPU.

## Table of Contents

- [Introduction](#introduction)
- [Performance Comparison](#performance-comparison)
- [Requirements](#requirements)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

This Project Demonstrates how Parallelization of different data structures and  Algorithms can affect a program. By the end of this, you will be  able to understand the basics of threads and  will know where and where not to implement it. I have implemented data  structures and algorithms to clearly distinguish performance. All Codes have been timed and the effects of parallelism can clearly be seen.
Parallelism might be strong but comes with some problems. The code becomes complex. There is an overhead  in launching every thread and in some cases it  might just be better to just use a single thread. While writing parallel code, we have to keep memory safety and thread synchronization in mind. While there are some problems that come with writing multithreaded code, it can significantly increase the speed of your code,  if  used correctly. Parallelization can be achieved using a CPU  and GPU with multiple cores. In this project I have used the CPU:‘Intel 12th Gen Intel(R) Core(TM) i7-12700H’ and 
GPU:‘NVIDIA GeForce RTX 3050 Laptop GPU’. The programming languages used are: C, C++ and CUDA.

## Performance Comparison

The performance comparison section presents benchmark results of the CPU and GPU implementations. It measures the execution time for all approaches and demonstrates the potential speedups.

## Requirements

To run this project, you need the following:

-A CPU with at least 4 cores available for multithreading.
- A compatible NVIDIA GPU with CUDA support.
- NVIDIA CUDA Toolkit installed on your system.
- C++ compiler with CUDA support (e.g., NVCC).

## Usage

For Windows users:
1. Clone the repository.
2. Open CMD/Powershell at the file location.
3. Run:
   ```pip install -r requirements.txt```
5. Run:
   ```.\project_runner_cli.bat```

   If the codes do not run, delete the exe files and recompile the codes accordinglly.

For Linux/MacOS
You will have to recompile all the codes since the output is in .exe format. You wont be able to run the .bat file, so you will have to run all the codes individually.

For the merge sort multi threaded code I have used ```#include <windows.h>``` and ```#include <process.h>``` libraries which is only available for Windows. You will have to modify the code using the ```#include <pthread.h>``` library

## Contributing

Contributions to this project are welcome. If you find any issues or have improvements to suggest, feel free to open an issue or create a pull request.




