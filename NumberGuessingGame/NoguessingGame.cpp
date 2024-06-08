#include <iostream>
#include <cstdlib>  //for rand() and srand()
#include <ctime>  //for time()

using namespace std;

int main()
{
    srand(time(0));  //seed the random number generator

    int SecretNumber = rand()%100+1;
    int guess;
    int attempts = 0;

    cout<<"Welcome to the Guessing Game!"<<endl;
    cout<<"I have chosen a number between 1 and 100. Can you guess it?"<<endl;

    while(1)  //keep looping until the user gives the correct number 
    {
        cout<<"Enter your guess:"<<endl;
        cin>>guess;

        attempts++; //Increment the number of attempts

        if(guess==SecretNumber)
        {
            cout<<"Congratulations! You guessed the correct number in"<<" "<<attempts<<" "<<"attempts"<<endl;
            break;
        }

        else if(guess<SecretNumber)
        {
            cout<<"Too Low! Try again."<<endl;
        }
        else
        {
            cout<<"Too High! Try again."<<endl;
        }
    }
    return 0;
}