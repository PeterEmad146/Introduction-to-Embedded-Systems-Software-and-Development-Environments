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

    