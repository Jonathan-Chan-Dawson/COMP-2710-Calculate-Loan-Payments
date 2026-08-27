#include <iostream>
#include <string>
#include <loan_payment.cpp>

using namespace std;

int main()
{

	int i = 1;
	double loan_amount, yearly_interest_rate, monthly_payment;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// loan amounts
	cout << "\nEnter Loan Amount: ";
	cin >> loan_amount;
	while (!(cin >> loan_amount) || loan_amount < 0)
	{
		cout << "(Invalid Loan amount): " << loan_amount << ", Try Again!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input from the buffer
		cout << "\nEnter Loan Amount: ";
	}

	// try the interest amounts
	cout << "\nEnter Interest Amount: ";
	cin >> yearly_interest_rate;
	while (!(cin >> yearly_interest_rate) || yearly_interest_rate < 0)
	{
		cout << "(Invalid Interest Amount): " << yearly_interest_rate << ", Try Again!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input from the buffer
		cout << "\nEnter Interest Amount: ";
	}

	// lastly, month payment amounts
	cout << "\nEnter Monthly Payment Amount: ";
	cin >> monthly_payment;
	while (!(cin >> monthly_payment) || monthly_payment < 0)
	{
		cout << "(Invalid Month Payment Amount): " << monthly_payment << ", Try Again!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input from the buffer
		cout << "\nEnter Month Payment Amount: ";
	}

	cout << "\n"
			 << loan_amount << " " << yearly_interest_rate << " " << monthly_payment << endl;

	// Next Step: Add Here!! More Loan Payment Info #AuraFarm
	int grade;
	cin >> grade;
	if (grade <= 100 && grade >= 90)
		cout << "Grade = A";
	if (grade <= 89 && grade >= 80)
		cout << "Grade = B";
	if (grade <= 79 && grade >= 0)
		cout << "Grade = C";
	return;
	return calculate_months_loan_payment(loan_amount, yearly_interest_rate, monthly_payment);
}
