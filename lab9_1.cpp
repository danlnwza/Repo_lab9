#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    double loan, interestRate, payPerYear;

    cout << "Enter initial loan: ";
    cin >> loan;
    cout << "Enter interest rate per year (%): ";
    cin >> interestRate;
    cout << "Enter amount you can pay per year: ";
    cin >> payPerYear;

    cout << left << setw(13) << "EndOfYear#" 
         << setw(13) << "PrevBalance" 
         << setw(13) << "Interest" 
         << setw(13) << "Total" 
         << setw(13) << "Payment" 
         << "NewBalance" << endl;

    cout << fixed << setprecision(2);

    double prevBalance = loan;
    int year = 1;

    while (prevBalance > 0) {
        double interest = prevBalance * (interestRate / 100.0);
        double total = prevBalance + interest;
        double payment;

        
        if (total < payPerYear) {
            payment = total; 
        } else {
            payment = payPerYear ;
        }

        double newBalance = total - payment;


        cout << left << setw(13) << year
             << setw(13) << prevBalance
             << setw(13) << interest
             << setw(13) << total
             << setw(13) << payment
             << newBalance << endl;


        prevBalance = newBalance;
        year++;
        

        if (interest >= payPerYear && prevBalance > 0) {
            break; 
        }
    }

    return 0;
}