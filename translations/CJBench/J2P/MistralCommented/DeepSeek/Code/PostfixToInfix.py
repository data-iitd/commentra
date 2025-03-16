class Main:
    @staticmethod
    def is_operator(token):
        return token == '+' or token == '-' or token == '/' or token == '*' or token == '^'

    @staticmethod
    def is_valid_postfix_expression(postfix):
        if len(postfix) == 1 and postfix.isalpha():
            return True
        if len(postfix) < 3:
            return False
        operand_count = 0
        operator_count = 0
        for token in postfix:
            if Main.is_operator(token):
                operator_count += 1
                if operator_count >= operand_count:
                    return False
            else:
                operand_count += 1
        return operand_count == operator_count + 1

    @staticmethod
    def get_main(postfix):
        if not postfix:
            return ""
        if not Main.is_valid_postfix_expression(postfix):
            raise ValueError("Invalid Postfix Expression")
        stack = []
        for token in postfix:
            if not Main.is_operator(token):
                stack.append(token)
            else:
                operand_b = stack.pop()
                operand_a = stack.pop()
                stack.append(f'({operand_a}{token}{operand_b})')
        return stack.pop()

    @staticmethod
    def main():
        postfix = input()
        try:
            infix = Main.get_main(postfix)
            print("Infix Expression: " + infix)
        except ValueError as e:
            print("Error: " + str(e))

Main.main()
