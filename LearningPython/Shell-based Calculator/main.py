import Operations as op
import moremath1 as mm1
import temp as tmp
import programmer_calc as procal
import EqAndIneq as eq

op_choice = ["[1] Addition","[2] Subtraction","[3] Multiplication","[4] Division"]
moremath1 = ["[1] Square","[2] Cube","[3] Square Root","[4] Cube Root"]
tempchoice = ["[1] To Celsius","[2] To Fahrenheit"

running = True

def basicOp():
    num1 = int(input("First number: "))
    num2 = int(input("Second number: "))

    for opch in op_choice:
        print(opch)

    choose1 = int(input("Now choose an operation... [1/2/3/4] : "))

    if choose1 not in [1,2,3,4]:
        print("Invalid input, try again.")
        basicOp()
    elif (choose1==1):
        print(op.Add(num1, num2))
    elif (choose1==2):
        print(op.Sub(num1, num2))
    elif (choose1==3):
        print(op.Mult(num1, num2))
    else:
        print(op.Div(num1, num2))

def rts_n_mr():
    num = int(input("Type a number: "))

    for mrmth1 in moremath1:
        print(mrmth)

    choose2 = int(input("Now choose any of those... [1/2/3/4] : "))

    if choose2 not in [1,2,3,4]:
        print("Invalid input, try again.")
        rts_n_mr()
    elif (choose2==1):
        print(mm1.Square(num))
    elif (choose2==2):
        print(mm1.Cube(num))
    elif (choose2==3):
        print(mm1.Sqrt(num))
    else:
        print(mm1.Cbrt(num))

def toTemp():
    num = int(input("Input a number to convert: "))

    for convTemp in tempchoice:
        print(convTemp)

    choose3 = int(input("[1/2] : "))

    if choose3 not in [1,2]:
        print(Invalid input, try again.)
    elif (choose3==1):
        print(tmp.toCelsius(num) + "°C")
    else:
        print(tmp.toFahrenheit(num) + "°F")

def toProgram():
    for i in range(len(procal.convto)):
        print(procal.convto[i])

    choose4 = int(input("[1/2] : "))

    if choose4 not in [1,2]:
        print("Invalid input, try again.")
        toProgram()
    elif choose4 == 1:
        num = int(input("Now type in a number : "))
        print(toBinary(num))
    else:
        num = int(input("Now type in a number : "))
        print(toDecimal(num))

def toEq():
    num1 = int(input("First number: "))
    num2 = int(input("Second number: "))
    
    for i in range(len(Eq.eqchoice)):
        print(eq.choice[i])

    choose5 = int(input("[1/2/3/4/5/6] : "))

    if choose5 not in [1,2,3,4,5,6]:
        print("Invalid input, try again.")
        toEq()
    elif choose5 == 1:
        print(eq.Eq(num1,num2))
    elif choose5 == 2:
        print(eq.Ineq(num1,num2))
    elif choose5 == 3:
        print(eq.isGreaterThan(num1, num2))
    elif choose5 == 4:
        print(eq.isLessThan(num1, num2))
    elif choose5 == 5:
        print(eq.atLeast(num1, num2))
    else:
        print(eq.atMost(num1, num2))

# Main call

while running:
    print("[1] Basic Operations")
    print("[2] Roots & More")
    print("[3] Temperature Converter")
    print("[4] Programmer")
    print("[5] Equalities and Inequalities")
    print("[6] Exit")
    choice = int(input("[1/2/3/4/5/6] : "))
    
    if choice not in [1,2,3,4,5,6]:
        print("Invalid input, try again.")
    elif choice == 1:
        basicOp()
    elif choice == 2:
        rts_n_mr()
    elif choice == 3:
        toTemp()
    elif choice == 4:
        toProgram()
    elif choice == 5:
        toEq()
    else:
        running = False
        break
