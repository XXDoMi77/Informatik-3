CC=g++

OBJS= main.o battleship.o
DEMOTARGET= main battleship

main.o:	main.cpp
	$(CC) -c $<  -std=c++11

battleship.o:	battleship.cpp
	$(CC) -c $<  -std=c++11


main:	$(OBJS)
	$(CC) -o $@ $^ -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11 -lpthread $(LIBS)

battleship:	$(OBJS)
	$(CC) -o $@ $^ -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11 -lpthread $(LIBS)

clean:
	-rm -r -f   $(DEMOTARGET) *.o DOXYGENDOC  *.txt

doc:
	doxygen Doxyfile 


all:	$(DEMOTARGET)
	make clean && make main && make battleship

run:	main	
	./main
