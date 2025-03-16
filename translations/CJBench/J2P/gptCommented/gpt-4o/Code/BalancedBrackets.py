class Main:
    @staticmethod
    def is_paired(left_bracket, right_bracket):
        # Define a list of paired brackets
        paired_brackets = [
            ('(', ')'),
            ('[', ']'),
            ('{', '}'),
            ('<', '>'),
        ]
        
        # Check if the left and right brackets form a pair
        return (left_bracket, right_bracket) in paired_brackets

    @staticmethod
    def is_balanced(brackets):
        # Check for None input and raise an exception if true
        if brackets is None:
            raise ValueError("Input string is None")
        
        # Create a stack to keep track of opening brackets
        brackets_stack = []
        
        # Iterate through each character in the input string
        for bracket in brackets:
            if bracket in '([{<':
                # If the character is an opening bracket, push it onto the stack
                brackets_stack.append(bracket)
            elif bracket in ')]}>':
                # If the character is a closing bracket
                # Check if the stack is empty or if the brackets do not match
                if not brackets_stack or not Main.is_paired(brackets_stack.pop(), bracket):
                    return False  # Return false if not balanced
            else:
                # If the character is not a bracket, return false
                return False
        
        # Return true if all opening brackets have been matched and the stack is empty
        return len(brackets_stack) == 0

if __name__ == "__main__":
    # Read a line of input from the user
    input_brackets = input()
    
    # Check if the input brackets are balanced and store the result
    result = Main.is_balanced(input_brackets)
    
    # Print the result: either "Balanced" or "Not Balanced"
    print("Balanced" if result else "Not Balanced")

# <END-OF-CODE>
