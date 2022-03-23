/*
1. Name: Kim, Jun
2. Assignment: CSCI 1 - Assignment 8: Struct and Array of Struct
3. Compiler used: CLion 2021.1.1
4. Operating system used: macOS Big Sur 11.3.1
5. Date and time you ran your program successfully and no changes were made after that:
    final version was released at May.27,2021. It was successful.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Quiz{
    string question;
    char key;
    char response;
};

const int MAX = 20;

void openInputFile(ifstream & input, const string & message);
int fillQuestions(Quiz qz[], ifstream & in);
int fillAnswerKeys(Quiz qz[], ifstream & inA);
void fillResponses(Quiz qz[], int len);
int gradeResponses(const Quiz qz[], int len);
void printAnswersAndResponses(const Quiz qz[], int len);

int main() {
    Quiz qz[MAX]={};
    ifstream input;
    cout<<"Welcome to driving test."<<endl;

    openInputFile(input, "questions");
    int lenQ = fillQuestions(qz, input);
    input.close();

    openInputFile(input, "answers");
    int lenA = fillAnswerKeys(qz, input);
    input.close();

    if(lenQ != lenA){
        cout<<"Number of questions and answers are different."<<endl;
    }else{
        fillResponses(qz, lenQ);
        int score = gradeResponses(qz, lenQ);
        cout<<"\nYou scored "<<score<<" points out of total "<<lenQ<<" points."<<endl;
        double percent = (static_cast<double>(score)/lenQ) * 100;
        if(percent >= 60.0){
            cout<<"You passed exam. Congratulation!"<<endl;
        }else{
            cout<<"You failed. Please review your answers."<<endl;
        }
        cout<<"Total answered correctly: "<<score<<endl
            <<"Total answered incorrectly: "<<(lenQ-score)<<endl;
        printAnswersAndResponses(qz, lenQ);
    }
    return 0;
}
void openInputFile(ifstream & input, const string & message){
    bool done = false;
    string In_File = "";
    while(!done) {
        input.clear();
        cout<<"Please input the name of the data file with "<<message<<" to be read: \n";
        getline(cin, In_File);
        cout<<"The file name entered is : \n"<<In_File<<endl;
        input.open(In_File);
        if (input.fail()) {
            cout<<"The file "<<In_File<<" does not exist.\n";
            done = false;
        }else{
            input.peek();
            if (input.eof()) {
                cout<<"The file has no data in it.\n";
                done = false;
                input.close();
            }else{
                done = true;
            }
        }
    }
    cout<<"File "<<In_File<<"opened and has data in it.\n"<<endl;
}
int fillQuestions(Quiz qz[], ifstream & in){
    int count = 0;
    while(in.peek() != EOF && count<MAX){
            string temp = "";
            in.ignore();
            getline(in,temp,'$');
            qz[count].question = temp;
            count++;
    }
    return count;
}
int fillAnswerKeys(Quiz qz[], ifstream & inA){
    int count = 0;
    while(inA.peek() != EOF && count<MAX){
            char temp = ' ';
            inA>>temp;
            qz[count].key = temp;
            count++;
    }
    return count;
}
void fillResponses(Quiz qz[], int len){
    cout<<"     * * * Driver's License Practice Exam * * *"<<endl
        <<"Please answer the questions as asked. Questions are multiple choice."<<endl
        <<"Enter correct letter response out of A, B, C, or D.\n"<<endl;
    for(int index=0; index<len; index++){
        cout<<qz[index].question<<endl;
        char temp = ' ';
        bool flag_Res = false;
        do{
            cout<<"Please choose your answer: ";
            cin>>temp;
            temp = toupper(temp);
            if(temp=='A' || temp=='B' || temp=='C' || temp=='D'){
                flag_Res = true;
            }else{
                cout<<"You entered wrong value. Please, choose correct one.\n";
            }
        }while(flag_Res == false);
        qz[index].response = temp;
    }
}
int gradeResponses(const Quiz qz[], int len){
    int score = 0;
    for(int index=0; index<len; index++){
        if(qz[index].key == qz[index].response){
            score++;
        }
    }
    return score;
}
void printAnswersAndResponses(const Quiz qz[], int len){
    cout<<"\nNow we give summary of all questions, answers and your responses."<<endl;
    for(int index=0; index<len; index++){
        cout<<qz[index].question<<endl
            <<"Correct answer = "<<qz[index].key<<endl
            <<"Your answer = "<<qz[index].response<<endl;
        if(qz[index].key == qz[index].response){
            cout<<"You got this question right.\n";
        }else{
            cout<<"You got this question wrong.\n";
        }
        if(index == (len-1)){
            cout<<"Thank you for using driving test\n"
                <<"Goodbye!"<<endl;
        }else{
            cout<<"Press any key to continue..."<<endl;
            cin.get(); //for Mac
            //system("pause") //for Windows
        }
    }
}