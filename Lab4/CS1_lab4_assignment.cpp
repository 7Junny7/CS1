/*
1. Name: Kim, Jun
2. Assignment: Assignment/Lab 4 More Advanced Selection Structure
3. Compiler used: CLion 2020.3.2
4. Operating system used: macOS Big Sur 11.2.2
5. Date and time you ran your program successfully and no changes were made after that:
    final version was released at Mar.29,2021. It was successful.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string nameFirst,       //First name
           nameLast,        //Last name
           nameEmployee;    //Employee Description depending on Employee Code
    char codeEmployee;      //Employee Code (S, O, or M)
    int ID,                 //User ID
        codeJob,            //Job classification (1, 2, or 3)
        serviceYear,        //Years of service (allow less than 50)
        codeEducation;      //Educational code (1, 2, 3, or 4)
    bool flagEmp = true,    //Checking codeEmployee is valid
         flagJob = true,    //Checking codeJob is valid
         flagYear = true,   //Checking serviceYear is valid
         flagEdu = true;    //Checking code Education is valid

    double salaryBase,      //Base Pay
           incJob,          //Additions by Job Classification
           incYear,         //Additions by Years of Service
           incEdu;          //Additions by Educational Code

    cout<<"In a row, the Data Set order is below \n"
        <<"first name, last name, Employee code, ID, Job classification code, \n"
        <<"years of service, education code."<<endl;
    cin>>nameFirst>>nameLast>>codeEmployee>>ID>>codeJob>>serviceYear>>codeEducation;

    //Base Pay for various Employee Codes
    if (codeEmployee == 'S'){
        salaryBase = 800.95;
        nameEmployee = "Factory Worker";
    }else if (codeEmployee == 'O'){
        salaryBase = 1000.86;
        nameEmployee = "Office Worker";
    }else if (codeEmployee == 'M'){
        salaryBase = 1499.89;
        nameEmployee = "Management";
    }else{
        cout<<"Employee code is invalid."<<endl;
        flagEmp = false;
    }

    //Additions to base pay due to Job Classification
    if (codeJob == 1){
        incJob = salaryBase * 0.05;
    }else if (codeJob == 2){
        incJob = salaryBase * 0.1;
    }else if (codeJob == 3){
        incJob = salaryBase * 0.2;
    }else{
        cout<<"Job Classification is invalid."<<endl;
        flagJob = false;
    }

    //Additions to salary due to Years of Service
    if (serviceYear >= 0 && serviceYear <= 10){
        incYear = salaryBase * 0.05;
    }else if (serviceYear > 10 && serviceYear <= 50){
        incYear = (salaryBase * 0.05) + (salaryBase * 0.01 * (serviceYear - 10));
    }else{
        cout<<"Years of services is invalid."<<endl;
        flagYear = false;
    }

    //Additions to salary due to educational code
    if (codeEducation == 1){
        incEdu = 0;
    }else if (codeEducation == 2){
        incEdu = salaryBase * 0.05;
    }else if (codeEducation == 3){
        incEdu = salaryBase * 0.12;
    }else if (codeEducation == 4){
        incEdu = salaryBase * 0.2;
    }else{
        cout<<"Education code is invalid."<<endl;
        flagEdu = false;
    }

    if (flagEmp && flagJob && flagYear && flagEdu) {
        double salary = salaryBase + incJob + incYear + incEdu;
        string nameUser = nameFirst + " " + nameLast;

        cout << fixed << showpoint << setprecision(2);
        cout << left << setw(20) << "Name" << setw(20) << "ID#"
             << setw(20) << "Job Type" << setw(20) << "Gross Salary ($)"
             << endl
             << "----------------------------------------------------------------------------"
             << endl;
        cout << setw(20) << nameUser << setw(20) << ID
             << setw(20) << nameEmployee <<"$"<< setw(20) <<salary << endl;
    }


    return 0;
}
