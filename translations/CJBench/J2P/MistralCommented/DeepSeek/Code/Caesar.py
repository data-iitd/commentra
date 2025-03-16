import sys

class Main:
    def encode(self, message, shift):
        encoded = []
        shift %= 26
        for char in message:
            if char.isupper():
                encoded_char = chr((ord(char) - ord('A') + shift) % 26 + ord('A'))
                encoded.append(encoded_char)
            elif char.islower():
                encoded_char = chr((ord(char) - ord('a') + shift) % 26 + ord('a'))
                encoded.append(encoded_char)
            else:
                encoded.append(char)
        return ''.join(encoded)

    def decode(self, encrypted_message, shift):
        decoded = []
        shift %= 26
        for char in encrypted_message:
            if char.isupper():
                decoded_char = chr((ord(char) - ord('A') - shift) % 26 + ord('A'))
                decoded.append(decoded_char)
            elif char.islower():
                decoded_char = chr((ord(char) - ord('a') - shift) % 26 + ord('a'))
                decoded.append(decoded_char)
            else:
                decoded.append(char)
        return ''.join(decoded)

    def bruteforce(self, encrypted_message):
        list_of_all_the_answers = [None] * 27
        for i in range(27):
            list_of_all_the_answers[i] = self.decode(encrypted_message, i)
        return list_of_all_the_answers

# Main function to run the program
def main():
    operation = input().strip().lower()
    if operation == "encode":
        plaintext = input()
        shift = int(input())
        cipher = Main()
        print("Encoded Message: " + cipher.encode(plaintext, shift))
    elif operation == "decode":
        encrypted_text = input()
        shift = int(input())
        cipher = Main()
        print("Decoded Message: " + cipher.decode(encrypted_text, shift))
    elif operation == "bruteforce":
        encrypted_text = input()
        cipher = Main()
        possible_solutions = cipher.bruteforce(encrypted_text)
        for i, solution in enumerate(possible_solutions):
            print(f"Shift {i}: {solution}")
    else:
        print("Invalid operation. Please enter encode, decode, or bruteforce.")

if __name__ == "__main__":
    main()
