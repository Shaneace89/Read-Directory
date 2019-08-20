#Makefile

readdir: readdirDriver.o readdir.o
	g++ readdirDriver.cpp readdir.h readdir.cpp -lstdc++fs -o ReadDir

clean:
	rm *.o *.gch

cleanclean: 
	rm *.o *.gch output.csv ReadDir

run:
	./ReadDir
