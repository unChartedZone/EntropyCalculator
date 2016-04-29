TORM = entropy_calculator.o entropy_calculator
CC = g++
CCFLAGS = -g -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings

entropy_calculator: entropy_calculator.o
	${CC} ${CCFLAGS} -o entropy_calculator entropy_calculator.o

entropy_calculator.o:	entropy_calculator.cpp entropy_calculator.h entropy_error.h
		${CC} ${CCFLAGS} -c entropy_calculator.cpp

clean:
	rm -f ${TORM}
