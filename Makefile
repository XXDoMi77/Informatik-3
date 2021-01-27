DIR		=$(strip $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))
CC			=g++
LIBRARIES	=$(addprefix $(DIR)/,$(wildcard lib/*.*))
LIB1		=$(DIR)/plugins/repos/INF3_PRAK/TASK3.C
LIB2		=$(DIR)/plugins/repos/INF3_PRAK/TASK3.H
LIB3		=$(DIR)/plugins/repos/INF3_PRAK/SIMPLESOCKET.C
LIB4		=$(DIR)/plugins/repos/INF3_PRAK/SIMPLESOCKET.H

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
	rm $(DIR)/plugins/repos/INF3_PRAK -rf; \
	git clone https://github.com/XXDoMi77/INF3_PRAK.git $(DIR)/plugins/repos/INF3_PRAK; \
	$(CC) $(LIBRARIES) -I $(DIR)/plugins/repos/INF3_PRAK $(LIB1) $(LIB2) $(LIB3) $(LIB4) $(PLUGINS) -I $(DIR)/plugins/local/include -I $(DIR)/plugins/local/include/ncursestw -L $(DIR)/plugins/local/lib -o $(DIR)/main -lpthread -std=c++11 -lncursestw -ldl

clean:
	-rm -r -f *.o *.txt DOXYGENDOC main plugins

doc:
	doxygen $(DIR)/Doxyfile; \
	ln -s $(DIR)/DOXYGENDOC/html/index.html $(DIR)/DOXYGENDOC/index.html

run:
	gnome-terminal -e "$(DIR)/main"
	
runa:
	./main

clone:
	git clone https://github.com/amlmsh/INF3_PRAK.git $(DIR)/plugins/repos/INF3_PRAK

test: 
	@echo $(LIBRARIES)
