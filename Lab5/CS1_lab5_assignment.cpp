/*
1. Name: Kim, Jun
2. Assignment: Assignment/Lab 5 Nested Loop and Nested If/Else
3. Compiler used: CLion 2021.1
4. Operating system used: macOS Big Sur 11.2.3
5. Date and time you ran your program successfully and no changes were made after that:
    final version was released at Apr.20,2021. It was successful.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

const double belowOne = 0.00,          //Fine, <=1
             oneToThree = 1000000.00,   //Fine, >1 but <=3
             threeToFive = 2000000.00,  //Fine, >3 but <=5
             fiveToSeven = 3000000.00,  //Fine, >5 but <=7
             overSeven = 4500000.00;   //Fine, >7
int main() {
    string fileIn = "",     //Full path of input file
           fileOut = "";    //Full path of output file

    cout<<"Welcome to El Camino Software Engineering Lab."<<endl
        <<"We will calculate average carbon footprint and corresponding fine."<<endl
        <<"Please be ready to provide the data file name for carbon FP for US cities."<<endl;

    cout<<"Please enter the full path of input data file name: ";
    getline(cin,fileIn);
    ifstream in(fileIn);
    if(in.is_open()){
        cout<<"Please provide full path to output file: ";
        getline(cin,fileOut);
        ofstream out(fileOut);
        if(out.is_open()){
            int totalCities = 0;    //Total number of cities in the file
            double totalFine = 0.0; //Total collected fine from cities

            out<<"Welcome to El Camino Software Engineering Lab."<<endl
                <<"We will calculate average carbon footprint and corresponding fine."<<endl;

            cout<<fixed<<showpoint<<setprecision(2);
            out<<fixed<<showpoint<<setprecision(2);
            cout<<"***********************************************************************"<<endl;
            out<<"***********************************************************************"<<endl;
            cout<<left<<setw(15)<<"City"<<setw(35)<<"Rounded Average Carbon FP"
                <<setw(15)<<"Fine ($)"<<endl;
            out<<left<<setw(15)<<"City"<<setw(35)<<"Rounded Average Carbon FP"
                <<setw(15)<<"Fine ($)"<<endl;
            cout<<"***********************************************************************"<<endl;
            out<<"***********************************************************************"<<endl;
            while(in.peek() != EOF){
                totalCities++;
                string nameCity = "";   //Name of the city in each row
                in>>nameCity;

                int averageCarbon = 0;  //Rounded average carbon FP
                double fine = 0.0;      //Amount of fine
                int oneCarbon = 0,      //Reading carbon foot print value
                    sumCarbon = 0,      //Sum of all oneCarbon
                    countCarbon = 0;    //total number of oneCarbon
                in>>oneCarbon;
                while(oneCarbon >= 0){
                    sumCarbon+=oneCarbon;
                    countCarbon++;
                    in>>oneCarbon;
                }
                averageCarbon = round(sumCarbon/static_cast<double>(countCarbon));

                if(averageCarbon <= 0){
                    cout<<left<<setw(15)<<nameCity<<setw(35)
                        <<"No value available for carbon FP. Fine not calculated."<<endl;
                    out<<left<<setw(15)<<nameCity<<setw(35)
                        <<"No value available for carbon FP. Fine not calculated."<<endl;
                }else{
                    if(averageCarbon <= 1){
                        fine = belowOne;
                    }else if(averageCarbon > 1 && averageCarbon <= 3){
                        fine = oneToThree;
                    }else if(averageCarbon > 3 && averageCarbon <= 5){
                        fine = threeToFive;
                    }else if(averageCarbon > 5 && averageCarbon <= 7){
                        fine = fiveToSeven;
                    }else{
                        fine = overSeven;
                    }
                    cout<<left<<setw(15)<<nameCity<<setw(35)<<averageCarbon<<setw(15)<<fine<<endl;
                    out<<left<<setw(15)<<nameCity<<setw(35)<<averageCarbon<<setw(15)<<fine<<endl;
                    totalFine+=fine;
                }
            }
            cout<<"***********************************************************************"<<endl;
            out<<"***********************************************************************"<<endl;
            cout<<"Total number of cities in the file = "<<totalCities<<endl
                <<"Total fine collected: $"<<totalFine<<endl
                <<"Thank you for using El Camino Software Engineering Lab."<<endl;
            out<<"Total number of cities in the file = "<<totalCities<<endl
                <<"Total fine collected: $"<<totalFine<<endl
                <<"Thank you for using El Camino Software Engineering Lab."<<endl;
        }
        else{
            cout<<"Error opening output file. File either does not exist or has no read permission."<<endl
                <<"Thank you for using El Camino Software Engineering Lab."<<endl;
        }
        out.close();
    }else{
        cout<<"Error opening input file. File either does not exist or has no read permission."<<endl
            <<"Thank you for using El Camino Software Engineering Lab."<<endl;
    }
    in.close();

    return 0;
}
