TARGET?=
CPPFLAGS=
CFLAGS=-fopenmp
LDFLAGS=-lpthread
CC=gcc

all: $(TARGET)

$(TARGET): $(TARGET).o random.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(TARGET).o: $(TARGET).c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

random.o: random.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
