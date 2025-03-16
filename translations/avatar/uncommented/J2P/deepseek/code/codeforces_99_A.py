import sys

def main():
    str_input = input().strip()
    dot_index = str_input.find('.')
    
    if str_input[dot_index - 1] == '9':
        print("GOTO Vasilisa.")
    elif int(str_input[dot_index + 1]) > 4:
        _str = str_input[:dot_index]
        print(str(int(_str) + 1))
    else:
        print(str_input[:dot_index])

if __name__ == "__main__":
    main()
