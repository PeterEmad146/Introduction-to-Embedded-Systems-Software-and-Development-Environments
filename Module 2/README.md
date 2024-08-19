# Module 2
## Compilation with GCC and GNU Make

### <code style="color:cyan">Introduction to Build Systems using GNU Toolsets</code>

- In our Embedded System Development Platform, Build system is contained on the host machine. 

- The main job of the compiler toolset is to translate a high-level language into architecture specific language.

- The architecture specific language we need to translate our C-Program into is called <code style ="color:red">assembly</code>.

- The assembly is translated into machine code, which is binary encoding of assembly insturctions.

- This machine code is what the processor understands and uses to perform work.

- Build and Install Process:
    * Preprocessing
    > The preprocessor will take your source files Cs and Hs and transform into new files by evaluating preprocessor directives and performing macro substitution.

    > These modified files are then fed into the comiler proper. This performs a C programming to assembly code translation.

    * Assembling 
    > The assembler converts our assembly code into object code. 

    * Compiling
    > Object files need to be combined into a single executable where all references between object files need to be combined into a references symbols.

    * Linking 
    > The Linker provides the linked file to a relocator which will map all the addresses of code and data into the processor's memory space.

    * Locating 
    * Installing
    > Installation will require other tools

<div align=center>
    <img src="./pics/Build Process.jpg" alt="Build Process Illustration">
</div>

- Once you compile a project, the executable only work on the architecture you compiled at for. It cannot be run on other systems.

- Native compilation is when you compile your build for the same system you intend to run the executable on.

- Cross compilation is when you compile an executable on one system and it is intended to run on another. 

- <code style="color:red">GCC = GNU's Compiler Collection</code>
    > Contains many tools (compiler, assembler, linker, etc)

    > GCC is a toolchain that compiles code, links it with any library dependencies, converts that code to assembly, and the prepares executable files. It follows the standard UNIX design philosophy of using simple tools that perform individual tasks well. 

    > When you run GCC on a source code file, it first uses a preprocessor to include header files and discard comments. Next, it tokenizes the code, expands macros, detects any compile-time issues, then prepares it for compilation. It is then sent to the compiler, which creates syntax trees of the program's objects and control flow and uses those to generate assembly code. The assembler then converts this code into the binary executable format of the system. Finally, the linker includes references to any external libraries as needed. The finished product is then executable on the target system.

- <code style="color:red">GNU Make</code>
    > Tool that contorls the generation of executables and other non-source files of a program from the program's source files.


### <code style="color:cyan">Compiling and Invoking GCC</code>

- Compilation is the process of converting high level software language to architecture specific binary encoded operations. 

- .i files is the file extension used for files outputs from preprocessing.

- Compilers:
    * Native Compiler: <code style = "color:red">gcc -> gcc-4.8</code>
    > For Code run on the host machine.

    * Cross Compiler: <code style="color:red">arm-none-eabi-gcc</code>
    > For code run on the target processor.

- Build Files:
    * Assembly Files --> .s Extension
    * Object Files --> .o Extension
    * Library Files --> .a Extension (with .h)
    * Executable Files --> Extension Varies

- C code gets inverted into architecture specific assembly. This conversion is a decomposition of C operations into numerous assembly operations.

- The assembler can be found of as a compiler as it converts assembly language into binary coded operations.

- GCC commands will have the following form: <code style="color:red">$ gcc [OPTIONS] [FILE]</code>.

<div align=center>
<h3><code style="color:orange">General Compiler Flags</code></h3>

| Option & Format          | Purpose                                              |
|:------------------------:|:----------------------------------------------------:|
| -c                       | Compile and Assemble File, Do Not Link               |
| -o FILE                  | Compile, Assemble, and Link to OUTPUT_FILE           |
| -g                       | Generate Debugging Information in Executable         |
| -Wall                    | Enable All Warning Messages                          |
| -Werror                  | Treat All Warnings as Errors                         |
| -I FILE                  | Include this <DIR> to Look for Header Files          |
| -ansi <br> -std=STANDARD | Specify which standard Version to Use (ex: c89, c99) |
| -v                       | Verbose Output from GCC                              |

</div>

<div align=center>
<h3><code style="color:orange">Architecture Specific Compiler Flags</code></h3>


