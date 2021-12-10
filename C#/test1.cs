using System;

namespace Main
{
    class Lobby
    {
        static void Main(string[] args)
        {
            string choice1;
            string choice2;
            
            Console.Write("Would you like a cup of tea? [Yes/No]: ");
            choice1 = Console.ReadLine();
            
            if (choice1 == "Yes")
            {
                Console.WriteLine("Well here is your cup of tea.");
                Console.WriteLine("Now let's talk about the contract.");
            }
            
            else if (choice1 == "No")
            {
                Console.Write("Some water perhaps? [Yes/No]: ");
                choice2 = Console.ReadLine();
                
                if (choice2 == "Yes")
                {
                    Console.WriteLine("Well here\'s some water.");
                    Console.WriteLine("Now let's talk about the contract.");
                }
                
                else if (choice2 == "No")
                {
                    Console.WriteLine("Ok. Now let's talk about the contract.");
                }
            }
        }
    }
}
