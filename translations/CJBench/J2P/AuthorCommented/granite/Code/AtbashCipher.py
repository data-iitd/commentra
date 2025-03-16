

import string

class Main:
    def __init__(self, str):
        self.to_convert = str

    def get_string(self):
        return self.to_convert

    def set_string(self, str):
        self.to_convert = str

    def is_capital(self, ch):
        return ch.isupper()

    def is_small(self, ch):
        return ch.islower()

    def convert(self):
        converted_string = ""

        for ch in self.to_convert:
            if self.is_small(ch):
                converted_string += chr(ord('z') - (ord(ch) - ord('a')))
            elif self.is_capital(ch):
                converted_string += chr(ord('Z') - (ord(ch) - ord('A')))
            else:
                converted_string += ch

        return converted_string

if __name__ == "__main__":
    input_text = input("Enter the text to convert: ")
    cipher = Main(input_text)
    result = cipher.convert()
    print("Converted Text:", result)

