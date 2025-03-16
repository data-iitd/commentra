import java.util.Stack;
import java.util.Scanner;

def isPaired(leftBracket, rightBracket):
    pairedBrackets = [
        ['(', ')'],
        ['[', ']'],
        ['{', '}'],
        ['<', '>'],
    ]
    for pairedBracket in pairedBrackets:
        if pairedBracket[0] == leftBracket and pairedBracket[1] == rightBracket:
            return True
    return False

def isBalanced(brackets):
    if brackets == None:
        raise Exception("Input string is null")
    bracketsStack = Stack()
    for bracket in brackets:
        if bracket == '(':
        elif bracket == '[':
        elif bracket == '{':
        elif bracket == '<':
        elif bracket == ')':
        elif bracket == ']':
        elif bracket == '}':
        elif bracket == '>':
        else:
            return False
    return bracketsStack.isEmpty()

def main():
    # Create a Scanner object to read input from the console
    scanner = Scanner(System.in)
    
    # Read a line of input from the user
    input = scanner.nextLine()
    
    # Close the scanner to free resources
    scanner.close()
    
    # Check if the input brackets are balanced and store the result
    result = isBalanced(input)
    
    # Print the result: either "Balanced" or "Not Balanced"
    print(result? "Balanced" : "Not Balanced")

if __name__ == "__main__":
    main()

