import sys

class Main:
    def __init__(self):
        pass

    def isOperator(self, token):
        return token == '+' or token == '-' or token == '/' or token == '*' or token == '^'

    def isValidPostfixExpression(self, postfix):
        if len(postfix) == 1 and postfix.isalpha():
            return True

        if len(postfix) < 3:
            return False # Postfix expression should have at least one operator and two operands

        operandCount = 0
        operatorCount = 0

        for token in postfix:
            if self.isOperator(token):
                operatorCount += 1
                if operatorCount >= operandCount:
                    return False # Invalid: more operators than operands at any point
            else:
                operandCount += 1

        return operandCount == operatorCount + 1

    def getMain(self, postfix):
        if postfix == "":
            return ""

        if not self.isValidPostfixExpression(postfix):
            raise Exception("Invalid Postfix Expression")

        stack = []
        for token in postfix:
            if not self.isOperator(token):
                stack.append(token)
            else:
                operandB = stack.pop()
                operandA = stack.pop()
                stack.append('(' + operandA + token + operandB + ')')

        return stack.pop()

if __name__ == "__main__":
    main = Main()
    postfix = sys.stdin.readline().strip()

    try:
        # Convert postfix to infix
        infix = main.getMain(postfix)
        print("Infix Expression: " + infix)
    except Exception as e:
        print("Error: " + e.message)

