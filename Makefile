CC = c++
CFLAGS = -std=c++11
TARGET = hank

all: main.o geometry.o tga.o draw.o
	${CC} main.o geometry.o tga.o draw.o -o ${TARGET} ${CFLAGS}

main.o: main.cpp
	${CC} -c main.cpp -o main.o ${CFLAGS}

geometry.o: geometry.cpp
	${CC} -c geometry.cpp -o geometry.o ${CFLAGS}

tga.o: tga.cpp
	${CC} -c tga.cpp -o tga.o ${CFLAGS}

draw.o: draw.cpp
	${CC} -c draw.cpp -o draw.o ${CFLAGS}

clean:
	rm *.o
