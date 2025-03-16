def is_operator(token):
    return token == '+' or token == '-' or token == '/' or token == '*' or token == '^'


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


def postfix_to_infix(postfix):
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
            stack.append(f'({operand_a}{token}{operand_b})')

    return stack.pop()


def main():
    postfix = input()
    try:
        infix = postfix_to_infix(postfix)
        print("Infix Expression: " + infix)
    except ValueError as e:
        print("Error: " + str(e))


if __name__ == "__main__":
    main()
