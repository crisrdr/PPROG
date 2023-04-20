########################## VARIABLES ##########################

EXE = play
TST = set_test space_test 
OBJ = libscreen.a command.o game_loop.o game_reader.o game.o graphic_engine.o object.o player.o space.o set.o enemy.o
GCC = gcc -Wall -ansi -pedantic -c -g


##################### ETIQUETAS DEL MAKE #####################

all: $(EXE) $(TST)

$(EXE): $(OBJ)
	gcc -o $(EXE) $(OBJ) -L ./ -lscreen

command.o: command.c command.h types.h
	$(GCC) $<

enemy.o: enemy.c enemy.h types.h
	$(GCC) $<

game_loop.o: game_loop.c graphic_engine.h game.h command.h space.h types.h object.h player.h set.h enemy.h
	$(GCC) $<

game_reader.o: game_reader.c game_reader.h types.h game.h command.h object.h player.h space.h set.h enemy.h
	$(GCC) $<

game.o: game.c game.h command.h space.h types.h game_reader.h object.h player.h set.h enemy.h
	$(GCC) $<

graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h types.h libscreen.h object.h player.h set.h enemy.h
	$(GCC) $<

object.o: object.c object.h types.h 
	$(GCC) $<

player.o: player.c player.h types.h 
	$(GCC) $<

space.o: space.c space.h types.h object.h set.h
	$(GCC) $<

set.o: set.c set.h types.h
	$(GCC) $<

#### TESTS

set_test: set_test.o set.o 
	gcc -g -o set_test $^

space_test: space_test.o space.o object.o set.o
	gcc -g -o space_test $^

set_test.o: set_test.c set.h types.h set_test.h test.h
	$(GCC) $<

space_test.o: space_test.c space.h types.h object.h set.h space_test.h test.h
	$(GCC) $<

clean: 
	rm $(EXE) $(TST) *.o 

run:
	./$(EXE) hormiguero.dat

val:
	valgrind --leak-check=full -s ./play hormiguero.dat