
import string

class Main:
    def __init__(self, str):
        self.toConvert = str

    def get_string(self):
        return self.toConvert

    def set_string(self, str):
        self.toConvert = str

    def is_capital(self, ch):
        return ch >= 'A' and ch <= 'Z'

    def is_small(self, ch):
        return ch >= 'a' and ch <= 'z'

    def convert(self):
        converted_string = ""
        for ch in self.toConvert:
            if self.is_small(ch):
                converted_string += chr(ord('z') - (ord(ch) - ord('a')))
            elif self.is_capital(ch):
                converted_string += chr(ord('Z') - (ord(ch) - ord('A')))
            else:
                converted_string += ch
        return converted_string

if __name__ == "__main__":
    input_text = input("Enter text to convert: ")
    cipher = Main(input_text)
    result = cipher.convert()
    print("Converted Text:", result)

