
main: main.c libchip8_utils.a
	gcc -Wall `pkg-config --cflags gtk4` -o main main.c -L. -l:libchip8_utils.a -lGL -lGLU `pkg-config --libs gtk4`

libchip8_utils.a: display_utils.o file_utils.o
	ar rcs libchip8_utils.a file_utils.o display_utils.o
	rm file_utils.o display_utils.o

display_utils.o: display_utils.c
	gcc -Wall `pkg-config --cflags gtk4` -c -o display_utils.o display_utils.c

file_utils.o: file_utils.c
	gcc -Wall -c -o file_utils.o file_utils.c
