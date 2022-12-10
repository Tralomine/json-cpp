COMP := g++

all:
	$(COMP) -c json.cpp -o json.o -Wall -Wextra -Werror -Wpedantic
	$(COMP) -c main.cpp -o main.o
	$(COMP) main.o json.o -o a.out

debug:
	$(COMP) -g -c json.cpp -o json.o -Wall
	$(COMP) -g -c main.cpp -o main.o
	$(COMP) -g main.o json.o -o a.out

clean:
	rm *.o
