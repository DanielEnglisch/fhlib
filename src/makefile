TARGET = fhlib.a
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

CC      = g++
CCFLAGS = -g -std=c++11 -Wpedantic -Wall -Wconversion -Wextra -Werror=vla
ROOT    = $(shell pwd)
includeDir = $(ROOT)/../include/

CFILES  = $(call rwildcard, $(CURRDIR), *.cpp)

HFILES  = $(call rwildcard, $(CURRDIR), *.h)
OFILES  = $(CFILES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $< -o $(basename $<).o

.PHONY: all

all: $(TARGET)

$(TARGET): $(OFILES)
	ar cr fhlib.a $(OFILES)
	cp $(TARGET) ../lib/
	rm -r ../include/*
	cp --parents -R **/*.h *.h ../include/
	$(RM) $(OFILES) $(TARGET)
