HEADERS = -I ../ejercicio_1/ -I ../ejercicio_2/
SRC = $(shell find ../ejercicio_1 ../ejercicio_2 -name '*.cpp' ! -name 'main.cpp') simularBatalla.cpp

main: main.cpp $(SRC)
	@g++ -std=c++11 -Wall -Wextra $(HEADERS) -g main.cpp $(SRC) -o main
	@./main
	@rm main
	@rm -rf main.dSYM/
