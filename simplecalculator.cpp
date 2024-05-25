#include <iostream>
using namespace std;
int main()
{
    double num1,num2;
    char operation;

    cout<<"Welcome to the simple calculator:"<<endl;

    cout<<"Enter the first number:"<<" ";
    cin>>num1;
    cout<<"Enter the second number:"<<" ";
    cin>>num2;

    cout<<"Choose an opration from (+,-,*,/):"<<" ";
    cin>>operation;

    switch(operation)  // use to perform arthimetic operation based on cases
    {
        case '+':
          cout<<"Result:"<<" "<<num1+num2<<endl;
          break;

        case '-':
          cout<<"Result:"<<" "<<num1-num2<<endl;
          break;
        
        case '*':
          cout<<"Result:"<<" "<<num1*num2<<endl;
          break;

        case '/':
          if(num2!=0)
          {
            cout<<"Result:"<<" "<<num1/num2<<endl;
          }
          else{
            cout<<"Error! divisible by zero is not possible."<<endl;
          }
          break;

        default:
          cout<<"Error: Invalid operation."<<endl;
    }
    return 0;
}