#include <iostream>
#include <string>
#include <iomanip>
#include "loan_payment.h"

using namespace std;

return_months_and_payment calculate_months_loan_payment(double loan_amount, double yearly_interest_rate, double monthly_payment)
{
  // to return
  double month = 0;
  double cumulative_interest = 0;

  // variables
  double balance = loan_amount;
  double payment = monthly_payment;
  double rate = yearly_interest_rate / 12;
  double interest = 0;
  double principal = 0;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

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
  std::cout << "---------------------------------------------------------\n";
  std::cout << std::left << std::setw(8) << "0"
            << std::setw(14) << balance
            << std::setw(10) << "N/A"
            << std::setw(10) << "N/A"
            << std::setw(10) << "N/A"
            << std::setw(10) << "N/A" << "\n";

  while (balance > 0.0)
  {
    month++;
    interest = balance * rate * 0.01;
    principal = payment - interest;
    balance -= principal;
    balance = max(0.0, balance);
    cumulative_interest += interest;

    std::cout << std::left << std::setw(8) << month
              << std::setw(14) << balance
              << std::setw(10) << payment
              << std::setw(10) << rate
              << std::setw(10) << interest
              << std::setw(10) << principal << "\n";

    if (principal <= 0.0)
    {
      cout << "Payment Invalid!" << endl;
      return {month, cumulative_interest};
    }
    if (balance <= 0.0)
    {
      return {month, cumulative_interest};
    }
  }
  return {month, cumulative_interest};
}
