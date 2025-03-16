
import sys
import string

class Main:
    def __init__(self):
        self.operation = ""
        self.plaintext = ""
        self.shift = 0
        self.encryptedText = ""
        self.possibleSolutions = []

    def main(self):
        self.operation = sys.stdin.readline().strip().lower()
        if self.operation == "encode":
            self.plaintext = sys.stdin.readline().strip()
            self.shift = int(sys.stdin.readline().strip())
            self.cipher = Main()
            print("Encoded Message: " + self.cipher.encode(self.plaintext, self.shift))
        elif self.operation == "decode":
            print("Enter the encrypted text:")
            self.encryptedText = sys.stdin.readline().strip()
            print("Enter the shift value:")
            self.shift = int(sys.stdin.readline().strip())
            self.cipher = Main()
            print("Decoded Message: " + self.cipher.decode(self.encryptedText, self.shift))
        elif self.operation == "bruteforce":
            print("Enter the encrypted text:")
            self.encryptedText = sys.stdin.readline().strip()
            self.cipher = Main()
            self.possibleSolutions = self.cipher.bruteforce(self.encryptedText)
            print("Possible Decoded Messages:")
            for i in range(0, len(self.possibleSolutions)):
                print("Shift " + str(i) + ": " + self.possibleSolutions[i])
        else:
            print("Invalid operation. Please enter encode, decode, or bruteforce.")

    def encode(self, message, shift):
        encoded = ""
        shift %= 26
        for current in message:
            if current in string.ascii_uppercase:
                current = chr(ord(current) + shift)
                encoded += current if current <= 'Z' else chr(ord(current) - 26)
            elif current in string.ascii_lowercase:
                current = chr(ord(current) + shift)
                encoded += current if current <= 'z' else chr(ord(current) - 26)
            else:
                encoded += current
        return encoded

    def decode(self, encryptedMessage, shift):
        decoded = ""
        shift %= 26
        for current in encryptedMessage:
            if current in string.ascii_uppercase:
                current = chr(ord(current) - shift)
                decoded += current if current >= 'A' else chr(ord(current) + 26)
            elif current in string.ascii_lowercase:
                current = chr(ord(current) - shift)
                decoded += current if current >= 'a' else chr(ord(current) + 26)
            else:
                decoded += current
        return decoded

    def bruteforce(self, encryptedMessage):
        listOfAllTheAnswers = [""] * 27
        for i in range(0, 27):
            listOfAllTheAnswers[i] = self.decode(encryptedMessage, i)
        return listOfAllTheAnswers

if __name__ == "__main__":
    main = Main()
    main.main()

