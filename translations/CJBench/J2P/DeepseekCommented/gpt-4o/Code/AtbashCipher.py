










class Main:
    def __init__(self, str=None):
        self.to_convert = str

    # Getter method to retrieve the string to be converted
    def get_string(self):
        return self.to_convert

    # Setter method to set the string to be converted
    def set_string(self, str):
        self.to_convert = str

    # Helper method to check if a character is uppercase
    def is_capital(self, ch):
        return 'A' <= ch <= 'Z'

    # Helper method to check if a character is lowercase
    def is_small(self, ch):
        return 'a' <= ch <= 'z'

    # Method to convert the string based on the given logic
    def convert(self):
        converted_string = []
        for ch in self.to_convert:
            if self.is_small(ch):
                converted_string.append(chr(ord('z') - (ord(ch) - ord('a'))))
            elif self.is_capital(ch):
                converted_string.append(chr(ord('Z') - (ord(ch) - ord('A'))))
            else:
                converted_string.append(ch)
        return ''.join(converted_string)

# Main method to run the program
if __name__ == "__main__":
    input_text = input()
    cipher = Main(input_text)
    result = cipher.convert()
    print("Converted Text:", result)

# <END-OF-CODE>
