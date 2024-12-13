#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    
    double loanAmount, interestRate, yearlyPayment;

    
    cout << "Enter initial loan: ";
    cin >> loanAmount;
    cout << "Enter interest rate per year (%): ";
    cin >> interestRate;
    cout << "Enter amount you can pay per year: ";
    cin >> yearlyPayment;

    
    cout << setw(13) << left << "EndOfYear#"
         << setw(13) << left << "PrevBalance"
         << setw(13) << left << "Interest"
         << setw(13) << left << "Total"
         << setw(13) << left << "Payment"
         << setw(13) << left << "NewBalance" << endl;

    cout << fixed << setprecision(2);

    
    int year = 0;
    double prevBalance = loanAmount;
    double interest, total, newBalance;

    while (prevBalance > 0) {
        year++;
        interest = (prevBalance * interestRate) / 100;
        total = prevBalance + interest; 

        
        double payment = (total < yearlyPayment) ? total : yearlyPayment;
        newBalance = total - payment; 

        
        cout << setw(13) << left << year
             << setw(13) << left << prevBalance
             << setw(13) << left << interest
             << setw(13) << left << total
             << setw(13) << left << payment
             << setw(13) << left << newBalance << endl;

        
        prevBalance = newBalance;

        
        if (newBalance <= 0) break;
    }

    return 0;
}
