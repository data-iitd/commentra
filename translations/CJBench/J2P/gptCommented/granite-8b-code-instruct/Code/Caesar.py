
import string

class Main:
    def __init__(self):
        self.alphabet = string.ascii_lowercase

    def encode(self, message, shift):
        encoded = ""
        # Normalize the shift value to be within 0-25
        shift %= 26
        for char in message:
            if char in self.alphabet:
                encoded += self.alphabet[(self.alphabet.index(char) + shift) % 26]
            else:
                encoded += char
        return encoded

    def decode(self, encrypted_message, shift):
        decoded = ""
        # Normalize the shift value to be within 0-25
        shift %= 26
        for char in encrypted_message:
            if char in self.alphabet:
                decoded += self.alphabet[(self.alphabet.index(char) - shift) % 26]
            else:
                decoded += char
        return decoded

    def bruteforce(self, encrypted_message):
        possible_solutions = []
        for i in range(27):
            possible_solutions.append(self.decode(encrypted_message, i))
        return possible_solutions

# Read the operation type (encode, decode, bruteforce) from the user input
operation = input().strip().lower()

# Check if the operation is to encode a message
if operation == "encode":
    # Read the plaintext message to be encoded
    plaintext = input()
    # Read the shift value for encoding
    shift = int(input())
    cipher = Main()
    # Output the encoded message
    print("Encoded Message:", cipher.encode(plaintext, shift))
# Check if the operation is to decode a message
elif operation == "decode":
    # Read the encrypted message to be decoded
    encrypted_text = input()
    # Read the shift value for decoding
    shift = int(input())
    cipher = Main()
    # Output the decoded message
    print("Decoded Message:", cipher.decode(encrypted_text, shift))
# Check if the operation is to perform a brute force attack
elif operation == "bruteforce":
    # Read the encrypted message for brute force decoding
    encrypted_text = input()
    cipher = Main()
    # Get all possible decoded messages using brute force
    possible_solutions = cipher.bruteforce(encrypted_text)
    # Print all possible solutions with their respective shift values
    for i, solution in enumerate(possible_solutions):
        print(f"Shift {i}: {solution}")
# Handle invalid operation input
else:
    print("Invalid operation. Please enter encode, decode, or bruteforce.")

# Translate the above Python code to Java and end with comment "