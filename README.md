*This activity has been created as part of the 42 curriculum by nalrjoub.*

# Get Next Line

## Description
Get-Next-Line is a project designed to read a file descriptor line by line.
This project made use of static variables and `read()` system call to read data from the specified file descriptor.

## Instructions

### Usage
First of all, to read from a file we need to get its file descriptor using `open()` using system call. 
```c
#include <fcntl.h>
int fd = open("text.txt", O_RDONLY);
```
Or use standard input by assigning `0` to `fd`.\
Then, the function `get_next_line(fd)` is called and its return value is assigned to a `char *` variable.

## Compilation
To compile the code, use the command:
```bash
cc -Wall -Werror -Wextra *.c
```
then run the executable
```bash
./a.out
```
## Resources
- https://www.geeksforgeeks.org/c/g-fact-80/ (static variables).
- man page for `read()` system call.
- https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html (-Walloc-size error)
- AI was used to check for possible memory leaks.
