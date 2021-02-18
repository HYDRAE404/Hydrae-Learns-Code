// Hydrae's Science Trivia - C++ Code Edition //

#include <iostream>
using namespace std;

int main()
{
    int score = 0;
    cout << "Welcome to Hydrae's trivia!";
    cout << "\nI'll be asking 5 questions related to Science! :)";
    cout << "\n\nAlright! Let's start!";
    
    string ans1;
    cout << "\n\n1. What is anything that has mass, weight, density, and volume? ";
    getline(cin, ans1);
    if (ans1 == "Matter" || ans1 == "matter" || ans1 == "Matters" || ans1 == "matters")
    {
        score++;
        cout << "\nCorrect! Next item.";
    }
    else
    {
        cout << "\nIncorrect. Next item.";
    }
    
    string ans2;
    cout << "\n\n2. What are matters made of? ";
    getline(cin, ans2);
    if (ans2 == "Molecule" || ans2 == "Molecules" || ans2 == "molecule" || ans2 == "molecules")
    {
        score++;
        cout << "\nCorrect! Aight, next number!";
    }
    else
    {
        cout << "\nIncorrect. Next number.";
    }
    
    string ans3;
    cout << "\n\n3. Everything on Earth is a matter, including living things!\nBut living things are not made of molecules, what are they made of? ";
    getline(cin, ans3);
    if (ans3 == "Cell" || ans3 == "cell" || ans3 == "Cells" || ans3 == "cells")
    {
        score++;
        cout << "\nCorrect! Next!";
    }
    else
    {
        cout << "\nIncorrect. Next!";
    }
    
    string ans4;
    cout << "\n\n4. What is the process of the making of food of plants? ";
    getline(cin, ans4);
    if (ans4 == "Photosynthesis" || ans4 == "photosynthesis")
    {
        score++;
        cout << "\nCorrect! Last number!";
    }
    else
    {
        cout << "\nIncorrect. Last number!";
    }
    
    string ans5;
    cout << "\n\n5. What is a laboratory equipment is used to see tiny objects that cannot be seen by the naked eye? ";
    getline(cin, ans5);
    if (ans5 == "Microscope" || ans5 == "microscope" || ans5 == "Microscopes" || ans5 == "microscopes")
    {
        score++;
        cout << "\nCorrect!";
    }
    else
    {
        cout << "\nIncorrect.";
    }
    
    cout << "\n\nAlright, this is the end of the game!";
    cout << "\n\nYour score is: ";
    cout << score;
    cout << "/5";
    
    cout << "\n\n\nAight that's it! Until next time!";
    cout << "\n\nSee ya!";
    
    cout << "\n\n*This game was coded in C++";
    cout << "\n*Created by: HYDRAE404";
    cout << "\n*Thanks to OnlineGDB serving as an online compiler website! :D";
    cout << "\n\nNOTE: This game is now open source, anyone can copy/modify the code and distribute it.";
}
