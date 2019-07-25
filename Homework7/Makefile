CXX = g++
PROJECT_NAME = homework_7

OBJ_FLAGS = -c -fPIC
EXEC_FLAGS = -o

all: MyArray.o MyType.o main.o
	$(CXX) $^ $(EXEC_FLAGS) $(PROJECT_NAME)

MyArray.o: MyArray/MyArray.cpp
	$(CXX) $(OBJ_FLAGS) $<

MyType.o: MyType/MyType.cpp
	$(CXX) $(OBJ_FLAGS) $<

main.o: main.cpp
	$(CXX) $(OBJ_FLAGS) $<

clean:
	rm -rfv *.o ./$(PROJECT_NAME)
