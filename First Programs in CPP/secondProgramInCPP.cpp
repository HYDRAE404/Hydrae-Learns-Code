#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Welcome again!";
    cout << "\nThis is my second program in C++";
    
    cout << "\n\nToday, I'll be trying out the For Loop and While Loop.";
    cout << "\n\nAlright, let's start!\n";
    
    cout << "I just did the For Loop! : ";
    for (int i = 0; i < 11; i++)
    {
        cout << i;
    }
    
    cout << "\n\nNow let's try another one. But in a listing method! :\n";
    for (int i = 0; i < 11; i++)
    {
        cout << "\n" << i;
    }
    
    cout << "\n\nIt worked well! :D";
    
    cout << "\n\nOk, now moving on to the While Loop.\n";
    
    int i = 0;
    while (i != 51)
    {
        cout << i << "\n";
        i++;
    }
    
    cout << "\nOk, EPIC";
}