
import re

# Check if given character is an operator
def is_operator(token):
    return token in '+-*/^'

# Check if given postfix expression is valid
def is_valid_postfix_expression(postfix):
    # Check if the postfix expression is empty or contains only one alphabetic character
    if len(postfix) == 1 and postfix.isalpha():
        return True

    # Check if the length of the postfix expression is less than 3
    if len(postfix) < 3:
        return False

    operand_count = 0  # Initialize operand count
    operator_count = 0  # Initialize operator count

    # Iterate through each character in the postfix expression
    for token in postfix:
        # If the current character is an operator
        if is_operator(token):
            operator_count += 1  # Increment operator count

            # Check if the number of operators is greater than or equal to the number of operands
            if operator_count >= operand_count:
                return False
        else:
            operand_count += 1  # Increment operand count

    # Check if the number of operands is equal to the number of operators plus one
    return operand_count == operator_count + 1

# Convert postfix expression to infix expression
def get_main(postfix):
    # Check if the postfix expression is empty
    if not postfix:
        return ''

    # Check if the postfix expression is invalid
    if not is_valid_postfix_expression(postfix):
        raise ValueError('Invalid Postfix Expression')

    stack = []  # Initialize stack

    # Iterate through each character in the postfix expression
    for token in postfix:
        # If the current character is not an operator
        if not is_operator(token):
            stack.append(token)  # Push the operand onto the stack
        else:
            # Pop two operands from the stack and apply the operator on them
            operand_b = stack.pop()
            operand_a = stack.pop()

            # Push the result of the operation onto the stack
            stack.append('({} {} {})'.format(operand_a, token, operand_b))

    # Return the final result from the stack
    return stack.pop()

# Main method to read user input and print the result
def main():
    postfix = input('Enter Postfix Expression: ')  # Read postfix expression from user input

    try:
        # Convert postfix expression to infix expression and print it
        infix = get_main(postfix)
        print('Infix Expression:', infix)
    except ValueError as e:
        # Print error message if the postfix expression is invalid
        print('Error:', e)

if __name__ == '__main__':
    main()

