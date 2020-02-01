quickrun:
	clear
	make generate
	make compile
	./ebola
generate: main.c populateWorld.c getRandomState.c generate.c cellStatus.c
	gcc main.c -o main.o populateWorld.c -o populateWorld.o getRandomState.c -o getRandomState.o generate.c -o generate.o cellStatus.c -o cellStatus.o
compile: main.c populateWorld.c getRandomState.c generate.c cellStatus.c
	gcc -o ebola main.c populateWorld.c getRandomState.c generate.c cellStatus.c -lm
clean:
	rm *.o
	rm ebola