########################################### VARIABLES ###########################################
EXE = play
TST = command_test dialogue_test enemy_test game_management_test game_test inventory_test link_test object_test player_test set_test space_test
OBJS = $(OBJ)/command.o $(OBJ)/game_loop.o $(OBJ)/game_management.o $(OBJ)/game.o $(OBJ)/graphic_engine.o $(OBJ)/object.o $(OBJ)/player.o $(OBJ)/space.o $(OBJ)/set.o $(OBJ)/enemy.o $(OBJ)/inventory.o $(OBJ)/link.o $(OBJ)/dialogue.o 
OBJS_TST = $(OBJ)/command_test.o $(OBJ)/dialogue_test.o $(OBJ)/enemy_test.o $(OBJ)/game_management_test.o $(OBJ)/game_test.o $(OBJ)/inventory_test.o $(OBJ)/link_test.o $(OBJ)/object_test.o $(OBJ)/player_test.o $(OBJ)/set_test.o $(OBJ)/space_test.o
GCC = gcc 
CFALGS= -Wall -ansi -pedantic -g
##################### CARPETAS #####################
SRC = ./src
OBJ = ./obj
INC = ./include
TEST = ./test
LIB = ./lib
INCLUDE = -I ./include
CMDFILES = ./cmd_files

########################################### ETIQUETAS DEL MAKE ##################################
all: $(EXE) $(TST)

$(EXE): ./lib/libscreen.a $(OBJS)
	$(GCC) $(CFLAGS) -o $@ $(OBJS) -Llib -lscreen

########################################### OBJECTOS  ###########################################
$(OBJ)/command.o: $(SRC)/command.c $(INC)/command.h $(INC)/types.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/enemy.o: $(SRC)/enemy.c $(INC)/enemy.h $(INC)/types.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/game_loop.o: $(SRC)/game_loop.c $(INC)/graphic_engine.h $(INC)/game.h $(INC)/command.h $(INC)/space.h $(INC)/types.h $(INC)/object.h $(INC)/player.h $(INC)/set.h $(INC)/enemy.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/game_management.o: $(SRC)/game_management.c $(INC)/game_management.h $(INC)/types.h $(INC)/game.h $(INC)/command.h $(INC)/object.h $(INC)/player.h $(INC)/space.h $(INC)/set.h $(INC)/enemy.h $(INC)/inventory.h $(INC)/link.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/game.o: $(SRC)/game.c $(INC)/game.h $(INC)/command.h $(INC)/space.h $(INC)/types.h $(INC)/game_management.h $(INC)/object.h $(INC)/player.h $(INC)/set.h $(INC)/enemy.h $(INC)/link.h $(INC)/dialogue.h 
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/graphic_engine.o: $(SRC)/graphic_engine.c $(INC)/graphic_engine.h $(INC)/game.h $(INC)/command.h $(INC)/space.h $(INC)/types.h $(INC)/libscreen.h $(INC)/object.h $(INC)/player.h $(INC)/set.h $(INC)/enemy.h $(INC)/dialogue.h 
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/object.o: $(SRC)/object.c $(INC)/object.h $(INC)/types.h $(INC)/inventory.h $(INC)/set.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/player.o: $(SRC)/player.c $(INC)/player.h $(INC)/types.h $(INC)/inventory.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/space.o: $(SRC)/space.c $(INC)/space.h $(INC)/types.h $(INC)/object.h $(INC)/set.h $(INC)/link.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/set.o: $(SRC)/set.c $(INC)/set.h $(INC)/types.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/inventory.o: $(SRC)/inventory.c $(INC)/inventory.h $(INC)/object.h $(INC)/set.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)	 

$(OBJ)/link.o: $(SRC)/link.c $(INC)/link.h $(INC)/types.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/dialogue.o: $(SRC)/dialogue.c $(INC)/dialogue.h $(INC)/types.h $(INC)/command.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

########################################### TESTS ###############################################
command_test: $(OBJ)/command_test.o $(OBJ)/command.o 
	$(GCC) $(CFLAGS) -o $@ $^	 

dialogue_test: $(OBJ)/dialogue_test.o $(OBJ)/dialogue.o $(OBJ)/command.o
	$(GCC) $(CFLAGS) -o $@ $^	 
	
enemy_test: $(OBJ)/enemy_test.o $(OBJ)/enemy.o
	$(GCC) $(CFLAGS) -o $@ $^

game_management_test: $(OBJ)/game_management_test.o $(OBJ)/game_management.o $(OBJ)/game.o $(OBJ)/command.o $(OBJ)/object.o $(OBJ)/player.o $(OBJ)/space.o $(OBJ)/set.o $(OBJ)/enemy.o $(OBJ)/inventory.o $(OBJ)/link.o $(OBJ)/dialogue.o
	$(GCC) $(CFLAGS) -o $@ $^

