#Makefile

readdir: readdirDriver.o readdir.o
	g++ readdirDriver.cpp readdir.h readdir.cpp -lstdc++fs

clean:
	rm *.o *gch

cleanclean: 
	rm *.o *.gch output.csv a.out

run:
	./a.out
