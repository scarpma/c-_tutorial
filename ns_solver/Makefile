CC=g++
CCFLAGS=-std=c++11 -I/opt/homebrew/Cellar/boost/1.80.0/include

main: main.cpp grid.o vtkHelper.o
	${CC} ${CCFLAGS} main.cpp grid.o vtkHelper.o -o main

grid.o: grid.cpp
	${CC} ${CCFLAGS} -c grid.cpp

vtkHelper.o: vtkHelper.cpp
	${CC} ${CCFLAGS} -c vtkHelper.cpp

clean:
	rm *.o main

.PHONY: clean
