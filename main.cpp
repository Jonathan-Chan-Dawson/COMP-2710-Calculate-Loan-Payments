#include <iostream>
#include <string>
#include <limits>
#include "loan_payment.h"

using namespace std;

int main()
{

	double loan_amount, yearly_interest_rate, monthly_payment;

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
	cout << "\nEnter Interest Amount: ";
	while (!(cin >> yearly_interest_rate) || yearly_interest_rate < 0)
	{
		cout << "(Invalid Interest Amount): " << yearly_interest_rate << ", Try Again!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This ignores the past input
		cout << "\nEnter Interest Amount: ";
	}

	// lastly, month payment amounts
	cout << "\nEnter Monthly Payment Amount: ";
	while (!(cin >> monthly_payment) || monthly_payment < 0)
	{
		cout << "(Invalid Month Payment Amount): " << monthly_payment << ", Try Again!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This ignores the past input
		cout << "\nEnter Month Payment Amount: ";
	}

	cout << "Inputted: \n"
			 << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << endl;

	// Next Step: More Loan Payment Info #AuraFarm
	int monthsToPayment = calculate_months_loan_payment(loan_amount, yearly_interest_rate, monthly_payment);

	cout << "From Inputted: \n"
			 << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << "\n"
			 << "Months to Complete Payment = " << monthsToPayment << endl;
}
