# COMP 2710 - Loan Payment Assignment Makefile

CC = g++
CFLAGS = -std=c++11 -Wall

DEPS = loan_payment.h
OBJ = main.o loan_payment.o

all: a.out

a.out: $(OBJ)
	$(CC) $(CFLAGS) -o a.out $(OBJ)

main.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -c main.cpp

loan_payment.o: loan_payment.cpp $(DEPS)
	$(CC) $(CFLAGS) -c loan_payment.cpp

run: a.out
	./a.out

clean:
	rm -f *.o a.out loan_payment