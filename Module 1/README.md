# Module 1
Embedded System Development Components

## Software Requirements
* IDE: Code Composer Studio (CCS) 
* Serial Terminal Emulator: RealTerm
* VirtualBox: Virtual Machine Hypervisor
* Linux Distribution: Ubuntu Latest LTS

### Definition of an Embedded System
An Embedded System is a computerized system that is purpose built for its application.
Each embedded systems has a special purpose and contraints in their system resources such as processing memory, and peripherals.

- The hardware is a combination of a processing core, and external circuits for the processor to interact with.

- Target embedded systems usually use Printed Circuit Board (PCB) technology for hardware implementation. A PCB is a substrate with conductive wires. It interconnects many integrated circuits and passive elements that all have been soldered onto the board.

- An external programmer is connected to the embedded systems processor, in order to install a target application into the internal memory. 

- A host machine is responsible for developing and compiling and coordinate the install which is equally as important  as the development of the system PCB itself.

- One solution for the processing core would be a microcontroller. Microprocessors and microcontrollers are not the same!

- **Microcontroller:** is a microprocessor with added functionality such as memory peripheral hardware.

- The processor part of the microcontroller is called the Centeral Processing Unit (CPU).

- **CPU:** a piece of hardware that runs our software by fetching and executing assembling  instructions for memory.

CPU contains:
* Registers
* Arithmetic Logic Unit (ALU)
* Interrupt Controller
* Debug

- The CPU and its subsystems interact with other mircocontroller resources through one or more buses.
- A bus controller aids the processor in this data transmission between memory and peripherals.

- Memory holds data that we operate on as well as the program that we're executing. This data is stored in a combination of flass and Random Access Memory (RAM). 

- A clock system provides synchornization across all these components.

- Peripherals that may be included:
* Communication
* Analog signal processing
* Input/Output
* Timing
* Processor support 

