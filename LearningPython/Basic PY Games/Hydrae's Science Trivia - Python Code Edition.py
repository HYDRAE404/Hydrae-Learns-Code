# Hydrae's Science Trivia - Python Code Edition #

score = 0

print("Welcome to Hydrae's trivia!")
print("I'll be asking 5 questions related to Science! :)")
print("\nAlright! Let's start!")

ans1 = input("\n1. What is anything that has mass, weight, density, and volume? ")
if ans1 not in ["Matter", "matter", "Matters", "matters"]:
    print("\nIncorrect. Next item.")
else:
    score += 1
    print("\nCorrect! Next item.")

ans2 = input("\n2. What are matters made of? ")
if ans2 not in ["Molecule","molecule","Molecules","molecules"]:
    print("\nIncorrect. Next number.")
else:
    score += 1
    print("\nCorrect! Aight, next number!")

ans3 = input("\n3. Everything on Earth is a matter, including living things!\nBut living things are not made of molecules, what are they made of? ")
if ans3 not in ["Cell","cell","Cells","cells"]:
    print("\nIncorrect. Next!")
else:
    score += 1
    print("\nCorrect! Next!")

ans4 = input("\n4. What is the process of the making of food of plants? ")
if ans4 not in ["Photosynthesis","photosynthesis"]:
    print("\nIncorrect. Last number!")
else:
    score += 1
    print("\nCorrect! Last number!")

ans5 = input("\n5. What is a laboratory equipment is used to see tiny objects that cannot be seen by the naked eye? ")
if ans5 not in ["Microscope","microscope","Microscopes","microscopes"]:
    print("\nIncorrect.")
else:
    score += 1
    print("\nCorrect!")

print("\nAlright, this is the end of the game!")
print("\nYour score is: ",score,"/5")

print("\n\nAight that's it! Until next time!")
print("\nSee ya!")

print("\n*This game was originally coded in C++")
print("*But it was recreated in Python")
print("*Created by: HYDRAE404")
print("*Thanks to OnlineGDB serving as an online compiler website! :D")
print("\nNOTE: This game is now open source, anyone can copy/modify the code and distribute it.")
