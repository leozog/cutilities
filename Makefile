TARGET = test
SRCS = main.c darray.c vec.c random.c

CC = gcc
CFLAGS = -Wall
LIBS = -lm

OBJS = $(patsubst %,obj/%,$(patsubst %.c,%.o,$(SRCS)))

test: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $(TARGET) $(OBJS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $< 


clear:
ifeq ($(OS),Windows_NT)
	del obj\*.o
endif
ifeq ($(OS),Linux)
	rm -f obj/*.o
endif