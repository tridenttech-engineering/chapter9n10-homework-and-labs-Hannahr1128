//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Hannah Rhode> on <3/23/2025>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);

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
    double totalCreditPayment = 0.0;
    double totalDealerPayment = 0.0;

    //get inputs
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
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);
    totalCreditPayment = creditPayment * 48;
    totalDealerPayment = dealerPayment * 48;;

    //display payments
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;
    cout << "\nTotal amount if financed through credit union: $" << totalCreditPayment << endl;
    cout << "Total amount if financed through dealer: $" << totalDealerPayment << endl;
return 0;
} //end of main function

//*****function definitions*****
double getPayment(int prin, double monthRate, int months)
{
    //calculates and return a monthly payment
    double monthPay = 0.0;
    monthPay = (prin * monthRate) / (1.0 - pow(1.0 + monthRate, -months));
    return monthPay;
} //end of getPayment function