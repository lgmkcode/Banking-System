all: compile run

compile:
	g++ -I ./include/ -o ./bin/main ./src/main.cpp ./src/bank.cpp

run:
	./bin/main