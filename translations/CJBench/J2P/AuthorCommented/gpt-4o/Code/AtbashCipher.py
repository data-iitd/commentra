class AtbashCipher:
    def __init__(self, text=None):
        self.to_convert = text

    def get_string(self):
        return self.to_convert

    def set_string(self, text):
        self.to_convert = text

    @staticmethod
    def is_capital(ch):
        return 'A' <= ch <= 'Z'

    @staticmethod
    def is_small(ch):
        return 'a' <= ch <= 'z'

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

if __name__ == "__main__":
    input_text = input("Enter text to convert: ")

    # Perform the Atbash cipher conversion
    cipher = AtbashCipher(input_text)
    result = cipher.convert()

    # Output the converted text
    print("Converted Text:", result)

# <END-OF-CODE>
