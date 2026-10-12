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
## Algorithm

The algorithm uses three main variables:

- `ans` — a string that stores the line to be returned.
- `stash` — a string that stores data read from the file descriptor across function calls, preserving any remaining characters that have not yet been returned.
- `buffer` — a temporary string that stores the bytes read by the `read()` function.

The algorithm starts by reading data into `buffer` and appending it to `stash`. This process continues until `stash` contains a newline character (`\n`) or the end of the file is reached.

Once a complete line is available, the algorithm extracts the line from `stash` and stores it in `ans`. The remaining characters, if any, are kept in `stash` for the next function call.

For example, suppose `stash` contains the following data before extracting a line:

```
stash -> "Hello world\nHello"
```

After extracting the first line:

```
ans   -> "Hello world\n"
stash -> "Hello"
```

The function then returns `ans`, while `stash` preserves the remaining characters for the next call to `get_next_line()`.

If the end of the file is reached and `stash` still contains characters, those characters are returned as the final line, even if they are not followed by a newline character. If no characters remain, the function returns `NULL`.

## Resources
- https://www.geeksforgeeks.org/c/g-fact-80/ (static variables).
- man page for `read()` system call.
- https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html (-Walloc-size error)
- AI was used to check for possible memory leaks.
