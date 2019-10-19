CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o outputLetters.o countLetters.o
SRCS = main.cpp outputLetters.cpp countLetters.cpp
HEADERS = outputLetters.hpp countLetters.cpp
OUTPUT = generate-trigram-map

TITLE = generate-trigram-map

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${OUTPUT}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

valgrind:
	valgrind --leak-check=full ./${OUTPUT}

zip:
	zip ${TITLE}.zip *.cpp *.hpp Makefile input.txt

clean:
	rm -rf *.o *.dSYM ${OUTPUT}