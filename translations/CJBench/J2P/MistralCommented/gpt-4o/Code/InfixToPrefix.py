import re

class InfixToPrefixConverter:
    # Method to convert infix expression to prefix expression
    @staticmethod
    def infix_to_prefix(infix_expression):
        if infix_expression is None:  # Check if the input expression is None
            raise ValueError("Input expression cannot be null.")  # Raise ValueError if it is

        infix_expression = infix_expression.strip()  # Trim any leading or trailing white spaces from the input expression

        if not infix_expression:  # Check if the input expression is empty
            return ""  # Return an empty string if it is

        if not InfixToPrefixConverter.is_balanced(InfixToPrefixConverter.filter_brackets(infix_expression)):  # Check if the input expression is balanced
            raise ValueError("Invalid expression: unbalanced brackets.")  # Raise ValueError if it is not balanced

        output = []  # Create a list to store the prefix expression
        stack = []  # Create a list to store the opening brackets or operators

        reversed_infix = infix_expression[::-1]  # Reverse the input expression

        for element in reversed_infix:  # Iterate through each character in the reversed input expression
            if element.isalnum():  # If the character is a letter or a digit, add it to the output
                output.append(element)
            elif element in [')', '}', ']', '>']:  # If the character is a closing bracket
                while stack and not InfixToPrefixConverter.is_matching_pair(stack[-1], element):
                    output.append(stack.pop())
                stack.pop()  # Pop the matching opening bracket
            else:  # If the character is an operator
                while stack and InfixToPrefixConverter.precedence(stack[-1]) >= InfixToPrefixConverter.precedence(element):
                    output.append(stack.pop())
                stack.append(element)

        while stack:  # Add any remaining operators to the output
            output.append(stack.pop())

        return ''.join(reversed(output))  # Reverse the output and return it as the prefix expression

    # Helper method to calculate the precedence of an operator
    @staticmethod
    def precedence(operator):
        if operator in ['+', '-']:
            return 1
        elif operator in ['*', '/']:
            return 2
        elif operator == '^':
            return 3
        else:
            return 0

    # Helper method to filter out any non-relevant characters from the input expression
    @staticmethod
    def filter_brackets(input_expression):
        return re.sub(r'[^(){}[\]<>]', '', input_expression)  # Return the filtered string after removing all non-bracket characters

    # Helper method to check if two brackets are matching pairs
    @staticmethod
    def is_matching_pair(open_bracket, close_bracket):
        return (open_bracket == '(' and close_bracket == ')') or \
               (open_bracket == '{' and close_bracket == '}') or \
               (open_bracket == '[' and close_bracket == ']') or \
               (open_bracket == '<' and close_bracket == '>')

    # Helper method to check if the brackets in the expression are balanced
    @staticmethod
    def is_balanced(filtered_expression):
        stack = []
        for char in filtered_expression:
            if char in '({[<':
                stack.append(char)
            elif char in ')}]>':
                if not stack or not InfixToPrefixConverter.is_matching_pair(stack.pop(), char):
                    return False
        return len(stack) == 0


# Main method to start the application
if __name__ == "__main__":
    infix_expression = input()  # Read the infix expression from the user input

    try:
        prefix_expression = InfixToPrefixConverter.infix_to_prefix(infix_expression)  # Call the infix_to_prefix method to convert infix expression to prefix expression
        print("Prefix Expression:")  # Print the prefix expression to the console
        print(prefix_expression)
    except ValueError as e:  # Catch any ValueError thrown during the execution
        print("Error:", e)  # Print the error message to the console

# <END-OF-CODE>
