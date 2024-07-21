TARGET=add-nbo
CFLAGS=-g
CC=cc

all: $(TARGET)

$(TARGET): main.o
	$(CC) $^ $(LOADLIBS) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o