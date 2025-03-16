
import string

class VigenereCipher:
    """
    A Python implementation of the Vigenère Cipher.

    The Vigenère Cipher is a polyalphabetic substitution cipher that uses a
    keyword to shift letters in the plaintext by different amounts, depending
    on the corresponding character in the keyword. It wraps around the alphabet,
    ensuring the shifts are within 'A'-'Z' or 'a'-'z'.

    Non-alphabetic characters (like spaces, punctuation) are kept unchanged.

    Encryption Example:
    - Plaintext: "Hello World!"
    - Key: "suchsecret"
    - Encrypted Text: "Zynsg Yfvev!"

    Decryption Example:
    - Ciphertext: "Zynsg Yfvev!"
    - Key: "suchsecret"
    - Decrypted Text: "Hello World!"

    Wikipedia Reference:
    <a href="https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher">Vigenère Cipher - Wikipedia</a>

    @author straiffix
    @author beingmartinbmc
    """

    def __init__(self):
        self.alphabet = string.ascii_lowercase

    def encrypt(self, plaintext, key):
        """
        Encrypts a given message using the Vigenère Cipher with the specified key.
        Steps:
        1. Iterate over each character in the message.
        2. If the character is a letter, shift it by the corresponding character in the key.
        3. Preserve the case of the letter.
        4. Preserve non-alphabetic characters.
        5. Move to the next character in the key (cyclic).
        6. Return the encrypted message.

        @param plaintext The plaintext message to encrypt.
        @param key The keyword used for encryption.
        @throws IllegalArgumentException if the key is empty.
        @return The encrypted message.
        """
        if not key:
            raise ValueError("Key cannot be empty.")

        result = ""
        j = 0
        for i in range(len(plaintext)):
            c = plaintext[i]
            if c.isalpha():
                if c.isupper():
                    result += chr((ord(c) + ord(key[j].upper()) - 2 * ord('A')) % 26 + ord('A'))
                else:
                    result += chr((ord(c) + ord(key[j].lower()) - 2 * ord('a')) % 26 + ord('a'))
                j = (j + 1) % len(key)
            else:
                result += c

        return result

    def decrypt(self, ciphertext, key):
        """
        Decrypts a given message encrypted with the Vigenère Cipher using the specified key.
        Steps:
        1. Iterate over each character in the message.
        2. If the character is a letter, shift it back by the corresponding character in the key.
        3. Preserve the case of the letter.
        4. Preserve non-alphabetic characters.
        5. Move to the next character in the key (cyclic).
        6. Return the decrypted message.

        @param ciphertext The encrypted message to decrypt.
        @param key The keyword used for decryption.
        @throws IllegalArgumentException if the key is empty.
        @return The decrypted plaintext message.
        """
        if not key:
            raise ValueError("Key cannot be empty.")

        result = ""
        j = 0
        for i in range(len(ciphertext)):
            c = ciphertext[i]
            if c.isalpha():
                if c.isupper():
                    result += chr('Z' - (25 - (ord(c) - ord(key[j].upper()))) % 26)
                else:
                    result += chr('z' - (25 - (ord(c) - ord(key[j].lower()))) % 26)
                j = (j + 1) % len(key)
            else:
                result += c

        return result


if __name__ == "__main__":
    operation = input().lower()

    key = input()

    if operation == "encrypt":
        plaintext = input()
        cipher = VigenereCipher()
        encrypted = cipher.encrypt(plaintext, key)
        print("Encrypted Message: " + encrypted)
    elif operation == "decrypt":
        ciphertext = input()
        cipher = VigenereCipher()
        decrypted = cipher.decrypt(ciphertext, key)
        print("Decrypted Message: " + decrypted)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

