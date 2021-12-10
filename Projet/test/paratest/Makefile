CC=gcc

CFLAGS=  -Wextra -Wall -pedantic -g

LDFLAGS= -llorenz -lparametre -lentrees -lm

LIB= ../../../lib

INC= ../../../include

SRC= testparametre.c

OBJ= $(SRC:.c=.o)

EXEC=testparametre.exe


all: $(EXEC)

$(EXEC): $(OBJ) $(INC)/parametre.h

	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -I $(INC) -L $(LIB) $(LDFLAGS)

%.o: %.c %.h

	@$(CC) -o $@ -c $< $(CFLAGS)

debug:
	gdb $(EXEC) 
  
run:
	./$(EXEC)

clean:
	rm $(EXEC) *.o
