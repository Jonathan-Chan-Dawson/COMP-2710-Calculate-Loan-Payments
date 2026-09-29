#include <iostream>
#include <string>
#include <limits>
#include "loan_payment.h"

using namespace std;

int main()
{
	double loan_amount, yearly_interest_rate, monthly_payment;

	// keep decimal a precision of 2 points
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// for inputs: must be greater than 0, must have an input value
	// loan amounts
	cout << "\nEnter Loan Amount: ";
	while (!(cin >> loan_amount) || loan_amount < 0)
	{
		cout << "(Invalid Loan amount): " << loan_amount << ", Try Again!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This ignores the past input
		cout << "\nEnter Loan Amount: ";
	}

	// try the interest amounts
	cout << "\nEnter Interest Amount (%): ";
	while (!(cin >> yearly_interest_rate) || yearly_interest_rate < 0)
	{
		cout << "(Invalid Interest Amount): " << yearly_interest_rate << ", Try Again!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This ignores the past input
		cout << "\nEnter Interest Amount (%): ";
	}

	// lastly, month payment amounts
	cout << "\nEnter Monthly Payment Amount: ";

	// this tests if the principal less than 0 from monthly payments
	// probably not needed
	int interest = loan_amount * (yearly_interest_rate / 12) * 0.01;
	int principal = monthly_payment - interest;

	while (!(cin >> monthly_payment) || monthly_payment < 0 || principal <= 0) // probably redundant
	{
		interest = loan_amount * (yearly_interest_rate / 12) * 0.01;
		principal = monthly_payment - interest;

		if (monthly_payment < 0)
			cout << "(Invalid Month Payment Amount): " << monthly_payment << ", Try Again! \n";
		else if (principal <= 0)
			cout << "(You Didn't Pay Enough Money For Your Loan!): " << monthly_payment << ", Try Again! \n";
		else
			break;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This ignores the past input
		cout << "\nEnter Monthly Payment Amount: ";
	}

	cout << "Inputted: \n"
			 << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << endl;

	// Next Step: More Loan Payment Info #AuraFarm
	int monthsToPayment = calculate_months_loan_payment(loan_amount, yearly_interest_rate, monthly_payment);

	cout << "From Inputted: \n"
			 << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << "\n"
			 << "Months to Complete Payment = " << monthsToPayment << endl;
}
