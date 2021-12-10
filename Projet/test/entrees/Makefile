CC=gcc

CFLAGS=  -Wextra -Wall -pedantic -g

LDFLAGS=  -lm -lentrees

LIB= ../../../lib

INC= ../../../include

SRC= testEntrees.c

OBJ= $(SRC:.c=.o)

EXEC=testEntrees.exe

all: $(EXEC)

$(EXEC): $(OBJ) $(INC)/entrees.h
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -I $(INC) -L $(LIB) $(LDFLAGS)

testEntrees.o: testEntrees.c $(INC)/entrees.h
	$(CC) $(CFLAGS) -o testEntrees.o -c testEntrees.c

%.o: %.c %.h
	@$(CC) -o $@ -c $< $(CFLAGS)

debug:
	gdb $(EXEC) 

run:
	./$(EXEC)

clean:
	rm $(EXEC) *.o
