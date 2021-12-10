CC=gcc
CFLAGS= -Wextra -Wall -pedantic -g
LDFLAGS= -lparametre -llorenz -lentrees -lm   #Ordre des lib IMPORTANT, sinon risque de planter, lecture de droite à gauche!!!
LIB= ../../lib
INC= ../../Include
SRC= main.c
OBJ= $(SRC:.c=.o)

EXEC=main.exe

all: $(EXEC)

$(EXEC): $(OBJ) $(INC)/lorenz.h $(INC)/parametre.h $(INC)/entrees.h

	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -I $(INC) -L $(LIB) $(LDFLAGS)

%.o: %.c %.h

	@$(CC) -o $@ -c $< $(CFLAGS)


debug:
	gdb $(EXEC) 


run:
	./$(EXEC)


clean:
	rm $(EXEC) *.o