| Option & Format   | Purpose                                                             |
|:-----------------:|:-------------------------------------------------------------------:|
| -mcpu=NAME        | Specifies Target ARM Processor and Architecture (ex: cortex-m0plus) |
| -march=NAME       | Target ARM Architecture (ex: armv7-m, thumb)                        |
| -mtune=NAME       | Target ARM Processor (ex: cortex-m0plus)                            |
| -mthumb           | Generate code in Thumb States (ISA)                                 |
| -marm             | Generate code in ARM State  (ISA)                                   |
| -mthumb-interwork | Generate code that supports calling between ARM and Thumb (ISA)     |
| -mlittle-endian   | Generate code for Little Endian Mode                                |
| -mbig-endian      | Generate code for Big Endian Mode                                   |

</div>

### <code style="color:cyan">Preprocessor Directives</code>

- The preprocessor provides a special keywords called preprocessor directives. The directives begin with a number sign(#) and have many functions.

- They can be used to define constants or features, as well as define macro functions. 

- Macro is a term often used interchangeably with the application of a preprocessor directive. 

- Preprocessor directives consist of the following:
    * <code style="color:red">Macro definition directives</code> which replace tokens in the current file wiht specified replacement tokens.
    * <code style="color:red">File inclusion directives</code> which imbed files within the current file.
    * <code style="color:red">Conditional Compilation directives</code> which conditinally compile sections of the current file.
    * <code style="color:red">Message generation directives</code> which control the generation of diagnostic messages
    * <code style="color:red">The null directive (#)</code> which performs not action
    * <code style="color:red">Pragma directives</code> which apply compiler-specific rules to specified sections of code
    * <code style="color:red">C99 preprocessor features adopted in C++11</code>

- Coniditonal Compilation can also be performed with the compiler suing the <code style="color:red">#if</code> or <code style="color:red">#else</code> directives.

- Important Directives
    * #define, #undef
    > #define MACRO-NAME (MACRO-VALUE)

    > #define MACRO-FUNCTION(PARMS) (OPERATION)
    * #ifndef, #ifdef, #endif
    * #include
    > #include header-name <br>
    > instructs the preprocessor to paste the text of the given file into the current file.
    * #warning, #error
    * #pragma
    > Gives a specific instruction to the compiler (controls compilation from software instead of command line)

    > Unrecognized pragmas will be ignored.

### <code style="color:cyan">Creating Header and Implementation Files</code>

- Libraries: Collection of software (precompiled or direct source)

- Modules: Software Organization that each module has encapsulated certain functionality within a library

- Each module will contains two files. 

- The first is an implementation file or the c file, the source file. This contains functions definitions and other c code.

- The other file is a header file. This contains function declarations, macros, and even certain derived data type definitions, like enumerations or structures.

<div align=center>
    <img src="./pics/Creating Modules.jpg" alt="Creating Modules Illustration">
</div>

- <code style="color:red">#pragma once</code> directive is a nonstandard directive, that only certain compilers support. This features alows us to use only a single line to create an include guard. However, because of the limited support, using only this option would not make your code portable to other compilers or compiler versions.

- Compiled Libraries
    * Static Libraries: Directly linked into your output executable
        * Installed with the program image as part of the executable
        * Create using archiver

    * Shared Libraries: Linked dynamically at runtime with your executable
        * Pre-installed onto target
        * Used for applications with an operating system
        * Create with shared flag

### <code style="color:cyan">Linkers</code>

- The last two steps of the build process, linking and locating, are typically combined into one stage. 
    * The linker combines compiled object files into a single object file or executable.
    * The locator maps the object into specific address locations, creating an executable program for the embedded processor.

- The traditional linear build model is not typical for software projects due to the involvement of multiple input files.
    * The process usually involves various sources like different types of source files, libraries, and linker files.

- Assembly and C files are compiled into objects within the same project, and compiled library code is pulled in during the linking stage.
    * A linker file is also input into the linking and locating stage, instructing the locator on how to map the executable into proper addresses using the <code style="color:red">-T</code> flag.

- The linker's primary responsiblity is to combine all compiled object files into a single executable.
    * This process is handled directly by the LD application or indirectly by GCC.
    * Each object file contains different memeory segments, such as code memory and data memory, which need to be merged, mapped, and assigned addresses.

- Symbols used across multiple files or modules need to be properly mapped so that the location of the symbol's address is assigned correctly.
    * If a symbol isn't properly declared or included, the linker will search through object sources and library paths to resolve it, throwing an error if unresolved.

- Static libraries are directly linked at linking time using the <code style="color:red">-l</code> flag, while dynamic libraries reference paths already installed on the device. 
    * In embedded systems, dynamically linking at runtime cna save code space since libraries are often pre-installed on the device.

- Startup routines, usually defined in C standard libraries, are included as static libraries in the build.
    * If the linker is invoked directly, these libraries must be incuded manually.
    * The <code style="color:red">-nostdlib</code> flag can stop linking startup routines and libraries, but this requires manual definition of initialization and exit routines.

- The final output of the linking process is a relocatable file containing multiple segments of code blocks.
    * This file needs to be mapped into the architecture's memory regions, with the linker file providing instructions for memory relocation, including segment names, memory sizes, and access permissions. 

- During program installation, the executable is split into various physical memory regions, such as code, initialization data, stack, and heap.
    * The linker must specify the start location and length of each memory segment.
    * Linker scripts can include checks to ensure memory regions are not overllocated, preventing issues like stack and heap overflow.

- Data memory is typically set as read and write (RW), while code memory is set as read and execute (RX) to prevent accidental overwriting and enhance security.
    * Some processors enforce security by causing a fatal error if code is executed from the data memroy region instead of code memory.

- A linker file example shows how physical memroy spaces are mapped, with code memory placed in flash and data memory in SRAM.
    * After linking and locating, a map file can be generated to provide detailed information on memory allocation, including specific addresses.

- Several linker flags, such as <code style="color:red">-o</code> for code optimization and <code style="color:red">-Wl</code> or <code style="color:red">-Xlinker</code> for passing flags through GCC, provide additional control during the linking process.
    * The output executable file format varies depending on the installer and architecture, with common formats including Intel Hex, ELF, and ARM Image Format.

- Linking is a complex process that involves managing various input files, including object files, library files, and linker files.
    * Expertise in architecture is necessary for defining memory regions, making embedded software engineers crucial in both designing code and ensuring it fits into the memory space. 

<div align=center>
<h3><code style="color:orange">Linker Flags</code></h3>

| Option & Format   | Purpose                                                      |
|:-----------------:|:------------------------------------------------------------:|
| -map NAME         | Outputs a memory map file NAME from the result of linking    |
| -T NAME           | Specifies a linker script name NAME                          |
| -o NAME           | Place the output in the filename NAME                        |
| -O                | The level of optimizations from [#=0-3] (-O0, -O1, -O2, -O3) |
| -Os               | Optimize for memory size                                     |
| -z stacksize=SIZE | The amout of stack space to reserve                          |
| -shared           | Produce a share library (dynamic linking library)            |
| -l LIB            | Link with library                                            |
| -L DIR            | Include the following library path                           |
| -Wl, OPTION       | Pass option to linker from compiler                          |
| -Xlinker OPTION   | Pass option to linker from compiler                          |

</div>

### <code style="color:cyan">Make</code>

- Building Manually can be tedious
    * Many GCC flags
    * Many independent commands
    * Many build targets
    * Many supported architectures
    * Many source files
        > ex: The Linux Kernel. This software repository contains over 40,000 software files involved in the build process.<br>
    * Cause consistency issues
    * Waste development time

- There are tools that help simplify both command line and IDE building with the help of build automation using make.

- Build Management Software (or Build Automation) provides a simple and consistent method for producing a target executable.

- The Build Management Software automated the process of 
    * Preprocessing
    * Assembling
    * Compiling
    * Linking
    * Relocating

- Make is yet another free tool we get from the GNU tool chain that is utilized from the command line in the exact same way as GCC.

- It lives in the executable program binaries folder on Linux and has many options just like GCC did.

- One big difference is that it is not part of the GCC tool chain as it is independent of the Compiler or the architecture you're using.
    > Therefore there is no arm-none-eabi prefix to the command

<div align=center>

| Name      | Symbol | ARM Executable                      |
|:---------:|:------:|:-----------------------------------:|
| Assembler | as     | arm-none-eabi-as                    |
| Compiler  | gcc    | arm-none-eabi-gcc                   |
| Linker    | ld     | arm-none-eabi-ld                    |
| Make      | make   | <code style="color:red">make</code> |

</div>

- GNU Make
    > Tool that controls the generation of executables and other non-source files of a program from the program's source files.

- Makefile
    > Provides special directions and procedures to make in order to create an executable file from a multitude of input files.

- Makefiles have build targets or build rules
    > These are recipes for how to build a particular executable or non-source file.

- Executables can have dependencies:
    * Requirements needed for a particular recipe
    * These can be auto-generated from make

<img src="./pics/GNU Toolchain.jpg" alt="GNU Toolchain">

 <code style="color:violet">How does the command-line Make system differ from what we did with our IDE?</code>
 
 - IDE is going to auto-generate their Makefiles depending on how you configured your software project.
    > Meaning it will generate all of the specific flags and linker files for the guards to you architecture.

    > This is very bad for maintainability and portability, as most software teams build their own make system, and version control, so they have a method of controlling when a portable, consistent build system, that can work over a variety of architectures of their own design.

