CXXFLAGS:= -Wall -pedantic -MMD -MP

CXX  := g++
SRC  := simulation/Life.cpp simulation/life.cpp
OBJ  := $(SRC:.cpp=.o)
DEPS := $(OBJ:.o=.d)

bin/life.x: ${OBJ} | bin
	${CXX} ${CXXFLAGS} $^ -o $@

%.o: %.cpp
	${CXX} ${CXXFLAGS} $< -c -o $@

bin:
	mkdir -p bin

data:
	mkdir -p data

clean:
	rm -f ${OBJ} ${DEPS} bin/life.x

run: bin/life.x | data
	./bin/life.x ${ARGS}

-include ${DEPS}
