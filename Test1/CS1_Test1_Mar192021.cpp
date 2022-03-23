/*
1. Name: Kim, Jun
2. Assignment: Test 1 on Sequential Structures
3. Compiler used: CLion 2020.3.2
4. Operating system used: macOS Big Sur 11.2.2
5. Date and time you ran your program successfully and no changes were made after that:
    final version was released at Mar.19,2021. It was successful.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const double costPaint = 0.1;

int main() {
    double a,   //a side for the tetrahedron
           b,   //b side for the tetrahedron
           c,   //c side for the tetrahedron
           d,   //d side for the tetrahedron
           e,   //e side for the tetrahedron
           f;   //f side for the tetrahedron
    double P1,  //surface area of P1 in tetrahedron
           P2,  //surface area of P2 in tetrahedron
           P3,  //surface area of P3 in tetrahedron
           P4;  //surface area of P4 in tetrahedron
    double totalArea,   //total surface area
           totalPrice;  //cost to paint
    int roundedPennies, //derived value from "totalPrice"
        dollars,        //whole dollars part of "totalPrice"
        cents;          //whole cents part of "totalPrice"

    cout<<"Welcome to tetrahedron painting cost calculation program.\n"
        <<"Please enter six sides of tetrahedron in format [xx.xx] as\n"
        <<"space separated numbers: "<<endl;
    cin>>a>>b>>c>>d>>e>>f;
    P1 = (a+b+c) / 2.0;
    P2 = (c+d+e) / 2.0;
    P3 = (b+d+f) / 2.0;
    P4 = (a+e+f) / 2.0;
    totalArea = sqrt(P1*(P1-a)*(P1-b)*(P1-c))+
                sqrt(P2*(P2-c)*(P2-d)*(P2-e))+
                sqrt(P3*(P3-b)*(P3-d)*(P3-f))+
                sqrt(P4*(P4-a)*(P4-e)*(P4-f));
    cout<<fixed<<showpoint<<setprecision(5)
        <<"Total surface area to be painted: "
        <<totalArea<<" square inches."<<endl;
    totalPrice = totalArea * costPaint;
    roundedPennies = static_cast<int>(totalPrice + 0.5);
    dollars = roundedPennies / 100;
    cents = roundedPennies % 100;
    cout<<"Your painting cost is: $"<<dollars
        <<" and "<<cents<<" cents.\nGood bye.";

    return 0;
}
