class SimpleSubstitutionCipher:
    def encode(self, message, cipher_small):
        encoded = []
        cipher_map = {}

        begin_small_letter = ord('a')
        begin_capital_letter = ord('A')

        cipher_small = cipher_small.lower()
        cipher_capital = cipher_small.upper()

        # Create cipher map for encoding
        for i in range(len(cipher_small)):
            cipher_map[chr(begin_small_letter)] = cipher_small[i]
            cipher_map[chr(begin_capital_letter)] = cipher_capital[i]
            begin_small_letter += 1
            begin_capital_letter += 1

        for char in message:
            if char.isalpha():
                encoded.append(cipher_map[char])
            else:
                encoded.append(char)

        return ''.join(encoded)

    def decode(self, encrypted_message, cipher_small):
        decoded = []
        cipher_map = {}

        begin_small_letter = ord('a')
        begin_capital_letter = ord('A')

        cipher_small = cipher_small.lower()
        cipher_capital = cipher_small.upper()

        # Create cipher map for decoding
        for i in range(len(cipher_small)):
            cipher_map[cipher_small[i]] = chr(begin_small_letter)
            cipher_map[cipher_capital[i]] = chr(begin_capital_letter)
            begin_small_letter += 1
            begin_capital_letter += 1

        for char in encrypted_message:
            if char.isalpha():
                decoded.append(cipher_map[char])
            else:
                decoded.append(char)

        return ''.join(decoded)


if __name__ == "__main__":
    cipher = SimpleSubstitutionCipher()

    cipher_alphabet = input()
    operation = input()

    if operation.lower() == "encode":
        message = input()
        encrypted_message = cipher.encode(message, cipher_alphabet)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decode":
        encrypted_message = input()
        decrypted_message = cipher.decode(encrypted_message, cipher_alphabet)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.")

# <END-OF-CODE>
