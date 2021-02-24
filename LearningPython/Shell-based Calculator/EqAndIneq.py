eqchoice = ["[1] Equals","[2] Not Equals","[3] Greater Than","[4] Less Than","[5] At Least","[6] At Most"]

def Eq(num1, num2):
    if num1==num2:
        result = True
    else:
        result = False
    return result

 def Ineq(num1, num2):
    if num1!=num2:
        result = True
    else:
        result = False
    return result

def isGreaterThan(num1, num2):
    if num1 > num2:
        result = True
    else:
        result = False
    return result

def isLessThan(num1, num2):
    if num1 < num2:
        result = True
    else:
        result = False
    return result

def atLeast(num1, num2):
    pass
