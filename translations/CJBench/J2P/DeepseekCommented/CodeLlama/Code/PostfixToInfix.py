import re

# This method checks if a given character is an operator.
def is_operator(token):
    return token in ['+', '-', '/', '*', '^']

# This method validates if a given postfix expression is valid.
def is_valid_postfix_expression(postfix):
    if len(postfix) == 1 and postfix.isalpha():
        return True
    if len(postfix) < 3:
        return False
    operand_count = 0
    operator_count = 0
    for token in postfix:
        if is_operator(token):
            operator_count += 1
            if operator_count >= operand_count:
                return False
        else:
            operand_count += 1
    return operand_count == operator_count + 1

# This method converts a valid postfix expression to an infix expression.
def get_main(postfix):
    if not postfix:
        return ''
    if not is_valid_postfix_expression(postfix):
        raise ValueError("Invalid Postfix Expression")
    stack = []
    for token in postfix:
        if not is_operator(token):
            stack.append(token)
        else:
            operand_b = stack.pop()
            operand_a = stack.pop()
            stack.append('({} {} {})'.format(operand_a, token, operand_b))
    return stack.pop()

# This is the entry point of the program where the user inputs a postfix expression, and the program outputs the corresponding infix expression.
if __name__ == '__main__':
    postfix = input()
    try:
        infix = get_main(postfix)
        print("Infix Expression:", infix)
    except ValueError as e:
        print("Error:", e)

