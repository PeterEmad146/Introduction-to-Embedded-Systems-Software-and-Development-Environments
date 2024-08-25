# Module 2 Assessment

## Deliverables and Instructions

You will write a makefile that can compile multiple source files and support two platform targets. You will be given a folder structure and a set of source files. Download the starter files from github git clone the assessment repo from github:

> cd ~ <br>
> git clone https://github.com/afosdick/ese-coursera-course1.git <br>

In the assessments/c2 folder you will see 2 directories and a file.

- <code style="color:green">msp432p401r.lds</code> --> The Linker file you are to use for linking

**'src' folder**: contains five source files (*.c)

- <code style="color:green">Makefile</code> --> The Makefile you are to edit for the assignment<br><code style="color:green">sources.mk</code> --> The source file you are to edit for the assignment

- <code style="color:green">main.c</code> --> Main file you are to work with

- <code style="color:green">memory.c</code> --> File that interacts with the memory through an IO abstraction interface.

- <code style="color:green">interrupts_msp432p401r_gcc.c</code> MSP432 specific C-file for interrupts

- <code style="color:green">startup_msp432p401r_gcc.c</code> --> MSP432 specific C-file for startup

- <code style="color:green">system_msp432p401r.c</code> --> MSP432 specific C-file for system information

**'include' folder**: contains the three directories of supporting header files

- <code style="color:green">common</code> --> Contains common headers for both platform targets

- <code style="color:green">msp432</code> --> Contains MSP432 platform headers

- <code style="color:green">CMSIS</code> --> Contains ARM architecture specific headers

Inside the **common** folder, you have been provided a memory.h and a platform.h file. The platform.h file gives you an interface to printf using the macro PRINTF as a mechanism to reduce dependencies on the stdio.library.

**Platforms and Flag Support Guidelines**

You need to support two target platforms and their own specific compilers. These two platforms are the HOST and the MSP432. The host embedded system will use the native compiler, __gcc__. The target embedded system will use the cross compiler, **arm-none-eabi-gcc**. The **PLATFORM** keyword provided in the Makefile should be used to conditionally assign the appropriate compiler flags, linker flags, and architecture flags. The target platform must be provided at the command line with the make command to set the platform you are compiling for. 

Example:
> make build PLATFORM=MSP432<br>make build PLATFORM=HOST

Upon completion of a build, you should provide a build report of code size using the gcc **size** tool. Note, you will need to select the right GCC Toolchain Size application. The output executable that gets built needs to be called **c1m2.out**. This needs to be executed using dot-slash notation.

> ./c1m2.out

The Makefile and sources.mk files have already been populated with a few makefile variables that you will need to define at a miniumu. Those are listed below:

- <code style="color:green">CC</code> --> Compiler that will perform the build (Native or Cross)
- <code style="color:green">CFLAGS</code> --> C-programming flags for gcc
- <code style="color:green">CPPFLAGS</code> --> C-Preprocessor Flags
- <code style="color:green">LDFLAGS</code> --> Linker Flags
- <code style="color:green">PLATFORM</code> --> The target platform you are compiling for (Platform Specific)
- <code style="color:green">SOURCES</code> --> The list of sources files that will need to be compiled (Platform specific)
- <code style="color:green">INCLUDES</code> --> The list of include directories (Hint: Use the -l flag)

You will need to generate a handful of files for each complete build. These are:

- <code style="color:green">c1m2.map</code> --> Map file for the full build (Use the -Map= \<FILE> option)
- <code style="color:green">*.d</code> --> Dependency Files for each source file (main.dep, memory.dep, etc) (Use the -M* options [MP, MF, MD, MM, etc])
- <code style="color:green">*.o</code> --> Individual object files (main.o, memory.o, etc)
- <code style="color:green">c1m2.out</code> --> Output Executable file

For building will need to support a variety of flags. These will include general, platform and architecture specific flags. Those are listed below: 

- General Flags (Both Platforms)
    - -Wall
    - -Werror
    - -g
    - -O0 
    - -std=c99

- Platform Specific Flags (MSP432/HOST)
    - <code style="color:green">Linker File (MSP432)</code> --> -T msp432p401r.lds
    - <code style="color:green">Platform Target (Both)</code> --> -DMSP432 or -DHOST

- Architecture Specific Flags (ARM ONLY)
    - -mcpu=cortex-m4
    - -mthumb
    - -march=armv7e-m
    - -mfloat-abi=hard
    - -mfpu=fpv4-sp-d16
    - --specs=nosys.specs

You may NOT use wildcard searches for finding source files. You must directly define the files you wish to compile and the directories you wish to include based on the platform. To do this, you will need to define the sources and include list differently based on the target platform. Use a conditional check to switch between these. An example below provides a hint on how to do this:

> ifeq (\$(PLATFORM),HOST)<br>
> &emsp;&emsp;CC = \<Add the appropriate compiler\> <br>
> &emsp;&emsp;# etc <br>
> else <br>
> &emsp;&emsp;CC = \<Add the appropriate compiler\> <br>
> &emsp;&emsp;# etc <br>
> endif

**Build Target Guidelines**

You need to support a number of build rules and target files. Any rule with a prerequisite list must have only dependent files and dependent targets listed. For any prerequisite that is in another build target prerequisite list, that target dependency needs to execute those rules before running the initially provided target. Finally, you do NOT need to go from source file to preprocessor file to assembly file to object file to relocatable file to executable file for this build. You can have build rules that directly compile a file. 

Below are the targets which need to be supported in the makefile:

**%.i**

- Generate the preprocessed output of all c-program implementation files (use the -E flag).
- You can do this by providing a single target name: 

Example:
> \$ make main.i

**%.asm**

- Generate assembly output of c-program implementation files and the final output executable (Use the -S flag and the objdump utility).
- You can do this by providing a single target name.

Example:
> \$ make main.asm

**%.o**

- Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.

Example:
> \$ make main.o

**compile-all**

- Compile all object files, but DO NOT link.
- Needs to have .PHONY protection.

Example:
> \$ make compile-all

**Build**

- Compile all object files and link into a final executable.
- Needs to have .PHONY protection.

Example:
> \$ make build

**Clean**

- This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
- Needs to have .PHONY protection.
- This includes but is not limited to .map, .out, .o, .asm, .i etc. 

Example:
> \$ make clean


## Testing Your System

You can  intermittently test your build system targets as you write them. A few examples are listed as follows:

Example 1: 
> \$ make memory.o PLATFORM=MSP432

Example 2:
> \$ make build PLATFORM=HOST

Example 3:
> \$ make main.asm PLATFORM=HOST

Example 4:
> \$ make memory.i PLATFORM=HOST

Each of these build commands will produce one or more output files. You then use linux's ls command to list the current files in the directory. This should show the generated file. You then should be able to clean those files with the make clean command. RUnning the ls command once more, should show that these files have been removed. 

Example:
> \$ ls -la
> \$ make clean
> \$ ls -la

Finally, the host code should be able to run natively on your system. You can test that this file works properly by running ./c1m2.out. The cortex build will not be able to run natively. This should throw an error if you try to run natively. The native target execution should output a string "aXy72_L+R"

<div align=center>
&copy; University of Colorado Boulder
</div>