/*
1. Name: Kim, Jun
2. Assignment: CSCI 1 - Assignment 7: Arrays
3. Compiler used: CLion 2021.1.1
4. Operating system used: macOS Big Sur 11.3.1
5. Date and time you ran your program successfully and no changes were made after that:
    final version was released at May.18,2021. It was successful.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const size_t MAX = 20;

void openFile(ifstream & input, const string & message);
int fillQuestionsArray(string questions[], ifstream & in);
int fillAnswerKeyArray(char ans[], ifstream & in);
int fillResponseArray(const string questions[], char response[], int len);
int GradeResponses(const char answers[], const char response[], int len);
void printAnswersAndResponses(const string questions[], const char answers[], const char response[], int len);

int main() {
    cout<<"Welcome to driving test."<<endl;
    ifstream in;

    openFile(in, "questions");
    string questions[MAX] = {};
    int lenQ = fillQuestionsArray(questions,in);
    in.close();

    openFile(in, "answers");
    char ans[MAX] = {};
    int lenA = fillAnswerKeyArray(ans,in);

    if(lenQ != lenA){
        cout<<"Number of questions and answers are different."<<endl;

    }else{
        char response[MAX] = {};
        int lenR = fillResponseArray(questions, response, lenQ);
        int score = 0;
        if(lenQ != lenR){
            cout<<"Number of questions and responses are different."<<endl;
        }else{
            score = GradeResponses(ans,response,lenQ);
            cout<<"You scored "<<score<<" points out of total "<<lenQ<<" points."<<endl;
            double percent = (static_cast<double>(score)/lenQ) * 100;
            if(percent >= 60.0){
                cout<<"You passed exam. Congratulation!"<<endl;
            }else{
                cout<<"You failed. Please review your answers."<<endl;
            }
            cout<<"Total answered correctly: "<<score<<endl
                <<"Total answered incorrectly: "<<(lenQ-score)<<endl;
        }
        printAnswersAndResponses(questions, ans, response, lenQ);
    }
    in.close();
    return 0;
}

void openFile(ifstream & input, const string & message){
    bool done = false;
    string In_File = "";
    while(!done){
        input.clear();
        cout<<"Please input the name of the data file with "<<message<<" to be read: "<<endl;
        getline(cin,In_File);
        cout<<"The file name entered is: \n"<<In_File<<endl;
        input.open(In_File);
        if(input.fail()){
            cout<<"The file "<<In_File<<" does not exist."<<endl;
            continue;
        }else{
            if(input.peek() == EOF ){
                cout<<"The file has no data in it."<<endl;
                input.close();
                continue;
            }else{
                done = true;
            }
        }
    }
    cout<<"File "<<In_File<<" opened and has data in it.\n"<<endl;
}
int fillQuestionsArray(string questions[], ifstream & in){
    int i = 0;
    while(in.peek() != EOF && i<MAX){
        string question = "";
        char ch = ' ';
        while(in.peek() != '$'){ //Same function with "getline(in, question, '$');"
            ch = in.get();
            question += ch;
        }
        questions[i] = question;
        in.ignore(256,'\n');
        i++;
    }
    return i;
}
int fillAnswerKeyArray(char ans[], ifstream & in){
    int i = 0;
    while(in.peek() != EOF && i<MAX){
        in>>ans[i];
        i++;
    }
    return i;
}
int fillResponseArray(const string questions[], char response[], int len){
    cout<<"     * * * Driver's License Practice Exam * * *"<<endl
        <<"Please answer the questions as asked. Questions are multiple choice."<<endl
        <<"Enter correct letter response out of A, B, C, or D.\n"<<endl;
    char res = ' '; //response from user.
    int i = 0;
    for(i; i<len; i++){
        cout<<questions[i]<<endl;
        bool flag_Res = false;
        do{
            cout<<"Please choose your answer: ";
            cin>>res;
            res = toupper(res);
            if(res=='A'||res=='B'||res=='C'||res=='D'){
                flag_Res = true;
            }else{
                cout<<"You entered wrong value. Pleas, choose correct one."<<endl;
            }
        }while(flag_Res == false);
        response[i] = res;
    }
    return i;
}
int GradeResponses(const char answers[], const char response[], int len){
    int score = 0;
    for(int i=0; i<len; i++){
        if(answers[i] == response[i]){
            score++;
        }
    }
    return score;
}
void printAnswersAndResponses(const string questions[], const char answers[], const char response[], int len){
    cout<<"\nNow we give summary of all questions, answers and your responses."<<endl;
    int i = 0;
    for(i=0; i<len; i++){
        cout<<questions[i]<<endl
            <<"Correct answer = "<<answers[i]<<endl
            <<"Your answer = "<<response[i]<<endl;
        if(answers[i] == response[i]){
            cout<<"You got this question right."<<endl;
        }else{
            cout<<"You got this question wrong."<<endl;
        }
        if(i == (len-1)){
            cout<<"Thank you for using driving test\n"
                <<"Goodbye!"<<endl;
        }else {
            cout << "Press any key to continue..." << endl;
            cin.get(); //this cod is for Mac
            //system ("pause") //this code is for Windows
        }
    }
}