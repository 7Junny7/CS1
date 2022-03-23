/*
1. Name: Kim, Jun
2. Assignment: CSCI 1 - Test 2
3. Compiler used: CLion 2021.1.1
4. Operating system used: macOS Big Sur 11.3
5. Date and time you ran your program successfully and no changes were made after that:
    final version was released at Apr.30,2021. It was successful.
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const double SIZE_S{1.03},  //Six Inch
             SIZE_T{2.11},  //Twelve Inch
             SIZE_E{3.39},  //Eighteen Inch
             SIZE_F{4.11};  //Two Feet
const double FLOUR_ORG_WHEAT{0.1011},   //Organic Wheat
             FLOUR_MULTI{0.1555},       //Multigrain
             FLOUR_ORG_MULTI{0.2012};   //Organic Multigrain
const double FILLING_ARTICHOKES{0.50},          //Artichokes
             FILLING_ARTICHOKES_PCT_BASE{0.101},
             FILLING_JALAPENOS{0.25},           //Jalapenos
             FILLING_JALAPENOS_PCT_BASE{0.155},
             FILLING_EXTRA_CHEESE{0.30},        //Extra Cheese
             FILLING_EXTRA_CHEESE_PCT_BASE{0.113};
const double SALES_TAX{0.101};  //Sales tax


int main() {
    string first,       //First name
           last;        //Last name

    cout<<"Please enter your first and last names in that order: "<<endl;
    cin>>first>>last;
    cout<<"Hello "<<first<<" "<<last<<endl
        <<"Welcome to subway sandwich store."<<endl;

    //Inputting sandwich size
    cout<<"Please enter sandwich size: [S]ix inch, [T]welve inch, [E]ighteen inch, or Two [F]eet: ";
    char size;          //sandwich size
    cin>>size;
    bool flagSize = (size == 'S' || size == 'T' || size == 'E' || size == 'F');

    //Inputting Flour type
    cout<<"Enter 1 for wheat flour bread"<<endl
        <<"Enter 2 for organic wheat flour bread"<<endl
        <<"Enter 3 for multi grain bread"<<endl
        <<"Enter 4 for organic multigrain bread: ";
    int flourType;      //Flour for sandwich bread
    cin>>flourType;
    bool flagFlour = (flourType == 1 || flourType == 2 || flourType == 3 || flourType == 4);

    //Inputting Filling type
    cout<<"Enter 1 for cheese filling"<<endl
        <<"Enter 2 for artichokes filling"<<endl
        <<"Enter 3 for Jalapenos filling"<<endl
        <<"Enter 4 for extra cheese filling"<<endl
        <<"Enter 5 for all fillings that we offer: ";
    int fillingType;    //Filling inside the sandwich
    cin>>fillingType;
    bool flagFilling = (fillingType == 1 || fillingType == 2 || fillingType == 3 || fillingType == 4 || fillingType == 5);

    if (flagSize && flagFlour && flagFilling){
        double baseCost,    //Base cost of the sandwich
               incrFlour,   //Extra cost due to flour type
               incrFilling; //Extra cost due to fillings

        //Checking base cost
        if (size == 'S'){
            baseCost = SIZE_S;
        }else if (size == 'T'){
            baseCost = SIZE_T;
        }else if (size == 'E'){
            baseCost = SIZE_E;
        }else{
            baseCost = SIZE_F;
        }
        //Checking extra cost for flour type
        if (flourType == 1){
            incrFlour = 0;
        }else if (flourType == 2){
            incrFlour = baseCost * FLOUR_ORG_WHEAT;
        }else if (flourType == 3){
            incrFlour = baseCost * FLOUR_MULTI;
        }else{
            incrFlour = baseCost * FLOUR_ORG_MULTI;
        }
        //Checking extra cost for filling
        if (fillingType == 1){
            incrFilling = 0;
        }else if (fillingType == 2){
            incrFilling = FILLING_ARTICHOKES + (baseCost * FILLING_ARTICHOKES_PCT_BASE);
        }else if (fillingType == 3){
            incrFilling = FILLING_JALAPENOS + (baseCost * FILLING_JALAPENOS_PCT_BASE);
        }else if (fillingType == 4){
            incrFilling = FILLING_EXTRA_CHEESE + (baseCost * FILLING_EXTRA_CHEESE_PCT_BASE);
        }else{
            incrFilling = FILLING_ARTICHOKES + (baseCost * FILLING_ARTICHOKES_PCT_BASE)
                        + FILLING_JALAPENOS + (baseCost * FILLING_JALAPENOS_PCT_BASE)
                        + FILLING_EXTRA_CHEESE + (baseCost * FILLING_EXTRA_CHEESE_PCT_BASE);
        }

        //Calculating price
        double totalCost;    //Total raw cost including tax
        int    totalPennies, //Final cost in rounded pennies
               dollars,      //Whole dollars portion of the cost
               cents;        //Whole cents portion of cost
        totalCost = (baseCost + incrFlour + incrFilling) * (1 + SALES_TAX);
        totalPennies = static_cast<int>((totalCost * 100)+0.5);
        dollars = totalPennies / 100;
        cents = totalPennies % 100;

        cout<<fixed<<showpoint<<setprecision(2);
        cout<<"Total cost for your sandwich is: "<<dollars<<" dollars and "<<cents<<" cents.";
    }else{
        cout<<"We are unable to process your order due to following reasons."<<endl;
        if (!flagSize){
            cout<<"Invalid sandwich size was specified."<<endl;
        }
        if (!flagFlour){
            cout<<"Invalid flour code was entered."<<endl;
        }
        if (!flagFilling){
            cout<<"Invalid filling code was entered."<<endl;
        }
    }

    return 0;
}
