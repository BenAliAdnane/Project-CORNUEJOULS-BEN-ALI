CC=gcc
CFLAGS=  -Wextra -Wall -pedantic -g
LDFLAGS= -llorenz -lparametre -lentrees -lm     #Ordre des lib IMPORTANT, sinon risque de planter, lecture de droite à gauche!!!
LIB= ../../lib
INC= ../../include
EXEC= $(LIB)/liblorenz.a
SRC=lorenz.c
OBJ= $(SRC:.c=.o)
all : $(EXEC)
$(EXEC) : lorenz.c $(INC)/lorenz.h
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)
	ar rcs $(LIB)/liblorenz.a $(OBJ)
	ranlib $(LIB)/liblorenz.a 
%.o: %.c %.h
	@$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm $(LIB)/liblorenz.a  *.o
