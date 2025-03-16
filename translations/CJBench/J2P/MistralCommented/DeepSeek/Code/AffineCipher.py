class Main:
    a = 17
    b = 20

    @staticmethod
    def encrypt_message(msg: str) -> str:
        cipher = []
        for char in msg:
            if char != ' ':
                encrypted_char = chr(((Main.a * (ord(char) - ord('A')) + Main.b) % 26) + ord('A'))
                cipher.append(encrypted_char)
            else:
                cipher.append(char)
        return ''.join(cipher)

    @staticmethod
    def decrypt_cipher(cipher: str) -> str:
        msg = []
        a_inv = 0
        flag = 0

        for i in range(26):
            flag = (Main.a * i) % 26
            if flag == 1:
                a_inv = i
                break

        for char in cipher:
            if char != ' ':
                decrypted_char = chr(((a_inv * ((ord(char) - ord('A')) - Main.b + 26)) % 26) + ord('A'))
                msg.append(decrypted_char)
            else:
                msg.append(char)
        return ''.join(msg)


if __name__ == "__main__":
    import sys
    msg = input().upper()
    cipher_text = Main.encrypt_message(msg)
    print("Encrypted Message:", cipher_text)
    decrypted_text = Main.decrypt_cipher(cipher_text)
    print("Decrypted Message:", decrypted_text)
