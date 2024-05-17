#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time
using namespace std;
int main()
{
    srand(time(0));  // seed the random number generator 

    int secretNumber = rand()%100+1; // generates number from 1 to 100
    int guess;
    int attempts = 0;

    cout<<"Welcome to the guessing game!."<<endl;
    cout<<"I have chosen a number from 1 to 100. Can you guess it?."<<endl;

    while(1)
    {
        cout<<"Enter the guessing number:"<<endl;
        cin>>guess;
        attempts++; // increment number of attempts

        if (guess==secretNumber)
        {
            cout<<"Congratulations! you guess the correct number in"<< attempts << "attempts" <<endl;
            break;
        }
        else if(guess<secretNumber)
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