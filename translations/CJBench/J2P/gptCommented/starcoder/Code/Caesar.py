import sys

class Main:
    def __init__(self):
        self.shift = 0
        self.message = ""
        self.encryptedMessage = ""
        self.operation = ""
        self.possibleSolutions = []

    def main(self):
        # Read the operation type (encode, decode, bruteforce) from the user input
        self.operation = input("Enter the operation type (encode, decode, bruteforce): ").strip().lower()

        # Check if the operation is to encode a message
        if self.operation == "encode":
            # Read the plaintext message to be encoded
            self.message = input("Enter the plaintext message to be encoded: ")
            # Read the shift value for encoding
            self.shift = int(input("Enter the shift value for encoding: "))
            self.encode()
        # Check if the operation is to decode a message
        elif self.operation == "decode":
            # Read the encrypted message to be decoded
            self.encryptedMessage = input("Enter the encrypted message to be decoded: ")
            # Read the shift value for decoding
            self.shift = int(input("Enter the shift value for decoding: "))
            self.decode()
        # Check if the operation is to perform a brute force attack
        elif self.operation == "bruteforce":
            # Read the encrypted message for brute force decoding
            self.encryptedMessage = input("Enter the encrypted message for brute force decoding: ")
            self.bruteforce()
        # Handle invalid operation input
        else:
            print("Invalid operation. Please enter encode, decode, or bruteforce.")

    def encode(self):
        # Initialize the encoded message
        encoded = ""
        # Normalize the shift value to be within 0-25
        self.shift %= 26

        # Iterate through each character in the message
        for current in self.message:
            # Check if the character is a capital Latin letter
            if current.isupper():
                current = chr(ord(current) + self.shift) # Apply the shift
                # Wrap around if it exceeds 'Z'
                encoded += chr(ord(current) - 26) if ord(current) > ord('Z') else current
            # Check if the character is a small Latin letter
            elif current.islower():
                current = chr(ord(current) + self.shift) # Apply the shift
                # Wrap around if it exceeds 'z'
                encoded += chr(ord(current) - 26) if ord(current) > ord('z') else current
            # If it's neither, append the character as is
            else:
                encoded += current
        # Output the encoded message
        print("Encoded Message: " + encoded)

    def decode(self):
        # Initialize the decoded message
        decoded = ""
        # Normalize the shift value to be within 0-25
        self.shift %= 26

        # Iterate through each character in the encrypted message
        for current in self.encryptedMessage:
            # Check if the character is a capital Latin letter
            if current.isupper():
                current = chr(ord(current) - self.shift) # Apply the reverse shift
                # Wrap around if it goes below 'A'
                decoded += chr(ord(current) + 26) if ord(current) < ord('A') else current
            # Check if the character is a small Latin letter
            elif current.islower():
                current = chr(ord(current) - self.shift) # Apply the reverse shift
                # Wrap around if it goes below 'a'
                decoded += chr(ord(current) + 26) if ord(current) < ord('a') else current
            # If it's neither, append the character as is
            else:
                decoded += current
        # Output the decoded message
        print("Decoded Message: " + decoded)

    def bruteforce(self):
        # Try all shifts from 0 to 26
        for i in range(27):
            self.possibleSolutions.append(self.decode(self.encryptedMessage, i)) # Decode with the current shift
        # Print all possible solutions with their respective shift values
        for i in range(27):
            print("Shift " + str(i) + ": " + self.possibleSolutions[i])

if __name__ == "__main__":
    main = Main()
    main.main()

