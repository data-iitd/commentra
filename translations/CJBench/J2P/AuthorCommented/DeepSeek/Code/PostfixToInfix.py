def is_operator(token):
    return token == '+' or token == '-' or token == '/' or token == '*' or token == '^'


def is_valid_postfix_expression(postfix):
    if len(postfix) == 1 and postfix[0].isalpha():
        return True

    if len(postfix) < 3:
        return False  # Postfix expression should have at least one operator and two operands

    operand_count = 0
    operator_count = 0

    for token in postfix:
        if is_operator(token):
            operator_count += 1
            if operator_count >= operand_count:
                return False  # Invalid: more operators than operands at any point
        else:
            operand_count += 1

    return operand_count == operator_count + 1


def get_main(postfix):
    if not postfix:
        return ""

    if not is_valid_postfix_expression(postfix):
        raise ValueError("Invalid Postfix Expression")

    stack = []
    for token in postfix:
        if not is_operator(token):
            stack.append(token)
        else:
            operand_b = stack.pop()
            operand_a = stack.pop()
            stack.append('(' + operand_a + token + operand_b + ')')

    return stack.pop()


if __name__ == "__main__":
    import sys
    # Input from the user
    postfix = input().strip()

    try:
        # Convert postfix to infix
        infix = get_main(postfix)
        print("Infix Expression: " + infix)
    except ValueError as e:
        print("Error: " + str(e))
