class Main:
    def __init__(self, to_convert=None):
        # Variable to hold the string that will be converted
        self.to_convert = to_convert

    # Getter method to retrieve the string to convert
    def get_string(self):
        return self.to_convert

    # Setter method to set the string to convert
    def set_string(self, to_convert):
        self.to_convert = to_convert

    # Method to check if a character is an uppercase letter
    def is_capital(self, ch):
        return 'A' <= ch <= 'Z'

    # Method to check if a character is a lowercase letter
    def is_small(self, ch):
        return 'a' <= ch <= 'z'

    # Method to convert the string by reversing the alphabetic characters
    def convert(self):
        converted_string = []  # List to hold the converted result
        # Iterate through each character in the string to convert
        for ch in self.to_convert:
            # If the character is lowercase, convert it to its reverse
            if self.is_small(ch):
                converted_string.append(chr(ord('z') - (ord(ch) - ord('a'))))
            # If the character is uppercase, convert it to its reverse
            elif self.is_capital(ch):
                converted_string.append(chr(ord('Z') - (ord(ch) - ord('A'))))
            # If the character is neither, append it unchanged
            else:
                converted_string.append(ch)
        return ''.join(converted_string)  # Return the converted string

# Main method to run the program
if __name__ == "__main__":
    input_text = input()  # Read input from the user
    cipher = Main(input_text)  # Create an instance of Main with the input text
    result = cipher.convert()  # Convert the input text
    print("Converted Text:", result)  # Print the converted text
