#Makefile

readdir: readdirDriver.o readdir.o
	g++ readdirDriver.cpp readdir.h readdir.cpp -lstdc++fs -o ReadDir

clean:
	rm *.o

cleanclean: 
	rm *.o output.csv ReadDir

run:
	./ReadDir
