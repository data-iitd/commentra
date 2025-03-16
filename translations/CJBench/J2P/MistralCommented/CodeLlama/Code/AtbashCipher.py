import sys

class Main:
    def __init__(self, str):
        self.toConvert = str

    def getString(self):
        return self.toConvert

    def setString(self, str):
        self.toConvert = str

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

def main():
    inputText = sys.stdin.readline()
    cipher = Main(inputText)
    result = cipher.convert()
    print("Converted Text: " + result)

if __name__ == "__main__":
    main()

