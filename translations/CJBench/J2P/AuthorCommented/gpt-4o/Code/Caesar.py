class Main:
    def encode(self, message, shift):
        encoded = []
        shift %= 26

        for current in message:
            if self.is_capital_latin_letter(current):
                current = chr((ord(current) - ord('A') + shift) % 26 + ord('A'))
                encoded.append(current)
            elif self.is_small_latin_letter(current):
                current = chr((ord(current) - ord('a') + shift) % 26 + ord('a'))
                encoded.append(current)
            else:
                encoded.append(current)
        return ''.join(encoded)

    def decode(self, encrypted_message, shift):
        decoded = []
        shift %= 26

        for current in encrypted_message:
            if self.is_capital_latin_letter(current):
                current = chr((ord(current) - ord('A') - shift) % 26 + ord('A'))
                decoded.append(current)
            elif self.is_small_latin_letter(current):
                current = chr((ord(current) - ord('a') - shift) % 26 + ord('a'))
                decoded.append(current)
            else:
                decoded.append(current)
        return ''.join(decoded)

    @staticmethod
    def is_capital_latin_letter(c):
        return 'A' <= c <= 'Z'

    @staticmethod
    def is_small_latin_letter(c):
        return 'a' <= c <= 'z'

    def bruteforce(self, encrypted_message):
        list_of_all_the_answers = []
        for i in range(27):
            list_of_all_the_answers.append(self.decode(encrypted_message, i))
        return list_of_all_the_answers


if __name__ == "__main__":
    operation = input().strip().lower()

    cipher = Main()

    if operation == "encode":
        plaintext = input()
        shift = int(input())
        print("Encoded Message:", cipher.encode(plaintext, shift))
    elif operation == "decode":
        encrypted_text = input("Enter the encrypted text:\n")
        shift = int(input("Enter the shift value:\n"))
        print("Decoded Message:", cipher.decode(encrypted_text, shift))
    elif operation == "bruteforce":
        encrypted_text = input("Enter the encrypted text:\n")
        possible_solutions = cipher.bruteforce(encrypted_text)
        print("Possible Decoded Messages:")
        for i, solution in enumerate(possible_solutions):
            print(f"Shift {i}: {solution}")
    else:
        print("Invalid operation. Please enter encode, decode, or bruteforce.")

# <END-OF-CODE>
