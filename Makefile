
main: src/main.c libchip8_utils.a
	gcc -Wall `pkg-config --cflags gtk4` -I . -o main src/main.c -L. -l:libchip8_utils.a -lGL -lGLU `pkg-config --libs gtk4`

libchip8_utils.a: display_utils.o file_utils.o
	ar rcs libchip8_utils.a file_utils.o display_utils.o
	rm file_utils.o display_utils.o

display_utils.o:
	gcc -Wall `pkg-config --cflags gtk4` -c -I . -o display_utils.o src/display_utils.c

file_utils.o:
	gcc -Wall -c -I . -o file_utils.o src/file_utils.c
