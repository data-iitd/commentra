class Main:
    @staticmethod
    def is_paired(left_bracket, right_bracket):
        paired_brackets = [
            ('(', ')'),
            ('[', ']'),
            ('{', '}'),
            ('<', '>'),
        ]

        # Search for the pair of brackets in the paired_brackets list
        for paired_bracket in paired_brackets:
            if paired_bracket[0] == left_bracket and paired_bracket[1] == right_bracket:
                return True  # If found, return true
        return False  # If not found, return false

    @staticmethod
    def is_balanced(brackets):
        if brackets is None:  # Check if the input string is None
            raise ValueError("Input string is None")  # If so, raise a ValueError

        brackets_stack = []  # Create a new list to use as a stack

        # Iterate through each character in the input string
        for bracket in brackets:
            if bracket in '([{<':
                brackets_stack.append(bracket)  # Push the left bracket to the stack
            elif bracket in ')]}>':
                # If the stack is empty or the right bracket does not match the top left bracket, return false
                if not brackets_stack or not Main.is_paired(brackets_stack.pop(), bracket):
                    return False
            else:
                return False  # If the character is not a valid bracket, return false

        # If the stack is empty, the string is balanced
        return len(brackets_stack) == 0

# Main method is the entry point of the Python application
if __name__ == "__main__":
    input_string = input()  # Read a line of text from the standard input
    result = Main.is_balanced(input_string)  # Call the is_balanced method to check if the input string is balanced
    print("Balanced" if result else "Not Balanced")  # Print the result to the standard output

# <END-OF-CODE>
