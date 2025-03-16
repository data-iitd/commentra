def is_capital(ch):
    return 'A' <= ch <= 'Z'


def is_small(ch):
    return 'a' <= ch <= 'z'


def convert(to_convert):
    converted_string = []
    for ch in to_convert:
        if is_small(ch):
            converted_string.append(chr(ord('z') - (ord(ch) - ord('a'))))
        elif is_capital(ch):
            converted_string.append(chr(ord('Z') - (ord(ch) - ord('A'))))
        else:
            converted_string.append(ch)
    return ''.join(converted_string)


def main():
    input_text = input()
    result = convert(input_text)
    print("Converted Text:", result)


main()
