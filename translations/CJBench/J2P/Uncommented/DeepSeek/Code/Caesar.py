def is_capital_latin_letter(c):
    return 'A' <= c <= 'Z'


def is_small_latin_letter(c):
    return 'a' <= c <= 'z'


def encode(message, shift):
    encoded = []
    shift %= 26
    for current in message:
        if is_capital_latin_letter(current):
            current = chr(ord(current) + shift)
            if current > 'Z':
                current = chr(ord(current) - 26)
        elif is_small_latin_letter(current):
            current = chr(ord(current) + shift)
            if current > 'z':
                current = chr(ord(current) - 26)
        encoded.append(current)
    return ''.join(encoded)


def decode(encrypted_message, shift):
    decoded = []
    shift %= 26
    for current in encrypted_message:
        if is_capital_latin_letter(current):
            current = chr(ord(current) - shift)
            if current < 'A':
                current = chr(ord(current) + 26)
        elif is_small_latin_letter(current):
            current = chr(ord(current) - shift)
            if current < 'a':
                current = chr(ord(current) + 26)
        decoded.append(current)
    return ''.join(decoded)


def bruteforce(encrypted_message):
    list_of_all_the_answers = []
    for i in range(27):
        list_of_all_the_answers.append(decode(encrypted_message, i))
    return list_of_all_the_answers


def main():
    operation = input().strip().lower()
    if operation == 'encode':
        plaintext = input()
        shift = int(input())
        print("Encoded Message: " + encode(plaintext, shift))
    elif operation == 'decode':
        encrypted_text = input()
        shift = int(input())
        print("Decoded Message: " + decode(encrypted_text, shift))
    elif operation == 'bruteforce':
        encrypted_text = input()
        possible_solutions = bruteforce(encrypted_text)
        print("Possible Decoded Messages:")
        for i, possible_solution in enumerate(possible_solutions):
            print(f"Shift {i}: {possible_solution}")
    else:
        print("Invalid operation. Please enter encode, decode, or bruteforce.")


main()
