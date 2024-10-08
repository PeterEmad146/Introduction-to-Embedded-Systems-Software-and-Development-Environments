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

### <code style="color:cyan">Makefiles</code>

- One or more files used to tell make how to build a particular project.
    > makefile, Makefile, sources.mk, includes.mk, ...

- Makefiles have build targets or build rules
    > $make all <br> $make clean <br> $make main.out <br> $make main.o

- Targets can have dependencies or prerequisites
    > main.out: main.o my_file.o <br>

        gcc -g -Wl, -Map=main.map -o main.out main.o my_file.o

- A build rule requires a specific syntax of target, :, prerequisites, and commands

- These are recipes for how to build a particular executable or non-source file.

- A recipe can only be executed if the dependencies are met

<img src="./pics/Makefile Rule.jpg" alt="Makefile Rule Illustration">

- Makefile Syntax
    * Comments start with a <code style="color:red">#</code>
    * Can include other makefiles
    * Line continuation is done with a <code style="color:red"> \ </code>
    * Can create and use variables
    * Command lines start with a tab
    * Targets can depend on other targets

- Variables can be set to strings of text and can include other variables.
    - Variables access is done with the $(variable-name) syntax

- Recursively Expanded Variables (=) get data signed to and substituted into a statement whenever the variable is referenced.

    Example Recursively Expanded Varibales

    > CSTD=c89 

    > CPU=cortex-m0plus 
    
    > CC=arm-none-eabi-gcc

- Simply expanded variables get data signed only once at the time of definition. These can be useful for gathering some information about the current system you are compiling on, perhaps to make your makefile dynamic in selecting native versus cross compiler applications. <br>

    Example Simply Expanded Variables

    > ARCH := $(shell arch)

    > CWD := $(shell pwd) 

    > OS := $(shell uname) 

- Use variables for things like 
    * Compiler flags -> CFLAGS
    * Linker flags -> LDFLAGS

    C-Flags Example Variables

    > CFLAGS = -g -std= \$ (CSTD) -mcpu= \$ (CPU) -mthumb

- You can create variables that point to your source files and include paths.

- Automatic variables can be used to reduce the amount of typing for a particular rule. They are only useful within a recipe, as they have a scope. <br>

    Automatic Variables

    > \$\< -Prerequisite Name

    > \$@ -Target Rule Name

- Patter Matching (%)
    - Pattern matches a target object rule with an associated source file.
    > %.o: %.c<br>
        > &emsp; &emsp; \& (CC) -C \$@ -o \$\< \$ (CFLAGS)

- Variables implicity used by make
    - <code style="color:blue">CC</code> --> Compiler
    - <code style="color:blue">CPP</code> --> Preprocessor Program
    - <code style="color:blue">AS</code> --> Assembler Program
    - <code style="color:blue">LD</code> --> Linker
    - <code style="color:blue">CFLAGS</code> --> C program Flags
    - <code style="color:blue">CPPFLAGS</code> --> C Preprocessor Flags
    - <code style="color:blue">ASFLAGS</code> --> Flags for Assembler
    - <code style="color:blue">LDFLAGS</code> --> C program Linker Flags
    - <code style="color:blue">LDLIBS</code> --> Extra flags for Libraries

### <code style="color:cyan">Other Useful GNU Bin Tools</code>

- GNU Binary Utilities
    * The Assembler (as)
    * The Linker (ld)
    * Conversion of executables
    * Sizing compiled images
    * Library/Archive creation
    * Symbol Listing
    * Debugging
    * Many more...

<div align=center>

<code style="color:orange">Useful GNU Tools</code>

| Name    | Purpose                                                 | ARM Executable        |
|:-------:|:-------------------------------------------------------:|:---------------------:|
| size    | Lists the section sizes for object and executable files | arm-none-eabi-size    |
| nm      | Lists the symbols from object files                     | arm-none-eabi-nm      |
| objcopy | Copies and translates object files                      | arm-none-eabi-objcopy |
| objdump | Dispalys information from object files                  | arm-none-eabi-objdump |
| readelf | Displays information from elf files                     | arm-none-eabi-readelf |
| gdb     | GNU Project Debugger                                    | gdb                   |

</div>

- GNU Size Utility
    - Use GCC's size to display the sizes of the compiled sections inside your object files and executable file outputs.
    - Gives you an idea of your memory footprint is for your executable.
        - Code Memory
        - Data Memory

