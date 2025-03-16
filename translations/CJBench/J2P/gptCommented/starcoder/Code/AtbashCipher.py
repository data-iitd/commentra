import java.util.Scanner;

class Main:
    # Variable to hold the string that will be converted
    toConvert = ""

    # Default constructor
    def __init__(self):
        pass

    # Constructor that initializes the string to convert
    def __init__(self, str):
        self.toConvert = str

    # Getter method to retrieve the string to convert
    def getString(self):
        return self.toConvert

    # Setter method to set the string to convert
    def setString(self, str):
        self.toConvert = str

    # Method to check if a character is an uppercase letter
    def isCapital(self, ch):
        return ch >= 'A' and ch <= 'Z'

    # Method to check if a character is a lowercase letter
    def isSmall(self, ch):
        return ch >= 'a' and ch <= 'z'

    # Method to convert the string by reversing the alphabetic characters
    def convert(self):
        convertedString = "" # StringBuilder to hold the converted result
        # Iterate through each character in the string to convert
        for ch in self.toConvert:
            # If the character is lowercase, convert it to its reverse
            if self.isSmall(ch):
                convertedString += chr(ord('z') - (ord(ch) - ord('a')))
            # If the character is uppercase, convert it to its reverse
            elif self.isCapital(ch):
                convertedString += chr(ord('Z') - (ord(ch) - ord('A')))
            # If the character is neither, append it unchanged
            else:
                convertedString += ch
        return convertedString # Return the converted string

# Main method to run the program
if __name__ == "__main__":
    scanner = Scanner(System.in) # Create a Scanner object for input
    inputText = scanner.nextLine() # Read input from the user
    cipher = Main(inputText) # Create an instance of Main with the input text
    result = cipher.convert() # Convert the input text
    print("Converted Text: " + result) # Print the converted text
    scanner.close() # Close the scanner to free resources

