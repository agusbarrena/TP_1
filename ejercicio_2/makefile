HEADERS = -I ../ejercicio_1/ -I .
SRC = ../ejercicio_1/*.cpp PersonajeFactory.cpp

main: main.cpp $(SRC)
	@g++ -std=c++11 -Wall -Wextra $(HEADERS) -g main.cpp $(SRC) -o main
	@./main
	@rm main
	@rm -rf main.dSYM/
