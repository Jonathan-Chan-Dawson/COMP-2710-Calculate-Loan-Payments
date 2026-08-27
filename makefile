# COMP 2710 - Loan Payment Assignment Makefile

CC = g++
CFLAGS = -std=c++11 -Wall

DEPS = loan_payment.h
OBJ = main.o loan_payment.o

all: loan_payment

loan_payment: $(OBJ)
	$(CC) $(CFLAGS) -o loan_payment $(OBJ)

main.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -c main.cpp

loan_payment.o: loan_payment.cpp $(DEPS)
	$(CC) $(CFLAGS) -c loan_payment.cpp

clean:
	rm -f *.o loan_payment
