
import re

def main():
    operation = input().strip().lower()
    if operation == "encode":
        plaintext = input().strip()
        shift = int(input().strip())
        cipher = Main()
        print("Encoded Message: " + cipher.encode(plaintext, shift))
    elif operation == "decode":
        encryptedText = input().strip()
        shift = int(input().strip())
        cipher = Main()
        print("Decoded Message: " + cipher.decode(encryptedText, shift))
    elif operation == "bruteforce":
        encryptedText = input().strip()
        cipher = Main()
        possibleSolutions = cipher.bruteforce(encryptedText)
        print("Possible Decoded Messages:")
        for i in range(len(possibleSolutions)):
            print("Shift " + str(i) + ": " + possibleSolutions[i])
    else:
        print("Invalid operation. Please enter encode, decode, or bruteforce.")

class Main:
    def encode(self, message, shift):
        shift %= 26
        encoded = ""
        for current in message:
            if current.isupper():
                current += shift
                encoded += chr(current if current <= ord('Z') else current - 26)
            elif current.islower():
                current += shift
                encoded += chr(current if current <= ord('z') else current - 26)
            else:
                encoded += current
        return encoded

    def decode(self, encryptedMessage, shift):
        shift %= 26
        decoded = ""
        for current in encryptedMessage:
            if current.isupper():
                current -= shift
                decoded += chr(current if current >= ord('A') else current + 26)
            elif current.islower():
                current -= shift
                decoded += chr(current if current >= ord('a') else current + 26)
            else:
                decoded += current
        return decoded

    def bruteforce(self, encryptedMessage):
        listOfAllTheAnswers = []
        for i in range(27):
            listOfAllTheAnswers.append(self.decode(encryptedMessage, i))
        return listOfAllTheAnswers

if __name__ == "__main__":
    main()

