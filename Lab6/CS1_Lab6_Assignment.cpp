/*
1. Name: Kim, Jun
2. Assignment: CSCI 1 - Assignment 6: User Defined Functions
3. Compiler used: CLion 2021.1.1
4. Operating system used: macOS Big Sur 11.3
5. Date and time you ran your program successfully and no changes were made after that:
    final version was released at May.06,2021. It was successful.
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double socialTax = 0.071;
const int healthPremium = 200;
const string healthStatusTrue = "Employee opted for health insurance and was successfully registered.";
const string healthStatusFalse = "Employee opted for health insurance but was declined because of insufficient salary.";
const string healthStatusNone = "Employee did not opt to register in health plan.";

void greeting();
double getUserData(double & payRate, string & firstName, string & lastName, bool & healthPlan);
double getGrossSalary(double hoursWorked, double payRate);
double getTaxWithheld(double grossSalary);
double getNetSalary(double grossSalary, double taxWithheld, bool healthPlan, string & healthPlanStatusMessage);
void printResults(const string & firstName, const string & lastName, double hoursWorked, double payRate,
                  double grossSalary, double taxWithheld, double netSalary, const string & healthPlanStatus);
void goodbye();

int main() {
    string firstName;
    string lastName;
    double payRate;
    bool healthPlan;
    string healthPlanStatusMessage;
    string healthPlanStatus;

    greeting();
    double hoursWorked = getUserData(payRate, firstName, lastName, healthPlan);
    double grossSalary = getGrossSalary(hoursWorked, payRate);
    double taxWithheld = getTaxWithheld(grossSalary);
    double netSalary = getNetSalary(grossSalary, taxWithheld, healthPlan, healthPlanStatusMessage);
    healthPlanStatus = healthPlanStatusMessage;
    printResults(firstName, lastName, hoursWorked, payRate, grossSalary, taxWithheld, netSalary, healthPlanStatus);
    goodbye();

    return 0;
}

void greeting(){
    cout<<"---------------------------------------------------------------------"<<endl
        <<"Welcome to salary calculation program."<<endl
        <<"In this program we will ask for the information that would allow us to process your pay check."<<endl
        <<"We will collect information about hours worked, hourly pay rate and medical options."<<endl
        <<"Processing will be completed in just few minutes."<<endl
        <<"---------------------------------------------------------------------"<<endl;
}
double getUserData(double & payRate, string & firstName, string & lastName, bool & healthPlan){
    cout<<"Please enter your first name [One word only]: ";
    cin>>firstName;
    cout<<"Please enter your last name [One word only]: ";
    cin>>lastName;
    cout<<"Please enter hours worked (positive number only): ";
    int hoursWorked;
    cin>>hoursWorked;
    cout<<"Please enter your hourly pay rate. [For example enter 15.23 if your"<<endl
        <<"hourly pay rate is $15 and 23 cents: "<<endl;
    cin>>payRate;
    cout<<"Enter 1 to purchase health plan or 0 (zero) to decline: ";
    cin>>healthPlan;
    return hoursWorked;
}
double getGrossSalary(double hoursWorked, double payRate){
    double grossSalary;
    if (hoursWorked <= 40){
        grossSalary = hoursWorked * payRate;
    }else{
        grossSalary = (payRate * 40) + ((hoursWorked - 40) * (payRate * 1.5));
    }
    return grossSalary;
}
double getTaxWithheld(double grossSalary){
    double taxWithheld = grossSalary * socialTax;
    return taxWithheld;
}
double getNetSalary(double grossSalary, double taxWithheld, bool healthPlan, string & healthPlanStatusMessage){
    bool availableHealthPlan = (grossSalary - taxWithheld) > healthPremium;

    double netSalary;
    if (healthPlan){
        if (availableHealthPlan){
            netSalary = grossSalary - taxWithheld - healthPremium;
            healthPlanStatusMessage = healthStatusTrue;
        }else{
            netSalary = grossSalary - taxWithheld;
            healthPlanStatusMessage = healthStatusFalse;
        }
    }else{
        netSalary = grossSalary - taxWithheld;
        healthPlanStatusMessage = healthStatusNone;
    }
    return netSalary;
}
void printResults(const string & firstName, const string & lastName, double hoursWorked, double payRate,
                  double grossSalary, double taxWithheld, double netSalary, const string & healthPlanStatus){
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"---------------------------------------------------------------------"<<endl
        <<"Here are the Employee Payroll details."<<endl
        <<"Name: "<<firstName<<" "<<lastName<<endl
        <<"Hours worked: "<<hoursWorked<<" hours"<<endl
        <<"Hourly Pay Rate: $"<<payRate<<endl
        <<"Gross Salary: $"<<grossSalary<<endl
        <<"Tax withheld: $"<<taxWithheld<<endl
        <<healthPlanStatus<<endl
        <<"Employee net salary: $"<<netSalary<<endl;
}
void goodbye(){
    cout<<"---------------------------------------------------------------------"<<endl
        <<"Thank you for using our program."<<endl
        <<"Please have a pleasant day."<<endl;
}

/*
Output Example 1 is OK.
Output Example 2 is OK.
Output Example 3 is OK.
Output Example 4 is OK.
Output Example 5 is OK.
*/