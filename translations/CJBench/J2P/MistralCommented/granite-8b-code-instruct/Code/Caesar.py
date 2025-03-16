
import string

# This class contains the main method that starts the program
class Main:
    def __init__(self):
        pass

    def main(self):
        # Initialize a Scanner object to read user input
        operation = input().strip().lower()

        # Check which operation the user wants to perform
        if operation == "encode":
            # Read the plaintext and shift value from the input
            plaintext = input()
            shift = int(input())

            # Create an instance of the Main class to use the encode method
            cipher = Main()

            # Print the encoded message
            print("Encoded Message:", cipher.encode(plaintext, shift))
        elif operation == "decode":
            # Read the encrypted text and shift value from the input
            encrypted_text = input()
            shift = int(input())

            # Create an instance of the Main class to use the decode method
            cipher = Main()

            # Print the decoded message
            print("Decoded Message:", cipher.decode(encrypted_text, shift))
        elif operation == "bruteforce":
            # Read the encrypted text from the input
            encrypted_text = input()

            # Create an instance of the Main class to use the bruteforce method
            cipher = Main()

            # Get all possible solutions by brute-forcing
            possible_solutions = cipher.bruteforce(encrypted_text)

            # Print all possible solutions
            for i, solution in enumerate(possible_solutions):
                print("Shift", i, ":", solution)
        else:
            # If the user entered an invalid operation, print an error message
            print("Invalid operation. Please enter encode, decode, or bruteforce.")

    # Method to encode a message using a given shift value
    def encode(self, message, shift):
        encoded = ""

        # Make sure the shift value is within the valid range (0-25)
        shift %= 26

        # Iterate through each character in the message
        for current in message:
            # If the character is a capital Latin letter, add the shift value and handle the wrap-around
            if current.isupper():
                encoded += chr((ord(current) - 65 + shift) % 26 + 65)
            # If the character is a small Latin letter, add the shift value and handle the wrap-around
            elif current.islower():
                encoded += chr((ord(current) - 97 + shift) % 26 + 97)
            # If the character is not a letter, just append it to the encoded message
            else:
                encoded += current

        # Return the encoded message as a String
        return encoded

    # Method to decode a message using a given shift value
    def decode(self, encrypted_message, shift):
        decoded = ""

        # Make sure the shift value is within the valid range (0-25)
        shift %= 26

        # Iterate through each character in the encrypted message
        for current in encrypted_message:
            # If the character is a capital Latin letter, subtract the shift value and handle the wrap-around
            if current.isupper():
                decoded += chr((ord(current) - 65 - shift) % 26 + 65)
            # If the character is a small Latin letter, subtract the shift value and handle the wrap-around
            elif current.islower():
                decoded += chr((ord(current) - 97 - shift) % 26 + 97)
            # If the character is not a letter, just append it to the decoded message
            else:
                decoded += current

        # Return the decoded message as a String
        return decoded

    # Method to bruteforce the shift value for a given encrypted message
    def bruteforce(self, encrypted_message):
        all_the_answers = [""] * 27

        # Iterate through all possible shift values (0-25) and decode the message for each shift value
        for i in range(27):
            all_the_answers[i] = self.decode(encrypted_message, i)

        # Return the array of all possible decoded messages
        return all_the_answers

# Create an instance of the Main class and call the main method
Main().main()

