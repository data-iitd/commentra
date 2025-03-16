import sys
import re

def isOperator(token):
    return token == '+' or token == '-' or token == '/' or token == '*' or token == '^'

def isValidPostfixExpression(postfix):
    if len(postfix) == 1 and postfix[0].isalpha():
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

def getMain(postfix):
    if len(postfix) == 0:
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
    postfix = sys.stdin.readline().strip()
    try:
        infix = getMain(postfix)
        print("Infix Expression: " + infix)
    except Exception as e:
        print("Error: " + e.message)

