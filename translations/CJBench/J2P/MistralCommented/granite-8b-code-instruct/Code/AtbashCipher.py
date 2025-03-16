
import sys # Import the sys module for reading input from standard input

class Main: # Main class representing the entry point of the Python application
    def __init__(self, str): # Constructor that initializes the instance variable toConvert with the given string
        self.toConvert = str

    def get_string(self): # Getter method for the instance variable toConvert
        return self.toConvert

    def set_string(self, str): # Setter method for the instance variable toConvert
        self.toConvert = str

    def is_capital(self, ch): # Private helper method to check if a character is capital
        return ch >= 'A' and ch <= 'Z'

    def is_small(self, ch): # Private helper method to check if a character is small
        return ch >= 'a' and ch <= 'z'

    def convert(self): # Public method to convert the string to its ROT-13 encryption
        converted_string = "" # Initialize an empty string to store the converted string

        for ch in self.toConvert: # Iterate through each character in the string toConvert
            if self.is_small(ch): # If the character is small
                converted_string += chr(ord('z') - (ord(ch) - ord('a'))) # Append the corresponding character in ROT-13 encryption scheme
            elif self.is_capital(ch): # If the character is capital
                converted_string += chr(ord('Z') - (ord(ch) - ord('A'))) # Append the corresponding character in ROT-13 encryption scheme
            else: # If the character is neither small nor capital
                converted_string += ch # Append the character as it is

        return converted_string # Return the converted string

    def main(): # Main method to read input from standard input, convert it, and print the result
        input_text = sys.stdin.readline().strip() # Read a line of text from standard input
        cipher = Main(input_text) # Create a Main object with the input text
        result = cipher.convert() # Convert the input text to its ROT-13 encryption
        print("Converted Text: " + result) # Print the converted text to standard output

if __name__ == "__main__": # Call the main method if the script is executed directly
    Main.main() # Call the main method of the Main class

