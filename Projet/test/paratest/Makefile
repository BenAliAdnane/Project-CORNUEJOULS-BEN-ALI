CC=gcc
CFLAGS=  -Wextra -Wall -pedantic -g

# options d'édition de liens : librairies utilisées
LDFLAGS=  -lm -lentrees -llorenz -lparametre

# emplacement des .a
LIB= ../../../lib


# emplacement des .h
INC= ../../../include


SRC= testparametre.c



OBJ= $(SRC:.c=.o)


# nom de l'exécutable
EXEC=testparametre.exe


all: $(EXEC)


$(EXEC): $(OBJ) $(INC)/parametre.h

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

