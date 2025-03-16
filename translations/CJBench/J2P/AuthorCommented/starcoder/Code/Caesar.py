
import sys

class Main:
    def __init__(self):
        self.operation = ""
        self.plaintext = ""
        self.shift = 0
        self.encryptedMessage = ""
        self.possibleSolutions = []

    def main(self):
        self.operation = sys.stdin.readline().strip().lower()
        if self.operation == "encode":
            self.plaintext = sys.stdin.readline().strip()
            self.shift = int(sys.stdin.readline().strip())
            self.encryptedMessage = self.encode(self.plaintext, self.shift)
            print("Encoded Message: " + self.encryptedMessage)
        elif self.operation == "decode":
            self.encryptedMessage = sys.stdin.readline().strip()
            self.shift = int(sys.stdin.readline().strip())
            print("Decoded Message: " + self.decode(self.encryptedMessage, self.shift))
        elif self.operation == "bruteforce":
            self.encryptedMessage = sys.stdin.readline().strip()
            self.possibleSolutions = self.bruteforce(self.encryptedMessage)
            print("Possible Decoded Messages:")
            for i in range(0, len(self.possibleSolutions)):
                print("Shift " + str(i) + ": " + self.possibleSolutions[i])
        else:
            print("Invalid operation. Please enter encode, decode, or bruteforce.")

    def encode(self, message, shift):
        encoded = ""
        shift %= 26
        for current in message:
            if current.isupper():
                current = chr((ord(current) + shift - 65) % 26 + 65)
            elif current.islower():
                current = chr((ord(current) + shift - 97) % 26 + 97)
            encoded += current
        return encoded

    def decode(self, encryptedMessage, shift):
        decoded = ""
        shift %= 26
        for current in encryptedMessage:
            if current.isupper():
                current = chr((ord(current) - shift - 65) % 26 + 65)
            elif current.islower():
                current = chr((ord(current) - shift - 97) % 26 + 97)
            decoded += current
        return decoded

    def bruteforce(self, encryptedMessage):
        listOfAllTheAnswers = [""] * 27
        for i in range(0, 26):
            listOfAllTheAnswers[i] = self.decode(encryptedMessage, i)
        return listOfAllTheAnswers

if __name__ == "__main__":
    Main().main()

