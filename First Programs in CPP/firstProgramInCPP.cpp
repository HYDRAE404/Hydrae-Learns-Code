#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Hello, world!";

  string myFirstStr = "This is a string data type in C++";
  cout << "\n" + myFirstStr;

  int myFirstNum = 69;
  cout << "\nThis is an int data type: ";
  cout << myFirstNum;

  bool myFirstBool = true;
  cout << "\nThis is a bool data type: ";
  cout << myFirstBool;

  string fullName;
  cout << "\n\nWhat's your full name? : ";
  getline (cin, fullName);
  cout << "\nOh, hello " + fullName + "!";

  cout << "\n\nI wanna ask a question...";
  cout << "\nThis is just a trivia about America's new president.\n\n";

  string choice1;
  cout << "Who won the 2020 president election?: ";
  getline (cin, choice1);

  if (choice1 == "Biden" or choice1 == "Joe Biden")
    {
      cout << "\nCorrect!";
    }
  else
    {
      cout << "\nIncorrect.";
    }

  cout << "\nAight, that's it for now. See ya next time!";
}
