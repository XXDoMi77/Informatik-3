

DIR:=$(strip $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
CC = g++
LIBRARIES	= $(addprefix $(DIR)/,$(wildcard lib/*.*))
BINARIES	= $(addprefix bin/,$(patsubst *))

all:
	$(CC) $(LIBRARIES) -o $(DIR)/bin/main

clean:
	-rm -r -f *.o *.txt DOXYGENDOC

doc:
	doxygen /bin/Doxyfile 

run:
	./bin/main

test: 
	@echo $(LIBRARIES)