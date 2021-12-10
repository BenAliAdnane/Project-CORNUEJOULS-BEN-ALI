CC=gcc
CFLAGS=  -Wextra -Wall -pedantic -g
LDFLAGS=  -lm -lentrees -lparametre
LIB= ../../lib
INC= ../../include
EXEC= $(LIB)/liblorenz.a libparametre.a
SRC=lorenz.c
OBJ= $(SRC:.c=.o)
all : $(EXEC)
$(EXEC) : lorenz.c $(INC)/lorenz.h
	$(CC) -o $(OBJ) -c $(SRC) $(CFLAGS)
	ar rcs $(LIB)/liblorenz.a libparametre.a $(OBJ)
	ranlib $(LIB)/liblorenz.a libparametre.a
%.o: %.c %.h
	@$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm $(LIB)/liblorenz.a  *.o
