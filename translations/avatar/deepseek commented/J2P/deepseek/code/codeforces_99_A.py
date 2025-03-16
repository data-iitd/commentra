def main():
    # Read input string from the user
    str = input().strip()

    # Find the index of the dot ('.') in the string
    dot_index = 0
    for i in range(len(str)):
        if str[i] == '.':
            dot_index = i
            break

    # Check if the character before the dot is '9'
    if str[dot_index - 1] == '9':
        print("GOTO Vasilisa.")
    # If the character before the dot is not '9', check the digit after the dot
    elif int(str[dot_index + 1]) > 4:
        # Increment the number before the dot by 1 and print the result
        _str = ""
        for i in range(dot_index):
            _str += str[i]
        print(str(int(_str) + 1))
    # If the digit after the dot is 4 or less, print the number before the dot without any changes
    else:
        for i in range(dot_index):
            print(str[i], end='')
        print()


if __name__ == "__main__":
    main()
