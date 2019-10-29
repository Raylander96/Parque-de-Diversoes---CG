run: all
	./main
all: main.c
	gcc -o main main.c -lGLU -lGL -lglut -lGLEW -lSOIL `sdl-config --cflags --libs` -lSDL -lSDL_mixer -lm
