class Main:
    @staticmethod
    def is_paired(left_bracket, right_bracket):
        paired_brackets = {
            '(': ')',
            '[': ']',
            '{': '}',
            '<': '>',
        }
        return paired_bracket.get(left_bracket) == right_bracket

    @staticmethod
    def is_balanced(brackets):
        if brackets is None:
            raise ValueError("Input string is null")
        
        brackets_stack = []
        for bracket in brackets:
            if bracket in '([{<':
                brackets_stack.append(bracket)
            elif bracket in ')]}>':
                if not brackets_stack or not Main.is_paired(brackets_stack.pop(), bracket):
                    return False
            else:
                return False
        return len(brackets_stack) == 0

if __name__ == "__main__":
    input_string = input()
    result = Main.is_balanced(input_string)
    print("Balanced" if result else "Not Balanced")

# <END-OF-CODE>
