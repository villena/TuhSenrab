.PHONY= doc clean

CC=g++
//CC=g++-mp-4.8
OPTIONS= -g -fopenmp
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= coordenada.o cuerpo.o bhnode.o lienzo.o generadorcuerpos.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

main:    main.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) main.cpp $(OBJ) -o main

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

doc:
	doxygen

clean:
	rm -f $(OBJ) 
