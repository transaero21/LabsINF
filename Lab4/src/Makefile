all: default custom

default: default.c parse.c output.c
	gcc -o default -l readline default.c parse.c output.c

custom:
	gcc -o custom custom.c parse.c output.c input.c utils.c

clean:
	rm default custom
