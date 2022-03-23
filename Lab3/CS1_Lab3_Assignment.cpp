/*
1. Name: Kim, Jun
2. Assignment: Assignment3:Use of Nested if/else Selection Structure
3. Compiler used: CLion 2020.3.2
4. Operating system used: macOS Big Sur 11.2.2
5. Date and time you ran your program successfully and no changes were made after that:
    final version was released at Mar.17,2021. It was successful.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const string endMessage =
        "*****************************************************************\n"
        "Thanks for using El Camino Quadratic Equation Solver.\n"
        "*****************************************************************\n";

int main() {

    int A = 0,  //Coefficient A in formulae
        B = 0,  //Coefficient B in formulae
        C = 0;  //Coefficient C in formulae
    double X1 = 0.0,    //Result of formulae when A and B is not zero
           X2 = 0.0,    //Result of formulae when A and B is not zero
           X3 = 0.0;    //Result of formulae when A is zero
    bool flagA, //Check for coefficient A value is not zero
         flagB; //Check for coefficient B value is not zero
    int discriminant = 0;   //Check for Nature of Solutions

    cout<<scientific<<setprecision(4);
    cout<<"*****************************************************************"<<endl
        <<"        EL CAMINO QUADRATIC EQUATION SOLVER                      "<<endl
        <<"*****************************************************************"<<endl
        <<"This program will provide solutions for an equation of the form  "<<endl
        <<"                     Ax^2 + Bx + C = 0,                          "<<endl
        <<"Where A, B, and C are integers, and A is not equal to zero.      "<<endl
        <<"*****************************************************************"<<endl;
    cout<<"Enter value of A (int only): ";
    cin>>A;
    flagA = (A != 0);
    if (flagA){
        cout<<"Enter value of B (int only): ";
        cin>>B;
        flagB = (B != 0);
        cout<<"Enter value of C (int only): ";
        cin>>C;
        discriminant = B*B - 4*A*C;
        if (discriminant > 0){
            X1 = (-B + sqrt(discriminant)) / (2.0*A);
            X2 = (-B - sqrt(discriminant)) / (2.0*A);
            cout<<"The two real solutions are   X = "<<X1<<endl
                <<"                       And   X = "<<X2<<endl;
            cout<<endMessage<<endl;
        }else if (discriminant < 0){
            double negDiscriminant = sqrt(abs(discriminant))/(2.0*A);
            if (flagB){
                X1 = -B / (2.0*A);
                X2 = -B / (2.0*A);
                cout<<"The two imaginary solutions are      X = "<<X1<<" + ("<<negDiscriminant<<")*I"<<endl
                    <<"                            And      X = "<<X2<<" - ("<<negDiscriminant<<")*I"<<endl;
                cout<<endMessage;
            }else{
                cout<<"The two imaginary solutions are      X = "<<"("<<negDiscriminant<<")*I"<<endl
                    <<"                            And      X = "<<"- ("<<negDiscriminant<<")*I"<<endl;
                cout<<endMessage;
            }
        }else{
            X1 = (-B + sqrt(discriminant)) / (2.0*A);
            cout<<"The one real solution is     X = "<<X1<<endl;
            cout<<endMessage;
        }
    }else{
        cout<<"Caution! If leading coefficient is zero then you actually do not have a quadratic equation."<<endl
            <<"You have a linear equation. If you wish to solve th linear equation Bx + C = 0,"<<endl
            <<"then please proceed."<<endl;
        cout<<"Enter value of B (int only): ";
        cin>>B;
        flagB = (B != 0);
        if (flagB){
            cout<<"Enter value of C (int only): ";
            cin>>C;
            X3 = -C / static_cast<double>(B);
            cout<<"Solution is      X = "<<X3<<endl<<endl;
            cout<<endMessage;
        }else{
            cout<<"With A and B both being zero you actually do not have an algebraic equation."<<endl;
            cout<<endl<<endMessage;
        }
    }
    return 0;
}
