**GET_NEXT_LINE**

The aim of this project was to make a function that returns a line ending with a newline, read from a file descriptor.  
Calling the function in a loop will then allow you to read the text available on a file descriptor one line at a time
until the end of the text, no matter the size of either the text or one of its lines.  
The function behaves well when it reads from a file, from the standard output, from a redirection etc.  

Function prototype:  
`int		get_next_line(const int fd, char **line);`  
The first parameter is the file descriptor of the file we're going to read from.  
The second parameter is the adress of a string that will be used to save the line read from the file.  
The return value can be 1, 0 or -1 depending on whether a line has been read, the reading has been completed or
an error has happened respectively.  
_(Some functions from [LIBFT][link] were used)_

[link]: https://github.com/AnastasiaBur/LIBFT
