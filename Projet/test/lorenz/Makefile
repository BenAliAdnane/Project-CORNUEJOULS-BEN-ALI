CC=gcc
CFLAGS=  -Wextra -Wall -pedantic -g

LDFLAGS=  -lm -lentrees -llorenz

LIB= ../../../lib

INC= ../../../Include

SRC= testlorenz.c

OBJ= $(SRC:.c=.o)

EXEC=testlorenz.exe


all: $(EXEC)


$(EXEC): $(OBJ) $(INC)/lorenz.h

	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -I $(INC) -L $(LIB) $(LDFLAGS)


%.o: %.c %.h

	@$(CC) -o $@ -c $< $(CFLAGS)


debug:
	gdb $(EXEC) 


run:
	./$(EXEC)


clean:
	rm $(EXEC) *.o

