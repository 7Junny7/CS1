/*
1. Name: Kim, Jun
2. Assignment: Assignment 1: Computation of burning calories
3. Compiler used: CLion 2020.3.2
4. Operating system used: macOS Big Sur 11.2.1
5. Date and time you ran your program successfully and no changes were made after that
    : final version was released at 23Feb2021. It was successful.
*/

#include <iostream>
using namespace std;

int main() {
    double Weight;
    double Height;
    int Age;
    double ActivityFactor;
    double BMR;
    double CaloriesBurnt;

    cout<<"To advance your health we will calculate as to how much calories did you burn today."<<endl;
    cout<<"We will need data on your weight, height, and age and what kind of activity you do."<<endl;
    cout<<"All your information will be kept confidential and no salesman will call."<<endl;
    cout<<"Please enter your weight in pounds[xx.xx] and then press enter key: ";
    cin>>Weight;
    cout<<"Please enter your height in feet[xx.xx] and then press enter key: ";
    cin>>Height;
    cout<<"Please enter your age in years [xx] and press enter key: ";
    cin>>Age;
    cout<<"These are the activity numbers for your life style. Please enter just one of them."<<endl;
    cout<<"If you have a desk job and do no exercises then enter 1.2"<<endl;
    cout<<"If you do light exercise 1 to 3 days a week then enter 1.375"<<endl;
    cout<<"If you do moderate exercises 3 to 5 times a week enter 1.55"<<endl;
    cout<<"If you do hard exercises 6 to 7 days a week, enter 1.725"<<endl;
    cout<<"If you train hard in sports twice a day enter 1.9 : "<<endl;
    cin>>ActivityFactor;
    BMR = 66+6.2*Weight+152.4*Height-6.8*Age;
    CaloriesBurnt = BMR * ActivityFactor;
    cout<<"********************************************************"<<endl;
    cout<<"Here are the results from our computation."<<endl;
    cout<<"********************************************************"<<endl;
    cout<<"You burn "<<CaloriesBurnt<<" calories every day."<<endl;
    cout<<"If your calorie intake per day is more than this number then"<<endl;
    cout<<"you may wish to include more exercises in your daily life."<<endl;
    cout<<"Alternatively you may wish to cut down on your calorie intake as well."<<endl;
    cout<<"*****************************************************************************************"<<endl;
    cout<<"Here are the calories in some of the popular foods: "<<endl;
    cout<<"One Doughnut has about 250 to 300 calories."<<endl;
    cout<<"One butter croissant has about 272 calories."<<endl;
    cout<<"One piece of cheesecake has about 260 calories."<<endl;
    cout<<"One Danish pastry has about 353 calories."<<endl;
    cout<<"One bagel has about 156 calories."<<endl;
    cout<<"*****************************************************************************************"<<endl;
    cout<<"Thanks for using El Camino college calorie calculation program."<<endl;

    return 0;
}
