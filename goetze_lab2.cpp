#include <iostream>

void get_formula(int& operand1, char& op, int& operand2);//prints the menu of operators and the prompt for the formula. Reads the first operand into parameter operand1. If the first operand is not 0, reads the operator into parameter op and the second operand into parameter operand2. Post-condition: actual parameters are altered.
void print_formula(int operand1, char op, int operand2, double answer);//prints the formula with the answer.If the operand is / or % and the denominator is 0, print undefined for the answer
double sum(int a, char op, int b);//performs mathematical operation based on char

int main()
{
using namespace std;
cout  << "Welcome to the Programmer's Calculator!\n";
int operand1, operand2;
char op;
double answer;
int name, total;

do{                                             //loop so program continues to run until user inputs a 0 for the first operand
get_formula(operand1, op, operand2);                    //call of function get_formula
answer = sum(operand1, op, operand2);                   // call of function sum
print_formula(operand1, op, operand2, answer);          // call of function print_formula
}while(operand1 != 0);

return 0;
}


void get_formula(int& operand1, char& op, int& operand2)
{
using namespace std;

cout << "Enter a formula with integers below. Valid operators are:\n"
     << "\t+ addition\n"
     << "\t- subtraction\n"
     << "\t* multiplication\n"
     << "\t/ integer division\n"
     << "\t% modulus division\n"
     << "\t^ exponentiation\n"
     << "\t0 to end the program\n"
     << "Formula:";
cin  >> operand1;

if(operand1 == 0){
        cout <<"Thank you for using the Programmer's Calculator!" << endl;
return;}else
cin >> op >> operand2;

if(op=='/' && operand2 ==0 ){
        cout<<"Formula: " << operand1 << op << operand2 << " = undefined."<<endl;
return;}

if(op=='%' && operand2 ==0 ){
        cout<<"Formula: " << operand1 << op << operand2 << " = undefined."<<endl;
return;}

if(!(op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^'))
        cout << "Invalid operator."<< endl;


}


void print_formula(int operand1, char op, int operand2, double sum)
{
using namespace std;
if ((op == '/' || op == '%') && (operand2 ==0)){
        return;}else{
if(operand1 != 0 && (op =='+'|| op =='-' || op=='*' || op=='/' || op =='%' || op=='^'))
cout << operand1 << op << operand2<< "=" << sum << endl;
}
}

double sum(int a, char op, int b)
{
using namespace std;
int total,i;
total = 1;

if(op == '+')
        return(a+b);
if(op == '-')
        return(a-b);
if(op == '*')
        return(a*b);
if((op == '/') && (!(b==0)))
        return(a/b);
if((op == '%') && (!(b==0)))
        return(a%b);
if(op == '^'){
        for(i=0;i<b;++i){
        total *=a;}
        return(total);};
}
