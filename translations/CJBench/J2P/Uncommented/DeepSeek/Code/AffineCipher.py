class Main:
    a = 17
    b = 20

    @staticmethod
    def encrypt_message(msg):
        cipher = []
        for char in msg:
            if char != ' ':
                cipher.append(chr(((Main.a * (ord(char) - ord('A')) + Main.b) % 26) + ord('A')))
            else:
                cipher.append(char)
        return ''.join(cipher)

    @staticmethod
    def decrypt_cipher(cipher):
        msg = []
        a_inv = 0
        for i in range(26):
            if (Main.a * i) % 26 == 1:
                a_inv = i
                break
        for char in cipher:
            if char != ' ':
                msg.append(chr((a_inv * ((ord(char) - ord('A')) - Main.b + 26)) % 26 + ord('A')))
            else:
                msg.append(char)
        return ''.join(msg)

if __name__ == "__main__":
    msg = input().upper()
    cipher_text = Main.encrypt_message(msg)
    print("Encrypted Message:", cipher_text)
    decrypted_text = Main.decrypt_cipher(cipher_text)
    print("Decrypted Message:", decrypted_text)

# <END-OF-CODE>











