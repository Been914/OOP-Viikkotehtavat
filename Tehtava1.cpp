#include <iostream>
#include <cstdlib>
using namespace std;
int game(int maxnum);
int main() {
    while (true)
    {
        int maxnum;
        cout << "Enter the maximum number for the guessing game (or 0 to quit): ";
        cin >> maxnum;
        if (maxnum == 0)
        {
            break;
        }
        else if (maxnum < 1)
        {
            cout << "Invalid number" << endl;
            continue;   
        }
        else {
            int tries = game(maxnum);
            cout << "You took " << tries << " tries to guess the number" << endl;
        }
    }
    return 0;
}

int game(int maxnum)
{
    int number = rand() % maxnum + 1;
    int tries = 0;
    while(true)
    {
        tries++;
        int guess;
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess < number)
        {
            cout << "Too low" << endl;
        }
        else if (guess > number)
        {
            cout << "Too high" << endl;
        }
        else
        {
            cout << "Correct!" << endl;
            return tries;
        }
    }
}

