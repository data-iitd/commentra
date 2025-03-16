class Main:  # Main class representing the entry point of the Python application
    def __init__(self, str=None):  # Constructor that initializes the instance variable with the given string
        self.to_convert = str  # Instance variable to store the string to be converted

    def get_string(self):  # Getter method for the instance variable to_convert
        return self.to_convert

    def set_string(self, str):  # Setter method for the instance variable to_convert
        self.to_convert = str

    @staticmethod
    def is_capital(ch):  # Static method to check if a character is capital
        return 'A' <= ch <= 'Z'

    @staticmethod
    def is_small(ch):  # Static method to check if a character is small
        return 'a' <= ch <= 'z'

    def convert(self):  # Public method to convert the string to its ROT-13 encryption
        converted_string = []  # Create an empty list to store the converted string

        for ch in self.to_convert:  # Iterate through each character in the string to_convert
            if self.is_small(ch):  # If the character is small
                converted_string.append(chr(ord('z') - (ord(ch) - ord('a'))))  # Append the corresponding character in ROT-13 encryption scheme
            elif self.is_capital(ch):  # If the character is capital
                converted_string.append(chr(ord('Z') - (ord(ch) - ord('A'))))  # Append the corresponding character in ROT-13 encryption scheme
            else:  # If the character is neither small nor capital
                converted_string.append(ch)  # Append the character as it is

        return ''.join(converted_string)  # Return the converted string

if __name__ == "__main__":  # Main method to read input from standard input, convert it, and print the result
    input_text = input()  # Read a line of text from standard input
    cipher = Main(input_text)  # Create a Main object with the input text
    result = cipher.convert()  # Convert the input text to its ROT-13 encryption
    print("Converted Text:", result)  # Print the converted text to standard output











