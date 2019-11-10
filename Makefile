run: all
	./main
all: main.c
	gcc -o main main.c modelo.c malha.c lista.c coords.c toksplit.c -lGLU -lGL -lglut -lGLEW -lSOIL `sdl-config --cflags --libs` -lSDL -lSDL_mixer -lm
