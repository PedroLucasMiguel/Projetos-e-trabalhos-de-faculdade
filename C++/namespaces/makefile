out: main.o printzaoshow.o
	g++ main.o printzaoshow.o -o out

main.o: main.cpp
	g++ -c main.cpp

printzaoshow.o: printzaoshow.cpp
	g++ -c printzaoshow.cpp

clean:
	rm *.o out