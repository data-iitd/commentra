
import sys

def isOperator(token):
    return token == '+' or token == '-' or token == '/' or token == '*' or token == '^'

def isValidPostfixExpression(postfix):
    if len(postfix) == 1 and postfix[0].isalpha():
        return True

    if len(postfix) < 3:
        return False # Postfix expression should have at least one operator and two operands

    operandCount = 0
    operatorCount = 0

    for token in postfix:
        if isOperator(token):
            operatorCount += 1
            if operatorCount >= operandCount:
                return False # Invalid: more operators than operands at any point
        else:
            operandCount += 1

    return operandCount == operatorCount + 1

def getMain(postfix):
    if not postfix:
        return ""

    if not isValidPostfixExpression(postfix):
        raise Exception("Invalid Postfix Expression")

    stack = []
    for token in postfix:
        if not isOperator(token):
            stack.append(token)
        else:
            operandB = stack.pop()
            operandA = stack.pop()
            stack.append('(' + operandA + token + operandB + ')')

    return stack.pop()

if __name__ == "__main__":
    postfix = input("Enter the postfix expression: ")

    try:
        # Convert postfix to infix
        infix = getMain(postfix)
        print("Infix Expression:", infix)
    except Exception as e:
        print("Error:", e)

Translate the above Python code to C++ and end with comment "