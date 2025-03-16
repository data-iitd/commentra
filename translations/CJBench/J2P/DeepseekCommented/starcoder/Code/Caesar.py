import sys

class Main:
    def __init__(self):
        self.operation = ""
        self.plaintext = ""
        self.shift = 0
        self.encryptedText = ""
        self.possibleSolutions = []

    def main(self):
        # Read the operation type from the input
        self.operation = sys.stdin.readline().strip().lower()
        # Check which operation is selected and proceed accordingly
        if self.operation == "encode":
            # Read the plaintext message from the input
            self.plaintext = sys.stdin.readline().strip()
            # Read the shift value from the input
            self.shift = int(sys.stdin.readline().strip())
            # Call the encode method
            self.encode()
        elif self.operation == "decode":
            # Read the encrypted message from the input
            self.encryptedText = sys.stdin.readline().strip()
            # Read the shift value from the input
            self.shift = int(sys.stdin.readline().strip())
            # Call the decode method
            self.decode()
        elif self.operation == "bruteforce":
            # Read the encrypted message from the input
            self.encryptedText = sys.stdin.readline().strip()
            # Call the bruteforce method
            self.bruteforce()
        else:
            # Print an error message if the operation is invalid
            print("Invalid operation. Please enter encode, decode, or bruteforce.")

    def encode(self):
        # Initialize the encoded message
        encoded = ""
        # Normalize the shift value to ensure it is within the range of 0-25
        self.shift %= 26
        # Iterate over each character in the message
        for current in self.plaintext:
            # Check if the character is an uppercase Latin letter and shift it
            if self.isCapitalLatinLetter(current):
                current = chr(ord(current) + self.shift)
                encoded += current if current <= 'Z' else chr(ord(current) - 26)
            elif self.isSmallLatinLetter(current): # Check if the character is a lowercase Latin letter and shift it
                current = chr(ord(current) + self.shift)
                encoded += current if current <= 'z' else chr(ord(current) - 26)
            else:
                # Append the character as is if it is not a Latin letter
                encoded += current
        # Print the encoded message
        print("Encoded Message: " + encoded)

    def decode(self):
        # Initialize the decoded message
        decoded = ""
        # Normalize the shift value to ensure it is within the range of 0-25
        self.shift %= 26
        # Iterate over each character in the encrypted message
        for current in self.encryptedText:
            # Check if the character is an uppercase Latin letter and shift it back
            if self.isCapitalLatinLetter(current):
                current = chr(ord(current) - self.shift)
                decoded += current if current >= 'A' else chr(ord(current) + 26)
            elif self.isSmallLatinLetter(current): # Check if the character is a lowercase Latin letter and shift it back
                current = chr(ord(current) - self.shift)
                decoded += current if current >= 'a' else chr(ord(current) + 26)
            else:
                # Append the character as is if it is not a Latin letter
                decoded += current
        # Print the decoded message
        print("Decoded Message: " + decoded)

    def bruteforce(self):
        # Attempt to decode the message using each possible shift
        for i in range(27):
            self.possibleSolutions.append(self.decode(i))
        # Print each decoded message with its corresponding shift
        for i in range(27):
            print("Shift " + str(i) + ": " + self.possibleSolutions[i])

    def isCapitalLatinLetter(self, c):
        return c >= 'A' and c <= 'Z'

    def isSmallLatinLetter(self, c):
        return c >= 'a' and c <= 'z'

if __name__ == "__main__":
    Main().main()

