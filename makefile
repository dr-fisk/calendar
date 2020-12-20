EXEC = calendar.out
OBJS = appt.o calendar.o day.o DayOfWeek.o main.o time.o weeklyappointment.o

CC = g++

COMPILER_FLAGS = -ansi -Wall

LINKER_FLAGS = -std=c++14

calendar.out : $(OBJS)
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC) $(OBJS)

appt.o : appt.cpp appt.h time.h 
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c appt.cpp
 
 weeklyappointment.o: weeklyappointment.cpp weeklyappointment.h appt.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c weeklyappointment.cpp

calendar.o : calendar.cpp calendar.h day.h vector.h vector.cpp
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c calendar.cpp

day.o : day.cpp day.h appt.h DayOfWeek.h linkedlist.cpp linkedlist.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c day.cpp

DayOfWeek.o : DayOfWeek.cpp DayOfWeek.h  
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c DayOfWeek.cpp

main.o : main.cpp calendar.h appt.h 
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c main.cpp

time.o : time.cpp time.h 
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c time.cpp

clean : 
	rm -f $(OBJS)
