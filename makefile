quickrun:
	clear
	make generate
	make compile
	./ebola
generate: main.c generateWorld.c populateWorld.c getRandomState.c generate.c cellStatus.c
	gcc main.c -o main.o generateWorld.c -o generateWorld.o populateWorld.c -o populateWorld.o getRandomState.c -o getRandomState.o generate.c -o generate.o cellStatus.c -o cellStatus.o -lpthread
compile: main.c generateWorld.c populateWorld.c getRandomState.c generate.c cellStatus.c
	gcc -o ebola main.c generateWorld.c populateWorld.c getRandomState.c generate.c cellStatus.c -lm -lpthread
clean:
	rm *.o
	rm ebola