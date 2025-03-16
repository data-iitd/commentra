
import sys

# Check if given character is an operator
def isOperator(token):
    return token == '+' or token == '-' or token == '/' or token == '*' or token == '^'

# Check if given postfix expression is valid
def isValidPostfixExpression(postfix):
    # Check if the postfix expression is empty or contains only one alphabetic character
    if len(postfix) == 1 and postfix.isalpha():
        return True

    # Check if the length of the postfix expression is less than 3
    if len(postfix) < 3:
        return False

    operandCount = 0 # Initialize operand count
    operatorCount = 0 # Initialize operator count

    # Iterate through each character in the postfix expression
    for token in postfix:
        # If the current character is an operator
        if isOperator(token):
            operatorCount += 1 # Increment operator count

            # Check if the number of operators is greater than or equal to the number of operands
            if operatorCount >= operandCount:
                return False
        else:
            operandCount += 1 # Increment operand count

    # Check if the number of operands is equal to the number of operators plus one
    return operandCount == operatorCount + 1

# Convert postfix expression to infix expression
def getMain(postfix):
    # Check if the postfix expression is empty
    if postfix == "":
        return ""

    # Check if the postfix expression is invalid
    if not isValidPostfixExpression(postfix):
        raise Exception("Invalid Postfix Expression")

    stack = [] # Initialize stack

    # Iterate through each character in the postfix expression
    for token in postfix:
        # If the current character is not an operator
        if not isOperator(token):
            stack.append(token) # Push the operand onto the stack
        else:
            # Pop two operands from the stack and apply the operator on them
            operandB = stack.pop()
            operandA = stack.pop()

            # Push the result of the operation onto the stack
            stack.append('(' + operandA + token + operandB + ')')

    # Return the final result from the stack
    return stack.pop()

# Main method to read user input and print the result
def main():
    # Read postfix expression from user input
    postfix = sys.stdin.readline().strip()

    try:
        # Convert postfix expression to infix expression and print it
        infix = getMain(postfix)
        print("Infix Expression: " + infix)
    except Exception as e:
        # Print error message if the postfix expression is invalid
        print("Error: " + e.args[0])

if __name__ == "__main__":
    main()

