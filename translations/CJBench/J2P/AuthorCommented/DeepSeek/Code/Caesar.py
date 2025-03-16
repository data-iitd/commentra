def encode(message, shift):
    encoded = []
    shift %= 26

    for char in message:
        if 'A' <= char <= 'Z':
            char = chr((ord(char) + shift - ord('A')) % 26 + ord('A'))
            encoded.append(char)
        elif 'a' <= char <= 'z':
            char = chr((ord(char) + shift - ord('a')) % 26 + ord('a'))
            encoded.append(char)
        else:
            encoded.append(char)
    return ''.join(encoded)


def decode(encrypted_message, shift):
    decoded = []
    shift %= 26

    for char in encrypted_message:
        if 'A' <= char <= 'Z':
            char = chr((ord(char) - shift - ord('A')) % 26 + ord('A'))
            decoded.append(char)
        elif 'a' <= char <= 'z':
            char = chr((ord(char) - shift - ord('a')) % 26 + ord('a'))
            decoded.append(char)
        else:
            decoded.append(char)
    return ''.join(decoded)


def bruteforce(encrypted_message):
    list_of_all_the_answers = []
    for i in range(27):
        list_of_all_the_answers.append(decode(encrypted_message, i))
    return list_of_all_the_answers


def main():
    operation = input().strip().lower()

    if operation == "encode":
        plaintext = input()
        shift = int(input())
        print("Encoded Message: " + encode(plaintext, shift))
    elif operation == "decode":
        encrypted_text = input()
        shift = int(input())
        print("Decoded Message: " + decode(encrypted_text, shift))
    elif operation == "bruteforce":
        encrypted_text = input()
        possible_solutions = bruteforce(encrypted_text)
        for i, solution in enumerate(possible_solutions):
            print(f"Shift {i}: {solution}")
    else:
        print("Invalid operation. Please enter encode, decode, or bruteforce.")


if __name__ == "__main__":
    main()
