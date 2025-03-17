CC = gcc
CFLAGS = -I/include # Adiciona o diretorio include ao caminho de busca de headers

# Cria o diretorio build caso ele nao exista
build:
	mkdir build

./build/menu.o: ./src/menu.c ./include/Interface.h | build
	$(CC) $(CFLAGS) -c ./src/menu.c -o ./build/menu.o 

./build/list.o: ./src/list.c ./include/Mineassist.h | build
	$(CC) $(CFLAGS) -c ./src/list.c -o ./build/list.o

./build/main.o: ./src/main.c ./include/Mineassist.h | build
	$(CC) $(CFLAGS) -c ./src/main.c -o ./build/main.o

all: ./build/main.o ./build/list.o ./build/menu.o
	$(CC) ./build/main.o ./build/list.o ./build/menu.o -o ./tests/main.exe

clean:
	rm -rf ./tests/main.exe