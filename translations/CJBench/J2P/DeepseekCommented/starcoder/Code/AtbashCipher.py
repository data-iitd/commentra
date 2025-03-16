
class Main:
    def __init__(self, toConvert):
        self.toConvert = toConvert
    # Getter method to retrieve the string to be converted
    def getString(self):
        return self.toConvert
    # Setter method to set the string to be converted
    def setString(self, str):
        self.toConvert = str
    # Helper method to check if a character is uppercase
    def isCapital(self, ch):
        return ch >= 'A' and ch <= 'Z'
    # Helper method to check if a character is lowercase
    def isSmall(self, ch):
        return ch >= 'a' and ch <= 'z'
    # Method to convert the string based on the given logic
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
# Main method to run the program
if __name__ == "__main__":
    inputText = input()
    cipher = Main(inputText)
    result = cipher.convert()
    print("Converted Text: " + result)

