CC=gcc
CFLAGS=  -Wextra -Wall -pedantic -g

# options d'édition de liens : librairies utilisées
LDFLAGS=  -lm -lentrees -llorenz

# emplacement des .a
LIB= ../../../lib


# emplacement des .h
INC= ../../../include


SRC= testEntrees.c



OBJ= $(SRC:.c=.o)


# nom de l'exécutable
EXEC=testEntrees.exe


all: $(EXEC)


$(EXEC): $(OBJ) $(INC)/entrees.h

	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -I $(INC) -L $(LIB) $(LDFLAGS)


%.o: %.c %.h

	@$(CC) -o $@ -c $< $(CFLAGS)

# exécution en mode debug
debug:
	gdb $(EXEC) 

# exécution  
run:
	./$(EXEC)

# suppression de tous les binaires 
clean:
	rm $(EXEC) *.o
