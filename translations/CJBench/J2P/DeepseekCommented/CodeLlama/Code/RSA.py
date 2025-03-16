import math
import random

class Main:
    # Private variables to store Main keys
    modulus = None
    privateKey = None
    publicKey = None

    # Constructor to initialize Main keys
    def __init__(self, bits):
        self.generateKeys(bits)  # Generate Main keys of the specified bit size

    # Method to encrypt a message using Main public key
    def encrypt(self, message):
        if not message:
            raise ValueError("Message is empty")
        # Convert message to BigInteger, encrypt it, and return as string
        return str((int(message) ** self.publicKey) % self.modulus)

    # Method to decrypt an encrypted message using Main private key
    def decrypt(self, encryptedMessage):
        if not encryptedMessage:
            raise ValueError("Message is empty")
        # Convert encrypted message to BigInteger, decrypt it, and convert back to string
        return str((int(encryptedMessage) ** self.privateKey) % self.modulus)

    # Method to generate Main keys of the specified bit size
    def generateKeys(self, bits):
        random.seed(100)
        # Generate two large prime numbers p and q
        p = random.randint(1 << (bits / 2 - 1), 1 << (bits / 2))
        q = random.randint(1 << (bits / 2 - 1), 1 << (bits / 2))
        # Calculate modulus as the product of p and q
        self.modulus = p * q
        # Calculate the totient function phi
        phi = (p - 1) * (q - 1)
        # Initialize public key to 3 and ensure it is coprime with phi
        self.publicKey = 3
        while phi % self.publicKey != 1:
            self.publicKey += 2
        # Calculate private key as the modular inverse of public key mod phi
        self.privateKey = self.publicKey ** -1 % phi

    # Main method to run the Main encryption/decryption application
    def main(self):
        # Read the number of bits for the key size
        bits = int(input())
        rsa = Main(bits)
        # Print the public key and modulus
        print("Public Key:", rsa.publicKey)
        print("Modulus:", rsa.modulus)
        # Read the operation (encrypt or decrypt) and the message
        operation = input()
        message = input()
        if operation.lower() == "encrypt":
            encryptedMessage = rsa.encrypt(message)
            print("Encrypted Message:", encryptedMessage)
        elif operation.lower() == "decrypt":
            decryptedMessage = rsa.decrypt(message)
            print("Decrypted Message:", decryptedMessage)
        else:
            print("Invalid operation")


if __name__ == "__main__":
    Main().main()
    print("