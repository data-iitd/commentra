import sys; # Import sys module to read input from standard input

class Main: # Main class representing the entry point of the Python application
    def __init__(self, str): # Constructor that initializes the instance variable with the given string
        self.toConvert = str;

    def getString(self): # Getter method for the instance variable toConvert
        return self.toConvert;

    def setString(self, str): # Setter method for the instance variable toConvert
        self.toConvert = str;

    def isCapital(self, ch): # Private helper method to check if a character is capital
        return ch >= 'A' and ch <= 'Z';

    def isSmall(self, ch): # Private helper method to check if a character is small
        return ch >= 'a' and ch <= 'z';

    def convert(self): # Public method to convert the string to its ROT-13 encryption
        convertedString = ''; # Create an empty string to store the converted string

        for ch in self.toConvert: # Iterate through each character in the string toConvert
            if self.isSmall(ch): # If the character is small
                convertedString += chr(ord('z') - (ord(ch) - ord('a'))); # Append the corresponding character in ROT-13 encryption scheme
            elif self.isCapital(ch): # If the character is capital
                convertedString += chr(ord('Z') - (ord(ch) - ord('A'))); # Append the corresponding character in ROT-13 encryption scheme
            else: # If the character is neither small nor capital
                convertedString += ch; # Append the character as it is
        return convertedString; # Return the converted string

if __name__ == "__main__": # Main method to read input from standard input, convert it, and print the result
    inputText = sys.stdin.readline(); # Read a line of text from standard input
    cipher = Main(inputText); # Create a Main object with the input text
    result = cipher.convert(); # Convert the input text to its ROT-13 encryption
    print("Converted Text: " + result); # Print the converted text to standard output

