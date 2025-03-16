import java.util.Stack;
import java.util.Scanner;

def isPaired(leftBracket, rightBracket):
    pairedBrackets = [
        ('(', ')'),
        ('[', ']'),
        ('{', '}'),
        ('<', '>')
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
            bracketsStack.push(bracket)
        elif bracket == '[':
            bracketsStack.push(bracket)
        elif bracket == '{':
            bracketsStack.push(bracket)
        elif bracket == '<':
            bracketsStack.push(bracket)
        elif bracket == ')':
            if bracketsStack.isEmpty() or not isPaired(bracketsStack.pop(), bracket):
                return False
        elif bracket == ']':
            if bracketsStack.isEmpty() or not isPaired(bracketsStack.pop(), bracket):
                return False
        elif bracket == '}':
            if bracketsStack.isEmpty() or not isPaired(bracketsStack.pop(), bracket):
                return False
        elif bracket == '>':
            if bracketsStack.isEmpty() or not isPaired(bracketsStack.pop(), bracket):
                return False
    return bracketsStack.isEmpty()

if __name__ == '__main__':
    scanner = Scanner(System.in)
    input = scanner.nextLine()
    scanner.close()
    result = isBalanced(input)
    print(result)

