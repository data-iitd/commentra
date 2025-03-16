import re

class InfixToPrefixConverter:
    def infix_to_prefix(self, infix_expression):
        # Check if the input expression is None and raise an exception if it is
        if infix_expression is None:
            raise ValueError("Input expression cannot be null.")
        
        # Trim whitespace from the expression
        infix_expression = infix_expression.strip()
        
        # Return an empty string if the expression is empty
        if not infix_expression:
            return ""
        
        # Check if the brackets in the expression are balanced
        if not self.is_balanced(self.filter_brackets(infix_expression)):
            raise ValueError("Invalid expression: unbalanced brackets.")
        
        # Initialize a list to hold the output prefix expression
        output = []
        # Create a stack to hold operators and parentheses
        stack = []
        # Reverse the infix expression for processing
        reversed_infix = infix_expression[::-1]
        
        # Process each character in the reversed infix expression
        for element in reversed_infix:
            # If the character is an operand, add it to the output
            if element.isalnum():
                output.append(element)
            # If the character is a closing parenthesis, push it onto the stack
            elif element == ')':
                stack.append(element)
            # If the character is an opening parenthesis, pop from the stack until a closing parenthesis is found
            elif element == '(':
                while stack and stack[-1] != ')':
                    output.append(stack.pop())
                # Pop the closing parenthesis from the stack
                if stack:
                    stack.pop()
            # If the character is an operator
            else:
                # Pop operators from the stack to the output based on precedence
                while stack and self.precedence(element) <= self.precedence(stack[-1]):
                    output.append(stack.pop())
                # Push the current operator onto the stack
                stack.append(element)
        
        # Pop any remaining operators from the stack to the output
        while stack:
            output.append(stack.pop())
        
        # Reverse the output to get the final prefix expression
        return ''.join(reversed(output))

    # Method to determine the precedence of operators
    def precedence(self, operator):
        if operator in ('+', '-'):
            return 1  # Lowest precedence
        elif operator in ('*', '/'):
            return 2  # Medium precedence
        elif operator == '^':
            return 3  # Highest precedence
        else:
            return 0  # Non-operator

    # Method to filter out non-bracket characters from the input
    def filter_brackets(self, input_str):
        return re.sub(r'[^(){}[\]<>]', '', input_str)  # Return only the brackets

    # Method to check if the brackets in the expression are balanced
    def is_balanced(self, expression):
        stack = []
        for ch in expression:
            # Push opening brackets onto the stack
            if ch in '({[<':
                stack.append(ch)
            # For closing brackets, check for matching opening brackets
            elif ch in ')}]>':
                if not stack:
                    return False  # Unmatched closing bracket
                top = stack.pop()
                if not self.is_matching_pair(top, ch):
                    return False  # Mismatched brackets
        # The expression is balanced if the stack is empty at the end
        return not stack

    # Method to check if a pair of brackets match
    def is_matching_pair(self, open_bracket, close_bracket):
        return (open_bracket == '(' and close_bracket == ')') or \
               (open_bracket == '{' and close_bracket == '}') or \
               (open_bracket == '[' and close_bracket == ']') or \
               (open_bracket == '<' and close_bracket == '>')

if __name__ == "__main__":
    # Create an instance of the converter
    converter = InfixToPrefixConverter()
    
    # Read the infix expression from the user
    infix_expression = input("Enter infix expression: ")
    
    try:
        # Convert the infix expression to prefix notation
        prefix_expression = converter.infix_to_prefix(infix_expression)
        # Output the resulting prefix expression
        print("Prefix Expression:")
        print(prefix_expression)
    except ValueError as e:
        # Handle any exceptions that occur during conversion
        print("Error:", e)

# <END-OF-CODE>
