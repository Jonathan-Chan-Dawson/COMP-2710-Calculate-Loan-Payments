#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int calculate_months_loan_payment(double loan_amount, double yearly_interest_rate, double monthly_payment)
{
  int month = 0;
  int balance = loan_amount;
  int payment = monthly_payment;
  int rate = yearly_interest_rate / 12;
  int interest = 0;
  int principal = 0;

  cout << endl;
  cout << "****************************************************\n"
       << "\t\tAmortization Table\n"
       << "****************************************************\n";

  std::cout << std::left << std::setw(8) << "Month"
            << std::setw(14) << "Balance"
            << std::setw(10) << "Payment"
            << std::setw(10) << "Rate"
            << std::setw(10) << "Interest"
            << std::setw(10) << "Principal" << "\n";
  std::cout << "------------------------------------------------------------------------\n";
  std::cout << std::left << std::setw(8) << "0"
            << std::setw(13) << "N/A"
            << std::setw(9) << "N/A"
            << std::setw(9) << "N/A"
            << std::setw(9) << "N/A"
            << std::setw(9) << "N/A" << "\n";
  while (balance > 0)
  {
    month++;
    interest = balance * rate * 0.01;
    principal = payment - interest;
    balance -= max(0, principal);

    std::cout << std::left << std::setw(8) << month
              << std::setw(13) << balance
              << std::setw(9) << payment
              << std::setw(9) << rate
              << std::setw(9) << interest
              << std::setw(9) << principal << "\n";

    if (principal <= 0)
    {
      cout << "Payment Invalid!" << endl;
      return month;
    }
  }
  return month;
}
