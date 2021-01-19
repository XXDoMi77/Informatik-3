

DIR:=$(strip $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
CC = g++
LIBRARIES	= $(addprefix $(DIR)/,$(wildcard lib/*.*))

all:
	$(CC) $(LIBRARIES) -o $(DIR)/main -lpthread -lncurses -std=c++11

clean:
	-rm -r -f *.o *.txt DOXYGENDOC main

doc:
	doxygen $(DIR)/Doxyfile

run:
	./bin/main

test: 
	@echo $(LIBRARIES)
