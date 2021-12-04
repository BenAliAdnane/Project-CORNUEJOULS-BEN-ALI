CC=gcc

CFLAGS=  -Wextra -Wall -pedantic -g

LDFLAGS=  -lm

LIB= ../../lib

INC= ../../include

EXEC= libentrees.a

SRC=entrees.c

OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : entrees.c $(INC)/entrees.h
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)
	ar rcs $(LIB)/libentrees.a $(OBJ)
	ranlib $(LIB)/libentrees.a

%.o: %.c %.h
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm $(LIB)/libentrees.a  *.o
