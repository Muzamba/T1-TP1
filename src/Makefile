IDIR = ../include
CC = g++
CFLAGS = -I$(IDIR) -std=c++11

ODIR = obj
LDIR = ../lib


LIBS = -lm

_DEPS = dominios.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = dominios.o testes/testes.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


teste: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ test