SRC := Process.cpp process_test.cpp
INC := ./ # Current directory
NAME := process_test
CC := g++
CFLAGS := -Wall -g

main: ${OBJ}
	${CC} ${CFLAGS} -o ${NAME} ${SRC} -I ${INC}

clean:
	rm -f *~
