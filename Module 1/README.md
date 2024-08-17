# Module 1
## Embedded System Development Components

### <code style="color:cyan">Introduction to Embedded Systems</code>

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

- **Microprocessor:** is a computer processor for which the data processing logic and control is included on a single integrated circuit (IC), or small number of ICs. The microprocessor contains the arithmetic, logic and control circuitry required to perform the functions of a computer's central processing unit (CPU). The microprocessor is a multipurpose, clock-driven, register-based, digital integrated circuit that accepts binary data as input, processes it according to instructions stored in its memory, and provides results (in binary) as output.

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

- RAM is volatile (not permanent) as when power is turned off, RAM loses all its data, while Flash can keep its data intact with not power at all. 

- A clock system provides synchornization across all these components.

- Peripherals that may be included:
    * Communication
    * Analog signal processing
    * Input/Output
    * Timing
    * Processor support 

### <code style="color:cyan">Embedded Software Engineering</code>

- It's good to start by breaking a software concept down into flow diagrams or software blocks.

- A Flow diagram can depict how a particular software or algorithm should behave. It contains the software constructus such as Conditional Decisions and high level function calls.

- Software Block Diagram did not differ greatly from a hardware block diagram, it depict how different blocks of code communicate. 

- A software block diagram can also depict a software system in layers.

- Software that directly interacts with hardware is called <code style="color:red">Bare-metal firmware</code>.

- Hardware Abstraction Layer (HAL) allows the application layer developer to write platform independent code. 

- A common software block design method is called <code style="color:red">component design</code>, where we define small functional software blocks that have certain tasks. We define the interface mechanisms and the specs that each module needs to adhere to. 

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


### <code style="color:cyan">C-Programming Review</code>

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

### <code style="color:cyan">Introduction to Software Configuration Management</code>

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

### <code style="color:cyan">C Standardization and Team Coding Standards</code>

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

### <code style="color:cyan">Development Environments Overview</code>

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

### <code style="color:cyan">Development Kits and Documentation</code>

- Development kits are an important tool for software engineers to start becoming familiar with an architecture.

- There are many manufacturers of microcontroller integrated circuits, <code style="color: red">ICs</code>, or application-specific integrated circuits, <code style="color: red">ASICs</code>, in the industry.

- Some examples include:
    * Texas Insturments
    * Silicon Labs
    * Atmel
    * NXP Semiconductors

- Some important features you need to know before selecting a microcontroller to work with:
    * Word Size
    * Number of registers
    * Flash/RAM sizes
    * Branch Prediction Support
    * Instruction/Data Cache Support
    * Floating Point Arithmetic Support
    * DMA Support

- The process of creating this feature and operation requirements checklist is called a specification, or a features spec. 

- It's possible that you need to make significant software changes, or even a hardware chage, int the middle of a design process if you did not evaluate your initial designs correctly.

- There are many documents that describe how to pick out a platform or evaluate a particular chip. 

- <code style="color : yellow">Selector Guide</code>: This helps a suer slip down choices by interactively selecting feature sets for our design. 

- It shows a full processor family. A chip family will share the same chip architecture. Each sub-family typically has more differences in supported hardware. And each device in a sub-family only has a slightly variances form on sub-family part to another. 

- <code style ="color : yellow">Product Brief</code>: gives a concise overview for quick evaluation of a platform for design, but with more details that what you will see in the selector guide. This is much more marketed, and is far less dense than strict product specifications.

- <code style="color:yellow">Datasheet</code>: gives technical specifications on a chip or family of chips with a breakdown of all the differences between each version or part number within the family. 
- Pin counts as well as operation specifications are proveded with diagrams, tables and plots.
- These operation specifications can include many things:
    > Electrical characteristics such as voltage and current operating ratings, where we get information on power specs of various conditions and operating modes.

    > Timing characterisitcs are provided for our operation microcontroller. There are timing diagrams that show expected time delays before certain digital signals are asserted.

    > Environmental effects such as temperature, can affect the device or operation characteristics.

    > Physical Package such as a CAD drawing with dimensions for the physical package and footprints of the chip.

- <code style="color:yellow">Family Technical Reference Manual</code>: describes information on general platform componenets and configuration. 

- <code style="color:yellow">Chip Errata</code>: a document that contains additional and corrective information for our particular device set. It will list all problems with the description configuration or the hardware's operation. 

- Many businesses just create developmetn kits and module boards so that prototyping can be done easily, speeding up the time it takes chip manufacturers to get their products in customer hands for evaluation. 

- Here are two examples:
    * <code style="color:blue">The Freedom FRDM-KL25Z</code> --> this board is a product of NXP and has many impressive features including:
        * some supplemental external hardware
        * a capacitive touch slide
        * an RGB LED
        * an accelerometer

    * <code style="color:blue">The Nordic nRF24L01 Chip</code> --> this is not a microcontroller development kits. Development kits are not limited to microcontroller silicon manufacturers since any type of sensor, external memory, driver or communication device would want to be evaluated. The part is difficult package to solder called a <code style="color:yellow">QFN package</code> and that may have specific requirements for its antenna. 

- Some boards have on board programmer/debugger support, which may be a secondary processor which is used to run as an onboard programmer/debugger adaptor that can flash the target processor, this adaptor is called <code style="color:yellow">openSDA</code> which has a specialized, dedicated connection to the processor target for debug support and chip programming. 

### <code style="color:cyan">Version Control</code>

- Version Control will be used to track our software changes. 

- There are many different types of VCS:
    * Concurrent Versions Systems (CVS)
    * Subversion (SVN)
    * Mercurial
    * IBM Rational ClearCase
    * Git

- In a Git repo configuration and management files are stores in a folder called <code style="color:yellow">.git</code>

