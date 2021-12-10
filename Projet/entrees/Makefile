CC=gcc

CFLAGS=  -Wextra -Wall -pedantic -g

LDFLAGS=  -lparametre -llorenz -lentrees -lm    #Ordre des lib IMPORTANT, sinon risque de planter, lecture de droite à gauche!!!

LIB= ../../lib

INC= ../../include

EXEC= $(LIB)/libentrees.a

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
