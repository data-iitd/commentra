import sys

# This class contains the main method that starts the program
class Main:
    # This method contains the main logic of the program
    def main(self):
        # Read the user's operation from the input
        operation = sys.stdin.readline().strip().lower()

        # Check which operation the user wants to perform
        if operation == "encode":
            # Read the plaintext and shift value from the input
            plaintext = sys.stdin.readline().strip()
            shift = int(sys.stdin.readline().strip())

            # Create an instance of the Main class to use the encode method
            cipher = Main()

            # Print the encoded message
            print("Encoded Message: " + cipher.encode(plaintext, shift))
        elif operation == "decode":
            # Read the encrypted text and shift value from the input
            encryptedText = sys.stdin.readline().strip()
            shift = int(sys.stdin.readline().strip())

            # Create an instance of the Main class to use the decode method
            cipher = Main()

            # Print the decoded message
            print("Decoded Message: " + cipher.decode(encryptedText, shift))
        elif operation == "bruteforce":
            # Read the encrypted text from the input
            encryptedText = sys.stdin.readline().strip()

            # Create an instance of the Main class to use the bruteforce method
            cipher = Main()

            # Get all possible solutions by brute-forcing
            possibleSolutions = cipher.bruteforce(encryptedText)

            # Print all possible solutions
            for i in range(0, len(possibleSolutions)):
                print("Shift " + str(i) + ": " + possibleSolutions[i])
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
                current = chr(ord(current) + shift)
                encoded += chr(ord(current) - 26) if current > 'Z' else current
            # If the character is a small Latin letter, add the shift value and handle the wrap-around
            elif current.islower():
                current = chr(ord(current) + shift)
                encoded += chr(ord(current) - 26) if current > 'z' else current
            # If the character is not a letter, just append it to the encoded message
            else:
                encoded += current

        # Return the encoded message as a String
        return encoded

    # Method to decode a message using a given shift value
    def decode(self, encryptedMessage, shift):
        decoded = ""

        # Make sure the shift value is within the valid range (0-25)
        shift %= 26

        # Iterate through each character in the encrypted message
        for current in encryptedMessage:
            # If the character is a capital Latin letter, subtract the shift value and handle the wrap-around
            if current.isupper():
                current = chr(ord(current) - shift)
                decoded += chr(ord(current) + 26) if current < 'A' else current
            # If the character is a small Latin letter, subtract the shift value and handle the wrap-around
            elif current.islower():
                current = chr(ord(current) - shift)
                decoded += chr(ord(current) + 26) if current < 'a' else current
            # If the character is not a letter, just append it to the decoded message
            else:
                decoded += current

        # Return the decoded message as a String
        return decoded

    # Method to bruteforce the shift value for a given encrypted message
    def bruteforce(self, encryptedMessage):
        listOfAllTheAnswers = [""] * 27

        # Iterate through all possible shift values (0-25) and decode the message for each shift value
        for i in range(0, 26):
            listOfAllTheAnswers[i] = self.decode(encryptedMessage, i)

        # Return the array of all possible decoded messages
        return listOfAllTheAnswers

# This is the entry point of the program
if __name__ == "__main__":
    # Create an instance of the Main class to start the program
    Main().main()

