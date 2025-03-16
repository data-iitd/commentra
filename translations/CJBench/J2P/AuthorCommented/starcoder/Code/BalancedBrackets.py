
import java.util.Stack;
import java.util.Scanner;

class Main:
    def __init__(self):
        pass

    def isPaired(self, leftBracket, rightBracket):
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

    def isBalanced(self, brackets):
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
                if bracketsStack.isEmpty() or not self.isPaired(bracketsStack.pop(), bracket):
                    return False
            elif bracket == ']':
                if bracketsStack.isEmpty() or not self.isPaired(bracketsStack.pop(), bracket):
                    return False
            elif bracket == '}':
                if bracketsStack.isEmpty() or not self.isPaired(bracketsStack.pop(), bracket):
                    return False
            elif bracket == '>':
                if bracketsStack.isEmpty() or not self.isPaired(bracketsStack.pop(), bracket):
                    return False
            else:
                return False
        return bracketsStack.isEmpty()

    def main(self):
        scanner = Scanner(System.in)
        input = scanner.nextLine()
        scanner.close()
        result = self.isBalanced(input)
        print("Balanced" if result else "Not Balanced")

if __name__ == "__main__":
    Main().main()

