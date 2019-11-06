# Cooperative_Scheduler_for_Temperature_Control

Real-time concepts course, taken during my masters, introduced RTOS principles and its components. To demonstrate the understanding of the scheduler and its components such as tasks, registers, stack, semaphores, etc., I have designed a Cooperative scheduler for a non-RTOS temperature control embedded system.

The embedded system is a combination of a microcontroller (MSP430FR6989), a Bluetooth module (HC-06), a temperature sensor (LM-35), and a 4-wire cooling fan (MGT8012UR). The temperature sensor senses the temperature and sends the information to the microcontroller. The microcontroller processes the data and sets the fan speed; It also transmits the data to a Bluetooth paired smartphone for remote monitoring of the temperature and fan speed.

The developed cooperative scheduler has the following elements of an RTOS: Regular tasks, ISR tasks, Scheduler task, Library functions, Registers, Stack utilization, Global variables, Synchronization objects, Communication objects. It also clearly demonstrates the context switching and resilience.
