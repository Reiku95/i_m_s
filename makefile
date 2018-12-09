NAME = ims
EXE = ims
SUFFIX =cpp

CC =g++
DEBUGCFLAGS=-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
CFLAGS =-std=c++11 -g -pedantic
LDFLAGS =-lsimlib -lm

OBJFILES=main.o garbage_truck.o globals.o area.o place.o

.PHONY: all

all: $(OBJFILES) $(EXE)

%.o : %.$(SUFFIX)
	$(CC) $(CFLAGS) $(LDFLAGS) -c $<

$(EXE): $(OBJFILES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJFILES) -o $@

run:
	./ims --scenario 1
	./ims --scenario 2
	./ims --scenario 3
	./ims --scenario 4

clean-objects:
	rm -f *.o

clean-exe:
	rm -f $(EXE)

clean-all: clean-exe clean-objects

cl: clean-all

re: cl $(EXE)
