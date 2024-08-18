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
    <img src="./pics/General Compiler Flags.jpg" alt="General Compiler Flags Illustration">
</div>

<div align=center>
    <img src="./pics/Architecture Specific Compiler Flags.jpg" alt="Architecture Specific Compiler Flags Illustration.">
</div>

### <code style="color:cyan">Preprocessor Directives</code>

- The preprocessor provides a special keywords called preprocessor directives. The directives begin with a number sign(#) and have many functions.

- They can be used to define constants or features, as well as define macro functions. 

- Macro is a term often used interchangeably with the application of a preprocessor directive. 

- These directives are represented with the <code style="color:red">#def</code> or the <code style="color:red">#undef</code> keywords.

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
    <img src="./pics/Linker Flags.jpg" alt="Linker Flags Illustration">
</div>

### <code style="color:cyan">Make</code>

- Building a software target typically involves using numerous tools for building, testing, versioning, and developing code. 
    * Managing these tools can be tedious, espcially for large projects with many engineers. Simplifying the process can help maintaining consistency.

- Software companies often support multiple build targets and architectures, complicating the build process. 
    * Managing a large number of source files and build commands becomes impractical for large teams or projects, leading to potential human error and inconsistent builds.

- An example like the Linux Kernel, with over 40,000 software files, illustrates the scalability issues of iterative file-by-file builds.
    * Manual build processes are less feasible for large projects, necessitating a more automated approach.

- Integrated Development Environments (IDEs) run similar compile commands behind the scens for each source file, each with numerous flags.
    - These commands can be complex, highlighting the need for a more manageable solution. 

- Build automation tools like <code style="color:red">make</code> can simplify the command-line and IDE building processes.
    - <code style="color:red">Make</code> helps automate and manage the build process, reducing the need to memorize numerous commands and flags.

- Build management software provides a consistent mechanism to control and build executable images.
    * Terms like build management, build generation, and build automation refer to the processes and tools used to streamline bulding software.

- GNU Make is a free tool from the GNU toolchain used from the command line to manage builds.
    * It functions independently of the compiler or architecture, making it versatile for various build environments.

- GNU Make controls the generation of executables and non-source files from source files.
    - It can generate dependencies, statistical information, and more, providing a consistent and efficient build process.

- Makefiles are used to define specific recipes and procedures for building targets.
    - Each Makefile contains instructions for generating particular outputs from input files, and can auto-generate dependency files.

- Target in a Makefile can be built using simple commands, allowing automation similar to scripting.
    - Common targets include bulding objects, complete builds, and cleaning up generated files.

- Make can be configured to use various compiler toolchains, including vendor-specific or GCC.
    - It supports multiple compiler versions and toolchains, making it flexible for different bulid requirements.

- Comparing command-line Make with IDEs revelas the IDEs auto-generate Makefiles based on project configuration.
    * Custom Makefiles offer better maintainability and portability compared to IDE-generated ones, which are often less flexible.

- Example usage of Make includes creating a main Makefile and additional files to manage targets and build options.
    - Running commands like <code style="color:red">make all</code> performs a complete build, <code style="color:red"> make clean</code> removes generated files, and specific targets can be build individually.

- Build systems are crucial for software teams to avoid tedious and error-prone build processes. 
    - While there are various build generation systems, Make remains widely used due to its effectiveness in managing complex builds.

- Build systems provide abstraction from the target software and architecture, supporting portability and version contorl.
    - They ensure consistent builds over time and maintain information about build configurations.

