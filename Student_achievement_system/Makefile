CC=gcc
STD=-std=gnu99
BIN=System.bin
FLAG=-Wall  
OBJ=main.o system.o  tools.o principal.o teacher.o student.o  

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ)

main.o:main.c system.h
	$(CC) $(STD) $(FLAG) -c main.c
system.o:system.c system.h teacher.h student.h principal.h tools.h
	$(CC) $(STD) $(FLAG) -c system.c
principal.o:principal.c principal.h system.h teacher.h tools.h 
	$(CC) $(STD) $(FLAG) -c principal.c
teacher.o:teacher.c teacher.h system.h tools.h 
	$(CC) $(STD) $(FLAG) -c teacher.c
student.o:student.c student.h system.h tools.h  
	$(CC) $(STD) $(FLAG) -c student.c
tools.o:tools.c tools.h system.h
	$(CC) $(STD) $(FLAG) -c tools.c
	
clean:
	rm -rf $(BIN) $(OBJ)
