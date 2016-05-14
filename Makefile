
CC=g++
test:main.o
	$(CC) -o $@ $^ 
main.o:main.cpp
	$(CC) -c  $< -g
.PHONY:clean
clean:
	rm -f *.o test
