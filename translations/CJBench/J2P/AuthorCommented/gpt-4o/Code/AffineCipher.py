class AffineCipher:
    def __init__(self, a=17, b=20):
        self.a = a
        self.b = b
        self.m = 26  # Size of the alphabet

    def encrypt_message(self, msg):
        cipher = []
        for char in msg:
            if char != ' ':
                # Applying encryption formula (a * x + b) mod m
                encrypted_char = chr(((self.a * (ord(char) - ord('A')) + self.b) % self.m) + ord('A'))
                cipher.append(encrypted_char)
            else:
                cipher.append(char)
        return ''.join(cipher)

    def decrypt_cipher(self, cipher):
        msg = []
        a_inv = self.mod_inverse(self.a, self.m)

        for char in cipher:
            if char != ' ':
                # Applying decryption formula a^-1 * (y - b) mod m
                decrypted_char = chr(((a_inv * ((ord(char) - ord('A')) - self.b + self.m)) % self.m) + ord('A'))
                msg.append(decrypted_char)
            else:
                msg.append(char)

        return ''.join(msg)

    def mod_inverse(self, a, m):
        for i in range(m):
            if (a * i) % m == 1:
                return i
        return None  # Should not happen if a is coprime to m

if __name__ == "__main__":
    msg = input("Enter a message: ").upper()
    cipher = AffineCipher()

    # Encrypt the message
    cipher_text = cipher.encrypt_message(msg)
    print("Encrypted Message:", cipher_text)

    # Decrypt the ciphertext
    decrypted_text = cipher.decrypt_cipher(cipher_text)
    print("Decrypted Message:", decrypted_text)

# <END-OF-CODE>
