.PHONY= doc clean

CC=g++
OPTIONS= -g 
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= bhnode.o cuerpo.o coordenada.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

tad:    main.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/tad.cpp $(OBJ) -o main

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

doc:
	doxygen

clean:
	rm -f $(OBJ) 