- NM Utility
    - The symboly utility allows us to investigate the size of all the possible symbols that are defined in a given executable or object file.
    - Symbols are identifiers in your source code that can be referenced
        - Variables
        - Functions
        - Debug

    > Symbol Descriptions

    > T: Code <br> R: Read Only <br> D: Initialized Data <br> B: Uninitialized Data (BSS) <br>

- Objcopy Utility
    - Convert object files from one format to another
    - Make a copy of an object file

    > Object Format Types

    > Binary <br> srec (Motorola S-record) <br> intel Hex Record (ihex) <br> elf31-littlearm <br> elf32-bigarm <br>

- Objdump utility
    - Dumps information about an object file
        - Section Headers
        - Symbols 
        - Debugging
    - Can take object files and dump assembly from the machine code

- Readelf Utility
    - Displays information about a ELF formatted file
        - Compiled Sections
        - Memory Sections
        - Symbol Tables
        - Architecture Specifics 

    > ELF Files are not human readable they contain lots of hidden information in binary data

### <code style="color:cyan">QUIZ</code>

1) Which Compiler is used for the ARM Cortex M Processors
    - gcc
    - arm-linux-gnueabi-gcc
    - arm-none-eabi-gcc ✔️
    - None of the above

    <code style="color:green">Explanation</code>
    <code style="color:white">The ARM Cortex M processors are embedded systems that use the 'arm-none-eabi-gcc' compiler. This is a cross-compiler specifically designed for ARM Cortex M microcontrollers, producing code for systems without an operating system (bare-metal).</code>

2) When compiling with gcc, the command line parameter -Wl allow options to be passed to the:
    - Preprocessor
    - Assembler
    - Compiler
    - Linker ✔️

    <code style="color:green">Explanation</code>
    <code style="color:white">The -Wl option in GCC is used to pass options to the linker. '-Wl,option' sends 'option' to the linker.</code>

3) In the proprocessing stage of compilation... (Select all that apply)
    - Header files are actually expanded and included in the source code of the program ✔️
    - Macros are replaced by their respective values ✔️
    - All object files are linked together

    <code style="color:green">Explanation</code>
    <code style="color:white">During preprocessing, the compiler expands header files (via #include) and replaces macros with their defined values. Linking occurs later in the compilation process.</code>

4) The assembly code generated depends upon the 
    - Processor architecture ✔️
    - Memory
    - None of the above

    <code style="color:green">Explanation</code>
    <code style="color:white">Assembly code is directly tied to the processor architecture because it uses the specific instruction set of the processor.</code>

5) What kind of targets should have a phony directive in the makefile?
    - A target which is not one of your filenames ✔️
    - Targets that are either an existing filename or not an existing filename
    - The target which is not used for compilation
    - None of the above

    <code style="color:green">Explanation</code>
    <code style="color:white"> .PHONY targets in a Makefile are used for targets that are not files. This prevents confilicts if a file with the same name as the target exists.</code>

6) Select all that apply: A linker file .......
    - Provides details on the memory size and location ✔️
    - Maps compiled sections to physical memory ✔️
    - Resolves dependencies
    - Can check if memory was over allocated ✔️
    - Can provide the Entry point to the program ✔️

    <code style="color:green">Explanation</code>
    <code style="color:white">A linker script provides detailed control over how the program is loaded into memory, including memory allocation and mapping, and defining the entry point.</code>

7) Make can use what feature to ask the OS for compilation information? 
    - Dynamic Variables
    - Shell Functions ✔️
    - Runtime Functions
    - Conditional Functions

    <code style="color:green">Explanation</code>
    <code style="color:white">Make can use shell functions (e.g., \$(shell command)) to run commands and retrieve information from the operating system during the build process.</code>

8) Which of the following is a proper declaration of an include guard?
    - #ifdef__HEADER_H__<br>/* Code here */<br>#endif
    - #ifdef __HEADER_H__<br>#define __HEADER_H__<br>/* Code here */<br>#endif
    - #ifndef HEADER_H<br>#endif<br>/* Code here */
    - #ifndef __HEADER_H__<br>#define __HEADER_H__<br>/* Code here */<br>#endif ✔️

    <code style="color:green">Explanaiton</code>
    <code style="color:white">This is a typical and correct way to define an include guard to prevent multiple inclusions of the same header file.</code>

