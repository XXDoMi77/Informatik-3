DIR:=$(strip $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
CC = g++
LIBRARIES	= $(addprefix $(DIR)/,$(wildcard lib/*.*))

all:
	rm ~/local -rf; \
	rm ~/repos -rf; \
	mkdir ~/local; \
	mkdir ~/repos; \
	git clone https://github.com/mirror/ncurses.git ~/repos/ncurses; \
	cd ~/repos/ncurses; \
	bash configure --prefix ~/local --enable-widec --with-pthread; \
	cd ~/repos/ncurses; \
	make -j; \
	make -j install; \
	$(CC) $(LIBRARIES) $(PLUGINS) -I ~/local/include -I ~/local/include/ncursestw -L ~/local/lib -o $(DIR)/main -lpthread -std=c++11 -lncursestw -ldl

clean:
	-rm -r -f *.o *.txt DOXYGENDOC main

doc:
	doxygen $(DIR)/Doxyfile

run:
	gnome-terminal -e "$(DIR)/main"
	
runa:
	./main

test: 
	@echo $(LIBRARIES)
