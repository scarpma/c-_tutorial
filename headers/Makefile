CC="g++"
CCFLAGS="-std=c++11"

main: main.cpp csv.o
	${CC} ${CCFLAGS} main.cpp csv.o -o main

csv.o: csv.cpp
	${CC} ${CCFLAGS} -c csv.cpp

clean:
	rm *.o main

.PHONY: clean
