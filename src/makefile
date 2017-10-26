TARGET = fhlib.a
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

# compiler settings
CC      = gcc
CCFLAGS = -g -std=c11 -Wpedantic -Wall -Wconversion -Wextra -Werror=vla
ROOT    = $(shell pwd)
includeDir = $(ROOT)/../include/
LD      = gcc

# names of all .c and .o files
CFILES  = $(call rwildcard, $(CURRDIR), *.c)
HFILES  = $(call rwildcard, $(CURRDIR), *.h)
OFILES  = $(CFILES:.c=.o)

# rule how to compile .o files from .c files
%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $(basename $<).o

.PHONY: all

all: $(TARGET)

# main target: prg is the name of the executable to build
$(TARGET): $(OFILES)
	ar cr fhlib.a $(OFILES)
	cp --parents -R **/*.h *.h ../include/
	cp $(TARGET) ../lib/
	$(RM) $(OFILES) $(TARGET)
