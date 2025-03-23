//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Hannah Rhode> on <3/23/2025>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//function prototype
double getPayment(int, double, int);
double calculateSimplePayment(int, double, int);
//monthly user payment
double getPayment(int amount, double rate, int months)
{
  //if months is 0, return -1
  if (months == 0)
    return -1;
  double interest = amount * rate * months / (100);
  double total = amount + interest;
  return total / months;
}
double calculateSimplePayment(int amount, double rate, int months)
{
    //calculates and returns a monthly payment
    double monthPay = 0.0;
    double denominator = 1 - pow(rate + 1, -months);
    
    // Check if denominator is zero
    if (abs(denominator) < 1e-10) {
        return -1; // Return error value
    }
    
    monthPay = amount * rate / denominator;
    return monthPay;
} 
int main()
{
    //declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;
    //call function to calculate payments
    creditPayment = calculateSimplePayment(carPrice - rebate,
        creditRate / 12, term * 12);
    dealerPayment = calculateSimplePayment(carPrice, 
        dealerRate / 12, term * 12);

    //display payments
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union payment [Monthly]: $" 
        << creditPayment << endl;
    cout << "Credit union payment [Total]: $"
        << creditPayment * term * 12 << endl;
    cout << "Dealer payment [Monthly]: $"
        << dealerPayment << endl;
    cout << "Dealer payment [Total]: $"
        << dealerPayment * term * 12 << endl;
    return 0;
}