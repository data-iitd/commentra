
import sys

def main():
    # Read input string from the user
    str = sys.stdin.readline().strip()

    # Find the index of the dot ('.') in the string
    dotIndex = 0
    for i in range(len(str)):
        if str[i] == '.':
            dotIndex = i
            break

    # Check if the character before the dot is '9'
    if str[dotIndex - 1] == '9':
        print("GOTO Vasilisa.")
    # If the character before the dot is not '9', check the digit after the dot
    else:
        # Increment the number before the dot by 1 and print the result
        _str = ""
        for i in range(dotIndex):
            _str += str[i]
        print(int(_str) + 1)

if __name__ == "__main__":
    main()

