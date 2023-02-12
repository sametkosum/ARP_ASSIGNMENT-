# ARP assignment 2

Base repository for the **second assignment** of the **_Advanced and Robot Programming_** course - **_UNIGE_**.

Mustafa Melih Toslak 
Ahmet Samet Kosum      S5635830

Project's repository: [assignment 2]()

## The goal of assignment 

The assignment is designed to teach the utilization of shared memory and semaphores for interprocess communication between two separate programs using the fork. Additionally, it covers the usage of the fork and exec system calls for creating distinct processes.

## The program description

The program consists of three separate C programs: ProcessA.c, ProcessB.c, and Master.c.

ProcessA.c creates a console UI for displaying a moving circle and utilizes shared memory and semaphores for interprocess communication with ProcessB.c. The shared memory stores the position of the circle, and the semaphores ensure that the shared memory is only accessed by one process at a time. The code uses the ncurses library for the console UI and the bmp library for saving a snapshot of the UI as a bitmap image.

ProcessB.c displays the moving circle in the terminal window and also communicates with ProcessA.c using System V shared memory and semaphores. It maps the shared memory region to its virtual address space and uses semaphores to ensure mutually exclusive access to the shared memory. The code uses an infinite loop to wait for user input, such as resizing the terminal window or moving the circle. It generates a bitmap image of the moving circle and cleans up the shared memory and semaphores before exiting.

Master.c uses the fork and exec system calls to spawn ProcessA.c and ProcessB.c as separate processes in separate terminal windows. The parent process waits for both child processes to terminate and prints their exit status.

In summary, the code demonstrates the use of shared memory and semaphores for interprocess communication between two separate programs and the use of the fork and exec system calls for spawning separate processes.

The project provides a basic implementation of a simulated vision system using _shared memory_, according to the requirements specified in the [PDF file of the assignment](second_assignment.pdf).


In the folder `/src` you will find three processes:

## *libbitmap* installation and usage
To work with the bitmap library, you need to follow these steps:
1. Download the source code from [this GitHub repo](https://github.com/draekko/libbitmap.git) in your file system.
2. Navigate to the root directory of the downloaded repo and run the configuration through command ```./configure```. Configuration might take a while.  While running, it prints some messages telling which features it is checking for.
3. Type ```make``` to compile the package.
4. Run ```make install``` to install the programs and any data files and documentation.
5. Upon completing the installation, check that the files have been properly installed by navigating to ```/usr/local/lib```, where you should find the ```libbmp.so``` shared library ready for use.
6. In order to properly compile programs which use the *libbitmap* library, you first need to notify the **linker** about the location of the shared library. To do that, you can simply add the following line at the end of your ```.bashrc``` file:      
```export LD_LIBRARY_PATH="/usr/local/lib:$LD_LIBRARY_PATH"```
### Using *libbitmap* in your code
Now that you have properly installed the library in your system, it's time to use it in your programs:
1. Include the library in your programs via ```#include <bmpfile.h>```. If you want to check the content of ```bmpfile.h``` to glimpse the functionalities of the library, navigate to ```/usr/local/include```, where the header file should be located.
2. Compile programs which use the *libbitmap* library by linking the shared library with the ```-lbmp``` command.     
Example for compiling **circle.c**: ```gcc src/circle.c -lbmp -lm -o bin/circle``` 

## Compiling and running **processA** and **processB**
The two processes are implemented as UIs through *ncurses* library, therefore you need to compile their source files by linking the shared library via ```-lncurses```. As for the first assignment, exploit the resize event of the windows to get out of situations in which the graphical elements do not properly spawn.

## Executing **circle.c**
This is a simple example of a program which uses the *libbitmap* library. It generates a 100x100 colored `.bmp` file with user-defined name, depicting a blue circle of given radius. When you execute it, pass the two arguments (file name and radius value) along. Execution example: ```./bin/circle out/test.bmp 20```.

