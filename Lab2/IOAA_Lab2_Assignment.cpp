/*
 1. Name: Kim, Jun
 2. Assignment: Assignment/Lab 2 Source Code Develping, Testing andSubmission
 3. Compiler used: CLion 2020.3.2
 4. Operating system used: Windows 10 Home 19041.804
 5. Date and time you ran your program successfully and no changes were made after that
    : final version was released at Mar.03,2021. It was successful.
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    //Input
    double Deposit;
    double Rate;
    int Compound;
    int Left;
    //output
    double Accumulation;
    int Dollars;
    int Cents;
    //computing variables
    double TotalPennies;
    int RoundedPennies;

    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Enter your Initial deposit or principal in decimalized fraction \nwithout $. ex) 1000.00 :";
    cin>>Deposit;
    cout<<"Enter your Annual interest rate in decimalized fraction \nwithout %. ex) 7.2 :";
    cin>>Rate;
    Rate=Rate/100;
    cout<<"Enter your Number of times the compounding is done per year :";
    cin>>Compound;
    cout<<"Enter your Number of years "<<Deposit<<"\nis left in deposit :";
    cin>>Left;
    Accumulation = Deposit * pow(1+Rate/Compound,double(Left*Compound));
    TotalPennies = Accumulation * 100;
    RoundedPennies = int(TotalPennies + 0.5);
    Dollars = RoundedPennies / 100;
    Cents = RoundedPennies % 100;
    cout<<"Initial deposit or principal = "<<Deposit<<" $"<<endl;
    cout<<"Annual interest rate = "<<Rate*100<<" %"<<endl;
    cout<<"Number of times the compounding is done per year = "<<Compound<<endl;
    cout<<"Number of years "<<Deposit<<" is left in deposit = "<<Left<<endl;
    cout<<"Total accumulation after "<<Left<<" years = "<<Accumulation<<" $"<<endl;
    cout<<"Your accumulation is: "<<Dollars<<" dollars and "<<Cents<<" cents."<<endl;
    cout<<"Thanks for using our system. \nGood Bye~!"<<endl;

    return 0;
}
