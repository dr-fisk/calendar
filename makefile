OBJS = main.cpp calendar.cpp day.cpp appt.cpp time.cpp dayofweek.cpp linkedlist.cpp

CC = g++

COMPILER_FLAGS = -Wall 

LINKER_FLAGS = -std=c++14

OBJ_NAME = calendar.out

all:
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm $(OBJ_NAME)
