`$ gcc -c utils.c`\
`$ gcc -c read_from_file.c`\
`$ gcc utils.o read_from_file.o -o run`\

this is the preferred command stream for compiling multiple files as when changes are made you can avoid recompiling the library that hasn't changed, saving time on large projects.

the alternative option is to use the following:\
`$ gcc utils.c read_from_file.c -o run`\
which compiles the entire program each time, rather than just linking objects (the former is better practice)