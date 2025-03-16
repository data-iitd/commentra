
import string

class Main:
    def __init__(self, text):
        self.text = text

    def convert(self):
        converted_text = ""
        for char in self.text:
            if char.isalpha():
                if char.islower():
                    converted_text += chr(ord('z') - (ord(char) - ord('a')))
                else:
                    converted_text += chr(ord('Z') - (ord(char) - ord('A')))
            else:
                converted_text += char
        return converted_text

def main():
    scanner = input("Enter plaintext to encrypt/decrypt: ")
    cipher = Main(scanner)
    result = cipher.convert()
    print("Converted Text:", result)

if __name__ == "__main__":
    main()

