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
    <img src="./pics/Build Process.jpg">
</div>

- Once you compile a project, the executable only work on the architecture you compiled at for. It cannot be run on other systems.

- Native compilation is when you compile your build for the same system you intend to run the executable on.

- Cross compilation is when you compile an executable on one system and it is intended to run on another. 

- <code style="color:red">GCC = GNU's Compiler Collection</code>
    > Contains many tools (compiler, assembler, linker, etc)

- <code style="color:red">GNU Make</code>
    > Tool that contorls the generation of executables and other non-source files of a program from the program's source files.


