import sys
import re

# This method checks if a given character is an operator.
def isOperator(token):
    return token == '+' or token == '-' or token == '/' or token == '*' or token == '^'

# This method validates if a given postfix expression is valid.
def isValidPostfixExpression(postfix):
    if len(postfix) == 1 and postfix.isalpha():
        return True
    if len(postfix) < 3:
        return False
    operandCount = 0
    operatorCount = 0
    for token in postfix:
        if isOperator(token):
            operatorCount += 1
            if operatorCount >= operandCount:
                return False
        else:
            operandCount += 1
    return operandCount == operatorCount + 1

# This method converts a valid postfix expression to an infix expression.
def getMain(postfix):
    if postfix == "":
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

# This is the entry point of the program where the user inputs a postfix expression, and the program outputs the corresponding infix expression.
def main():
    postfix = sys.stdin.readline().strip()
    try:
        infix = getMain(postfix)
        print("Infix Expression: " + infix)
    except Exception as e:
        print("Error: " + e.args[0])

if __name__ == "__main__":
    main()

