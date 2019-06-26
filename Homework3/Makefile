CC = g++
OBJ_FLAGS = -c -fPIC

PROJECT_NAME = homework_2

ALL_OBJ = hello.o here.o bye.o main.o
FILES_OBJ = hello.o here.o bye.o

ALL_SRC = $(ALL_O:.o=.cpp)
FILES_SRC = $(FILES_O:.o=.cpp)


all: libs
	$(CC) $(ALL_OBJ) -o $(PROJECT_NAME)

main.o: main.cpp
	$(CC) $(OBJ_FLAGS) $<

hello.o: hello.cpp
	$(CC) $(OBJ_FLAGS) $<

here.o: here.cpp
	$(CC) $(OBJ_FLAGS) $<

bye.o: bye.cpp
	$(CC) $(OBJ_FLAGS) $<

libs: mylib.a libmylib.so

mylib.a: $(ALL_OBJ)
	ar rcs $@ $^

libmylib.so: $(FILES_OBJ)
	$(CC) -shared $^ -o $@ -Wl,--whole-archive -Wl,--no-whole-archive

clean:
	rm -fv *.o *.a  *.so ./homework_2
