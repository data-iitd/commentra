def is_capital(ch):
    return 'A' <= ch <= 'Z'


def is_small(ch):
    return 'a' <= ch <= 'z'


def atbash_cipher(to_convert):
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
    # Input plaintext to encrypt/decrypt
    input_text = input()

    # Perform the Atbash cipher conversion
    result = atbash_cipher(input_text)

    # Output the converted text
    print("Converted Text:", result)


if __name__ == "__main__":
    main()

