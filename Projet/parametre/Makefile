CC=gcc

CFLAGS=  -Wextra -Wall -pedantic -g

LDFLAGS= -lparametre -llorenz -lentrees -lm    #Ordre des lib IMPORTANT, sinon risque de planter, lecture de droite à gauche!!!

LIB= ../../lib

INC= ../../include

EXEC= $(LIB)/libparametre.a

SRC=parametre.c

OBJ= $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : parametre.c  $(INC)/parametre.h 
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)
	ar rcs $(LIB)/libparametre.a $(OBJ)
	ranlib $(LIB)/libparametre.a

%.o: %.c %.h
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm $(LIB)/libparametre.a  *.o
