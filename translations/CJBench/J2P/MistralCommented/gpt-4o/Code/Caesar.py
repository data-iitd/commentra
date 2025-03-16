class Main:
    def encode(self, message, shift):
        encoded = []

        # Make sure the shift value is within the valid range (0-25)
        shift %= 26

        # Iterate through each character in the message
        for current in message:
            # If the character is a capital Latin letter, add the shift value and handle the wrap-around
            if self.is_capital_latin_letter(current):
                current = chr((ord(current) - ord('A') + shift) % 26 + ord('A'))
                encoded.append(current)
            # If the character is a small Latin letter, add the shift value and handle the wrap-around
            elif self.is_small_latin_letter(current):
                current = chr((ord(current) - ord('a') + shift) % 26 + ord('a'))
                encoded.append(current)
            # If the character is not a letter, just append it to the encoded message
            else:
                encoded.append(current)

        # Return the encoded message as a string
        return ''.join(encoded)

    def decode(self, encrypted_message, shift):
        decoded = []

        # Make sure the shift value is within the valid range (0-25)
        shift %= 26

        # Iterate through each character in the encrypted message
        for current in encrypted_message:
            # If the character is a capital Latin letter, subtract the shift value and handle the wrap-around
            if self.is_capital_latin_letter(current):
                current = chr((ord(current) - ord('A') - shift) % 26 + ord('A'))
                decoded.append(current)
            # If the character is a small Latin letter, subtract the shift value and handle the wrap-around
            elif self.is_small_latin_letter(current):
                current = chr((ord(current) - ord('a') - shift) % 26 + ord('a'))
                decoded.append(current)
            # If the character is not a letter, just append it to the decoded message
            else:
                decoded.append(current)

        # Return the decoded message as a string
        return ''.join(decoded)

    @staticmethod
    def is_capital_latin_letter(c):
        # Return true if the character is a capital Latin letter, false otherwise
        return 'A' <= c <= 'Z'

    @staticmethod
    def is_small_latin_letter(c):
        # Return true if the character is a small Latin letter, false otherwise
        return 'a' <= c <= 'z'

    def bruteforce(self, encrypted_message):
        list_of_all_the_answers = []

        # Iterate through all possible shift values (0-25) and decode the message for each shift value
        for i in range(26):
            list_of_all_the_answers.append(self.decode(encrypted_message, i))

        # Return the list of all possible decoded messages
        return list_of_all_the_answers


if __name__ == "__main__":
    import sys

    # Initialize the main class
    cipher = Main()

    # Read the user's operation from the input
    operation = input().strip().lower()

    # Check which operation the user wants to perform
    if operation == "encode":
        # Read the plaintext and shift value from the input
        plaintext = input()
        shift = int(input())

        # Print the encoded message
        print("Encoded Message:", cipher.encode(plaintext, shift))
    elif operation == "decode":
        # Read the encrypted text and shift value from the input
        encrypted_text = input()
        shift = int(input())

        # Print the decoded message
        print("Decoded Message:", cipher.decode(encrypted_text, shift))
    elif operation == "bruteforce":
        # Read the encrypted text from the input
        encrypted_text = input()

        # Get all possible solutions by brute-forcing
        possible_solutions = cipher.bruteforce(encrypted_text)

        # Print all possible solutions
        for i, solution in enumerate(possible_solutions):
            print(f"Shift {i}: {solution}")
    else:
        # If the user entered an invalid operation, print an error message
        print("Invalid operation. Please enter encode, decode, or bruteforce.")
