**GET_NEXT_LINE**

The aim of this project was to make a function that returns a line ending with a newline, read from a file descriptor.  
The return value can be 1, 0 or -1 depending on whether a line has been read, the reading has been completed or
an error has happened respectively.  
Calling the function in a loop will then allow you to read the text available on a file descriptor one line at a time
until the end of the text, no matter the size of either the text or one of its lines.  
The function behaves well when it reads from a file, from the standard output, from a redirection etc.
