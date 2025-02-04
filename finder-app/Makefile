CC=$(CROSS_COMPILE)gcc
CFLAGS=-I.
OBJ = writer.o

default: writer

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

writer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
	rm -f writer