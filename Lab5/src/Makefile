all: parser timing

parser: parser.c args.c utils.c files.c objects.c sorter.c
	gcc -o parser parser.c args.c utils.c files.c objects.c sorter.c

timing: timing.c args.c utils.c objects.c sorter.c randomizer.c
	gcc -o timing timing.c args.c utils.c objects.c sorter.c randomizer.c
