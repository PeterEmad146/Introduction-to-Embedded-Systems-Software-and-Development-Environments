# Module 1
## Embedded System Development Components

### Introduction to Embedded Systems

- Software Requirements
    * IDE: Code Composer Studio (CCS) 
    * Serial Terminal Emulator: RealTerm
    * VirtualBox: Virtual Machine Hypervisor
    * Linux Distribution: Ubuntu Latest LTS

- An Embedded System is a computerized system that is purpose built for its application.

- Each embedded systems has a special purpose and contraints in their system resources such as processing memory, and peripherals.

- The hardware is a combination of a processing core, and external circuits for the processor to interact with.

- Target embedded systems usually use Printed Circuit Board (PCB) technology for hardware implementation. A PCB is a substrate with conductive wires. It interconnects many integrated circuits and passive elements that all have been soldered onto the board.

- An external programmer is connected to the embedded systems processor, in order to install a target application into the internal memory. 

- A host machine is responsible for developing and compiling and coordinate the install which is equally as important  as the development of the system PCB itself.

- One solution for the processing core would be a microcontroller. Microprocessors and microcontrollers are not the same!

- **Microcontroller:** is a microprocessor with added functionality such as memory peripheral hardware.

- The processor part of the microcontroller is called the Centeral Processing Unit (CPU).

- **CPU:** a piece of hardware that runs our software by fetching and executing assembling  instructions for memory.

- CPU contains:
    * Registers
    > a type of computer memory built directly into the CPU that is used to store and manipulate data during the execution of insturctions.

    * Arithmetic Logic Unit (ALU)
    > a digital circuit used to perform arithmetic and logic operations.

    * Interrupt Controller 
    > a component that gathers hardware interrupts events from various sources and presents them to processor

    * Debug

- The CPU and its subsystems interact with other mircocontroller resources through one or more buses.
- A bus controller aids the processor in this data transmission between memory and peripherals.

- Memory holds data that we operate on as well as the program that we're executing. This data is stored in a combination of flash and Random Access Memory (RAM). 

- A clock system provides synchornization across all these components.

- Peripherals that may be included:
    * Communication
    * Analog signal processing
    * Input/Output
    * Timing
    * Processor support 

### Embedded Software Engineering

- It's good to start by breaking a software concept down into flow diagrams or software blocks.

- A Flow diagram can depict how a particular software or algorithm should behave. It contains the software constructus such as Conditional Decisions and high level function calls.

- Software Block Diagram did not differ greatly from a hardware block diagram, it depict how different blocks of code communicate. 

- A software block diagram can also depict a software system in layers.

- Software that directly interacts with hardware is called Bare-metal firmware.

- Hardware Abstraction Layer (HAL) allows the application layer developer to write platform independent code. 

- A common software block design method is called component design, where we define small functional software blocks that have certain tasks. We define the interface mechanisms and the specs that each module needs to adhere to. 

- On-Target Testing refers to a term where you install the code onto your particular embedded systems instead of another. 

- Software Engineer Tools:
    * Simulators
    * Emulators
    * Compilers
    * Installers
    * Debuggers

- Simulations and Emulators allows validation of design to occur before the arrival of hardware. 
- Compilers, Installers, and debuggers will provide a quick development of features for the embedded target. 

- Principles of High Quality Software is to build and design Embedded software that is:
    * Maintainable
    * Testable
    * Portable
    * Robust
    * Efficient
    * Consistent


### C-Programming Review

- Embedded C is different from C because it puts some focus on some embedded features like efficient memory management, Timing centric operations, direction hardware/IO control, code size constraints, and optimize execution.

- Declaring variables in C programs requires a specific format with many fields
    * types-qualifiers(s) type-modifier data-type variable-name = initial-value;

- Data Types:
    * Integer
    * Floating Point
    * Enumerated
    * Derived
    * Void

- Type modifiers are used to increase the size of these types or change the properties of the variables.
- Type Modifiers:
    * Short 
    * Long
    * Unsigned
    * Signed 

- Type Qualifiers:
    * Const
    * Volatile
    * Restrict

- Signed Numbers are represented in the two's complement form, the conversion of sign numbers is a little more complex because they split the number of unique binary combinations in half (half for +ve numbers, other half for -ve numbers).

- **Pointers:** are special data types that hold address information. They are used to pass data by reference and can point to any type.

### Introduction to Software Configuration Management

- Software configuration management (SCM) is the process that handles how we configure and go about developing the code for the project.

- SCM simply describes how the software is developed and organized.

- Developing software can require a lot of process
    > Used directly by software engineers in development
    * Software Requirements
    * Environment Information
    * Software Build and Release
    * Software Review
    * Version Control
    * Testing 
    * Support
    > Used to help organize and support software projects
    * Documentation
    * Defect Tracking 
    * Task Management

- Legacy Systems: Older systems that may or may not be supported anymore. 
    > Software or hardware is outdated 

    > A loss of compatibility 

    > Parts not available 

    > Off company roadmap

### C Standardization and Team Coding Standards

- C-Programming Standards
    * C11
    * C99
    * C89 (ANSI-C) / C90 (ISO-C)
    * K&R C-Programming: Late 1970's (Informal Standard)

- Purposes of a coding standard 
    * Makes code readable
    * Improves runtime efficiency
    * Ensures consistency between various coders
    * Helps protect copyright claims

### Development Environments Overview

- The primary goal of the development environment would be to allow engineers to write, compile, install and debug a program.

- There are two different desktop environment that can be used in development:
    * The command line interface (CLI) 
    > Building software project using the CLI is a very usefull skill as it gives us powerful level of control of applictions, but at the expense of the user interface. 

    > For compilation, we will use GNU toolset to generate the SW executable files.

    > Installation and debugging are architecture dependent processes, host debugging can utilize a command line tool called GDB which stands for GNU project debugger.

    > On target debugging can be done through a network debugger or connected hardware debugger.

    * The integrated development environment (IDE)
    > The IDE encapsulates all the above complex details and provides a much more interactive user interface to make it easier to finish the job, but since the IDE hides some details from the developer, then it restrics the developer's degrees of freedom which becomes less ideal of them to work with IDEs

    > However, IDEs basically run behind the scenes the exact same commands as the commands we sue in the CLI. 

- Some basic Linux command line commands are:
    * pwd ==> shows the location of the present working directory.
    * ls ==> list all the current directories and files that are in the current working directory.
    * cd ==> change directory, this command changes the current working directory to another one.

