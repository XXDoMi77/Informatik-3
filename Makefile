DIR:=$(strip $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
CC = g++
LIBRARIES	= $(addprefix $(DIR)/,$(wildcard lib/*.*))

all:
ifeq (,$(wildcard ./plugins/local/include/ncursestw/curses.h))
	rm $(DIR)/plugins -rf; \
	mkdir $(DIR)/plugins; \
	mkdir $(DIR)/plugins/local; \
	mkdir $(DIR)/plugins/repos; \
	git clone https://github.com/mirror/ncurses.git $(DIR)/plugins/repos/ncurses; \
	cd $(DIR)/plugins/repos/ncurses; \
	bash configure --prefix $(DIR)/plugins/local --enable-widec --with-pthread; \
	make -j; \
	make -j install
endif
	$(CC) $(LIBRARIES) $(PLUGINS) -I $(DIR)/plugins/local/include -I $(DIR)/plugins/local/include/ncursestw -L $(DIR)/plugins/local/lib -o $(DIR)/main -lpthread -std=c++11 -lncursestw -ldl

clean:
	-rm -r -f *.o *.txt DOXYGENDOC main plugins

doc:
	doxygen $(DIR)/Doxyfile; \
	ln -s $(DIR)/DOXYGENDOC/html/index.html $(DIR)/DOXYGENDOC/index.html

run:
	gnome-terminal -e "$(DIR)/main"
	
runa:
	./main

test: 
	@echo $(LIBRARIES)
