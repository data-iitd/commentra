
import sys

def is_operator(token):
    return token in ['+', '-', '*', '/']

def is_valid_postfix_expression(postfix):
    # A single alphabetic character is a valid postfix expression
    if len(postfix) == 1 and postfix.isalpha():
        return True
    # Postfix expressions must have at least 3 characters to be valid
    if len(postfix) < 3:
        return False

    operand_count = 0  # Count of operands
    operator_count = 0  # Count of operators

    # Iterate through each character in the postfix expression
    for token in postfix:
        if is_operator(token):
            operator_count += 1  # Increment operator count
            # There must be at least one operand for each operator
            if operator_count >= operand_count:
                return False
        else:
            operand_count += 1  # Increment operand count
    # A valid postfix expression must have exactly one more operand than operators
    return operand_count == operator_count + 1

def get_main(postfix):
    # Return an empty string if the postfix expression is empty
    if not postfix:
        return ""
    # Validate the postfix expression; throw an exception if invalid
    if not is_valid_postfix_expression(postfix):
        raise ValueError("Invalid Postfix Expression")

    stack = []  # Stack to hold operands

    # Iterate through each character in the postfix expression
    for token in postfix:
        if not is_operator(token):
            # Push operands onto the stack
            stack.append(token)
        else:
            # Pop the top two operands from the stack for the operator
            operand_b = stack.pop()
            operand_a = stack.pop()
            # Form a new infix expression and push it back onto the stack
            stack.append(f"({operand_a} {token} {operand_b})")
    # The final infix expression is the only element left in the stack
    return stack.pop()

if __name__ == "__main__":
    postfix = input("Enter the postfix expression: ")
    try:
        # Convert the postfix expression to infix and print it
        infix = get_main(postfix)
        print(f"Infix Expression: {infix}")
    except ValueError as e:
        # Handle invalid postfix expression
        print(f"Error: {e}")

