# Variables for Cross Compilation
CC_NATIVE = gcc
CC_CROSS = x86_64-linux-gnu-gcc
CFLAGS = -Wall -g
WRITEFILE = /home/rounsahaubuntu/aesd-assignments/finder-app/rounaksaha_debug.txt
WRITESTR = rounaksaha

# Target Architecture is Native by Default
CROSS_COMPILE ?= native

# Set Compiler Based on Target Architecture
ifeq ($(CROSS_COMPILE),native)
	CC = $(CC_NATIVE)
else ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
	CC = $(CC_CROSS)
else
	$(error "Unsupported Target Architecture: $(CROSS_COMPILE)")
endif

# Build Rules
writer: writer.o
	$(CC) $(CFLAGS) -o writer writer.o
writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c
run: writer
	./writer $(WRITEFILE) $(WRITESTR)
clean:
	rm writer writer.o
