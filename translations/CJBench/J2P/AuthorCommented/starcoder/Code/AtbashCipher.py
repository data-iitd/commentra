
import sys

class Main:
    def __init__(self, toConvert):
        self.toConvert = toConvert

    def getString(self):
        return self.toConvert

    def setString(self, toConvert):
        self.toConvert = toConvert

    def isCapital(self, ch):
        return ch >= 'A' and ch <= 'Z'

    def isSmall(self, ch):
        return ch >= 'a' and ch <= 'z'

    def convert(self):
        convertedString = ""
        for ch in self.toConvert:
            if self.isSmall(ch):
                convertedString += chr(ord('z') - (ord(ch) - ord('a')))
            elif self.isCapital(ch):
                convertedString += chr(ord('Z') - (ord(ch) - ord('A')))
            else:
                convertedString += ch
        return convertedString

if __name__ == "__main__":
    # Input plaintext to encrypt/decrypt
    inputText = sys.stdin.readline().strip()

    # Perform the Atbash cipher conversion
    cipher = Main(inputText)
    result = cipher.convert()

    # Output the converted text
    print("Converted Text: " + result)

