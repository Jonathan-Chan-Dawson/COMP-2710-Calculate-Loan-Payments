#ifndef LOAN_PAYMENT_H
#define LOAN_PAYMENT_H

#include <iostream>

// Function declaration
struct return_months_and_payment
{
  double months;
  double interest_paid;

  void printResult()
  {
    std::cout << months << " months and $" << interest_paid << " interest" << std::endl;
  }
};

return_months_and_payment calculate_months_loan_payment(double loan_amount, double yearly_interest_rate, double monthly_payment);

#endif
