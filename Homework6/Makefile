CXX = g++
OBJ_FLAGS = -c -fPIC

PROJECT_NAME = homework_6

all: Heap.o main.o
	$(CXX) $^ -o $(PROJECT_NAME)

Heap.o: Heap/Heap.cpp
	$(CXX) $(OBJ_FLAGS) $<

main.o: main.cpp
	$(CXX) $(OBJ_FLAGS) $<

clean:
	rm -rfv *.o ./$(PROJECT_NAME)
