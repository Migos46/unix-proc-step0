# README 
This project aims to initialized the user with UNIX processes. It implements the basic tool for synchronising processess using `fork()` and `wait()` functions. The program takes 2 inputs from the user:  

- `numIterarions`: how many times the user wants the process to increment a variable  
- `numProcessess`: how many processess the user wants to do the incrementation  

## Environment  
- `language`: c
- `compiler`: gcc or similar
- if you are in linux -> `build-essentials` package from apt [`$ apt install build-essentials`]
- `build system`: cmake 
## Execution
```sh
# At the README.md file directory 
# Create build directory and change directory to it
$ mkdir build && cd build 
# cmake configurations and files generation  
/build $ cmake ../   
# Compile and link the program `.` after `--build` means current directory
/build $ cmake --build . --clean-first
# Run the program 
/build $ ./p7 5 10
``` 