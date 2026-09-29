# COMP 2710 - Loan Payment Assignment Makefile

CC = g++

OBJ = main.o loan_payment.o
DEPS = loan_payment.h

all: a.out
 
a.out: $(OBJ)
	$(CC) -o a.out $(OBJ)

main.o: main.cpp $(DEPS)
	$(CC) -c main.cpp

loan_payment.o: loan_payment.cpp $(DEPS)
	$(CC) -c loan_payment.cpp

run: a.out
	./a.out

clean:
	rm -f *.o a.out 