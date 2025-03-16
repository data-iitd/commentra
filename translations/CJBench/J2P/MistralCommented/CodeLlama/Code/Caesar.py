
# This class contains the main method that starts the program
class Main:
    # Method to encode a message using a given shift value
    def encode(self, message, shift):
        encoded = ""

        # Make sure the shift value is within the valid range (0-25)
        shift %= 26

        # Iterate through each character in the message
        for current in message:
            # If the character is a capital Latin letter, add the shift value and handle the wrap-around
            if current.isupper():
                current = chr((ord(current) + shift - 65) % 26 + 65)
                encoded += current
            # If the character is a small Latin letter, add the shift value and handle the wrap-around
            elif current.islower():
                current = chr((ord(current) + shift - 97) % 26 + 97)
                encoded += current
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
                current = chr((ord(current) - shift - 65) % 26 + 65)
                decoded += current
            # If the character is a small Latin letter, subtract the shift value and handle the wrap-around
            elif current.islower():
                current = chr((ord(current) - shift - 97) % 26 + 97)
                decoded += current
            # If the character is not a letter, just append it to the decoded message
            else:
                decoded += current

        # Return the decoded message as a String
        return decoded

    # Helper method to check if a character is a capital Latin letter
    def is_capital_latin_letter(self, c):
        # Return true if the character is a capital Latin letter, false otherwise
        return c.isupper()

    # Helper method to check if a character is a small Latin letter
    def is_small_latin_letter(self, c):
        # Return true if the character is a small Latin letter, false otherwise
        return c.islower()

    # Method to bruteforce the shift value for a given encrypted message
    def bruteforce(self, encrypted_message):
        list_of_all_the_answers = []

        # Iterate through all possible shift values (0-25) and decode the message for each shift value
        for i in range(0, 27):
            list_of_all_the_answers.append(self.decode(encrypted_message, i))

        # Return the array of all possible decoded messages
        return list_of_all_the_answers


# This is the main method that starts the program
def main():
    # Initialize a Scanner object to read user input
    scanner = Scanner(System.in)

    # Read the user's operation from the input
    operation = scanner.nextLine().trim().toLowerCase()

    # Check which operation the user wants to perform
    if operation == "encode":
        # Read the plaintext and shift value from the input
        plaintext = scanner.nextLine()
        shift = scanner.nextInt()

        # Create an instance of the Main class to use the encode method
        cipher = Main()

        # Print the encoded message
        print("Encoded Message: " + cipher.encode(plaintext, shift))
    elif operation == "decode":
        # Read the encrypted text and shift value from the input
        encrypted_text = scanner.nextLine()
        shift = scanner.nextInt()

        # Create an instance of the Main class to use the decode method
        cipher = Main()

        # Print the decoded message
        print("Decoded Message: " + cipher.decode(encrypted_text, shift))
    elif operation == "bruteforce":
        # Read the encrypted text from the input
        encrypted_text = scanner.nextLine()

        # Create an instance of the Main class to use the bruteforce method
        cipher = Main()

        # Get all possible solutions by brute-forcing
        possible_solutions = cipher.bruteforce(encrypted_text)

        # Print all possible solutions
        for i in range(0, len(possible_solutions)):
            print("Shift " + str(i) + ": " + possible_solutions[i])
    else:
        # If the user entered an invalid operation, print an error message
        print("Invalid operation. Please enter encode, decode, or bruteforce.")

    # Close the Scanner object
    scanner.close()


# This is the entry point for the program
if __name__ == "__main__":
    main()


