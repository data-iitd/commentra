

class Main:
    def __init__(self, str):
        self.toConvert = str

    def get_string(self):
        return self.toConvert

    def set_string(self, str):
        self.toConvert = str

    def is_capital(self, ch):
        return ord(ch) >= ord('A') and ord(ch) <= ord('Z')

    def is_small(self, ch):
        return ord(ch) >= ord('a') and ord(ch) <= ord('z')

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
    input_text = input("Enter the text to be converted: ")
    cipher = Main(input_text)
    result = cipher.convert()
    print("Converted Text:", result)

This Python code also provides a clear structure with comments explaining each part, making it easier to understand and maintain.