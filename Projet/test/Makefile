CC=gcc

CFLAGS=  -Wextra -Wall -pedantic

LDFLAGS=  -lm -lentrees

LIB= ../../lib

INC= ../../include

SRC= testEntrees.c

OBJ= $(SRC:.c=.o)

EXEC=testEntrees.exe

all: $(EXEC)

$(EXEC): $(OBJ) $(INC)/entrees.h
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -I $(INC) -L $(LIB) $(LDFLAGS)

%.o: %.c %.h
	@$(CC) -o $@ -c $< $(CFLAGS)
debug:
	gdb $(EXEC)		# gdb ou ddd 
run:	
	./$(EXEC)
clean:
	rm $(EXEC) *.o