game_test: $(OBJ)/game_test.o $(OBJ)/game.o $(OBJ)/command.o $(OBJ)/space.o $(OBJ)/game_management.o $(OBJ)/object.o $(OBJ)/player.o $(OBJ)/set.o $(OBJ)/enemy.o $(OBJ)/link.o $(OBJ)/inventory.o $(OBJ)/dialogue.o
	$(GCC) $(CFLAGS) -o $@ $^

inventory_test: $(OBJ)/inventory_test.o $(OBJ)/inventory.o $(OBJ)/object.o $(OBJ)/set.o
	$(GCC) $(CFLAGS) -o $@ $^

link_test: $(OBJ)/link_test.o $(OBJ)/link.o
	$(GCC) $(CFLAGS) -o $@ $^

object_test: $(OBJ)/object_test.o $(OBJ)/object.o $(OBJ)/inventory.o $(OBJ)/set.o
	$(GCC) $(CFLAGS) -o $@ $^

player_test: $(OBJ)/player_test.o $(OBJ)/player.o $(OBJ)/inventory.o $(OBJ)/set.o
	$(GCC) $(CFLAGS) -o $@ $^	

set_test: $(OBJ)/set_test.o $(OBJ)/set.o
	$(GCC) $(CFLAGS) -o $@ $^	 

space_test: $(OBJ)/space_test.o $(OBJ)/space.o $(OBJ)/object.o $(OBJ)/set.o $(OBJ)/link.o $(OBJ)/inventory.o
	$(GCC) $(CFLAGS) -o $@ $^ 

##########################################
$(OBJ)/command_test.o: $(SRC)/command_test.c $(INC)/command.h $(INC)/types.h $(INC)/test.h $(INC)/command_test.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/dialogue_test.o: $(SRC)/dialogue_test.c $(INC)/dialogue_test.h $(INC)/dialogue.h $(INC)/test.h $(INC)/types.h $(INC)/command.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/enemy_test.o: $(SRC)/enemy_test.c $(INC)/types.h $(INC)/enemy.h $(INC)/enemy_test.h $(INC)/test.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/game_management_test.o: $(SRC)/game_management_test.c $(INC)/game_management_test.h $(INC)/test.h $(INC)/game_management.h $(INC)/game.h $(INC)/types.h $(INC)/command.h $(INC)/object.h $(INC)/player.h $(INC)/space.h $(INC)/set.h $(INC)/enemy.h $(INC)/inventory.h $(INC)/link.h $(INC)/dialogue.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/game_test.o: $(SRC)/game_test.c $(INC)/game_test.h $(INC)/test.h $(INC)/game.h $(INC)/command.h $(INC)/space.h $(INC)/types.h $(INC)/game_management.h $(INC)/object.h $(INC)/player.h $(INC)/set.h $(INC)/enemy.h $(INC)/link.h $(INC)/inventory.h $(INC)/dialogue.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/inventory_test.o: $(SRC)/inventory_test.c $(INC)/inventory_test.h $(INC)/inventory.h $(INC)/test.h $(INC)/object.h $(INC)/set.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/link_test.o: $(SRC)/link_test.c $(INC)/link_test.h $(INC)/link.h $(INC)/test.h $(INC)/types.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/object_test.o: $(SRC)/object_test.c $(INC)/object_test.h $(INC)/object.h $(INC)/test.h $(INC)/types.h $(INC)/inventory.h $(INC)/set.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(OBJ)/player_test.o: $(SRC)/player_test.c $(INC)/player_test.h $(INC)/player.h $(INC)/test.h $(INC)/types.h $(INC)/inventory.h $(INC)/set.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)	

$(OBJ)/set_test.o: $(SRC)/set_test.c $(INC)/set.h $(INC)/types.h $(INC)/set_test.h $(INC)/test.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)	

$(OBJ)/space_test.o: $(SRC)/space_test.c $(INC)/space.h $(INC)/types.h $(INC)/object.h $(INC)/set.h $(INC)/space_test.h $(INC)/test.h $(INC)/link.h $(INC)/inventory.h
	$(GCC) -c $(INCLUDE) -o $@ $< $(CFLAGS)	

########################################### OTROS ###############################################s
clean: 
	rm $(EXE) $(OBJS) $(OBJS_TST) $(TST)

log: $(EXE)
	./$< hormiguero.dat -l log.txt

doxygen:
	doxygen Doxyfile

run:
	./$(EXE) hormiguero.dat

val:
	valgrind --leak-check=full -s ./$(EXE) hormiguero.dat