9) Variables for a makefile can be defined in 
    - Makefile ✔️
    - Command line ✔️
    - In the Linker File

    <code style="color:green">Explanation</code>
    <code style="color:white">Variables in a Makefile can be set within the Makefile itself or passed from the command line using 'make var=value'. They are not defined in the linker file.</code>

10) Cross compiled executables can run on both a host machine and target embedded system
    - True
    - False ✔️

    <code style="color:green">Explanation</code>
    <code style="color:white">Cross-compiled executables are generally intended for the target system, which often has a different architecture than the host machine, so they cannot run on both.</code>

11) Which on of the following provides all prerequisites listed in a makefile target?
    - $^ ✔️
    - $*
    - $:
    - None of the above

    <code style="color:green">Explanation</code>
    <code style="color:white">\$^ is a Makefile automatic variable that represents all the prerequisites of the target.</code>

12) Which gcc option includes debugging info in the generated object code?
    - -g ✔️
    - -c
    - -v
    - None of the above
    
    <code style="color:green">Explanation</code>
    <code style="color:white">The -g option tells GCC to include debugging information in the compiled object code.</code>

13) Make can help generate which of the following files:
    - Map Files ✔️
    - Executable Files ✔️
    - Object Files ✔️
    - Linker Files

    <code style="color:green">Explanation</code>
    <code style="color:white">Make is primarily used to automate the build process, generating object files, executable files, and can generate map files as part of the linking process.</code>

14) The -shared option of gcc generates a share _________ for share library.
    - Object file ✔️
    - Preprocessed file
    - Source file
    - Header file

    <code style="color:green">Explanation</code>
    <code style="color:white">The -shared option creates a shared object file (.so), which can be used as a share library.</code>

15) The correct sequence of the GCC compilation process is
    - Preprocessing -> Compiling -> Linking -> Assembling ✔️
    - Assemble -> Preprocessing -> Compilation -> Linking
    - Preprocessing -> Compiling -> Linking -> Locating
    - Locating -> Preprocessing -> Make -> Compilation -> Linking

    <code style="color:green">Explanation</code>
    <code style="color:white">The correct sequence is preprocessing (expanding macros and includes), compiling (converting source code to assembly), assembling (converting assembly to machine code), and linking (linking object files together).</code>

16) What utility allows you to produce assembly code from a given object file?
    - Objcopy
    - Ld
    - As
    - Objdump ✔️

    <code style="color:green">Explanation</code>
    <code style="color:white">Objdump is a utility that can disassemble an object file, showing the assembly code</code>

17) Which compilation setup makes sure that all the undefined symbols in the code are resolved?
    - Linking ✔️
    - Compiling
    - Preprocessing
    - None of the above

    <code style="color:green">Explanation</code>
    <code style="color:white">During linking, the linker resolves all undefined symbols by matching them with defined symbols from other object files or libraries</code>

18) If a program is linked against a static library then 
    - Machine code of the used function is copied in the executable ✔️
    - Used function definition is copied into the preprocessed code
    - Used function definition is provided at the time of compiling
    - None of the above

    <code style="color:green">Explanation</code>
    <code style="color:white">When linking against a static library, the linker copies the machine code for the used functions directly into the final executable.</code>

19) What architecture specific flags will need to be used for our ARM cross compiler? (Select all that apply)
    - -mthumb ✔️
    - -mcpu=cortex-m4 ✔️
    - --specs=nosys.specs ✔️
    - -compiler=arm-none-eabi-gcc
    - -std=c89

    <code style="color:green">Explanation</code>
    <code style="color:white">These flags are specific to ARM Cortex-M microcontrollers. -mthumb enables the Thumb instruction set, -mcpu=cortex-m4 targets the Cortex-M4 processor, and --specs=nosys.specs tells the compiler not to link against system libraries.</code>

20) A processor Executes what kind of code?
    - Assembly code
    - Machine code ✔️
    - C Code
    - Morse Code

    <code style="color:green">Explanation</code>
    <code style="color:white">The processor directly executes machine code, which is the binary representation of insturctions.</code>

21) A compile time switch can help:
    - Make code portable
    - Change the target files
    - Link differnt files
    - Change target architecture
    - All of the above ✔️

    <code style="color:green">Explanation</code>
    <code style="color:white">Compile-time switches can make code portable, change target files, link different files, and change the target architecture, among other things.</code>