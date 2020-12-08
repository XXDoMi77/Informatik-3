

DIR:=$(strip $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
CC = g++
LIBRARIES	= $(addprefix $(DIR)/,$(wildcard lib/*.*))

all:
	$(CC) $(LIBRARIES) -o $(DIR)/bin/main

clean:
	-rm -r -f *.o *.txt DOXYGENDOC

doc:
	doxygen $(DIR)/Doxyfile

run:
	./bin/main

test: 
	@echo $(LIBRARIES)