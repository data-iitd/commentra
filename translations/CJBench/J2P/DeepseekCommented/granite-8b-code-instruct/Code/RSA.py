
import random
from Crypto.Util.number import *

class Main:
    # Private variables to store Main keys
    modulus = None
    privateKey = None
    publicKey = None

    # Constructor to initialize Main keys
    def __init__(self, bits):
        self.generateKeys(bits) # Generate Main keys of the specified bit size

    # Method to encrypt a message using Main public key
    def encrypt(self, message):
        if not message:
            raise ValueError("Message is empty")
        # Convert message to bytes, encrypt it, and return as string
        return long_to_bytes(pow(bytes_to_long(message), self.publicKey, self.modulus))

    # Method to decrypt an encrypted message using Main private key
    def decrypt(self, encryptedMessage):
        if not encryptedMessage:
            raise ValueError("Message is empty")
        # Convert encrypted message to long, decrypt it, and convert back to string
        return bytes_to_long(pow(long_to_bytes(encryptedMessage), self.privateKey, self.modulus))

    # Method to generate Main keys of the specified bit size
    def generateKeys(self, bits):
        random.seed()
        # Generate two large prime numbers p and q
        p = getPrime(bits // 2)
        q = getPrime(bits // 2)
        # Calculate modulus as the product of p and q
        self.modulus = p * q
        # Calculate the totient function phi
        phi = (p - 1) * (q - 1)
        # Initialize public key to 3 and ensure it is coprime with phi
        self.publicKey = 3
        while gcd(phi, self.publicKey) > 1:
            self.publicKey += 2
        # Calculate private key as the modular inverse of public key mod phi
        self.privateKey = inverse(self.publicKey, phi)

# Main method to run the Main encryption/decryption application
def main():
    bits = int(input("Enter the number of bits for the key size: "))
    rsa = Main(bits)
    # Print the public key and modulus
    print("Public Key:", rsa.publicKey)
    print("Modulus:", rsa.modulus)
    # Read the operation (encrypt or decrypt) and the message
    operation = input("Enter the operation (encrypt or decrypt): ")
    message = input("Enter the message: ")
    if operation.lower() == "encrypt":
        encryptedMessage = rsa.encrypt(message)
        print("Encrypted Message:", encryptedMessage)
    elif operation.lower() == "decrypt":
        encryptedMessage = int(input("Enter the encrypted message: "))
        decryptedMessage = rsa.decrypt(encryptedMessage)
        print("Decrypted Message:", decryptedMessage)
    else:
        print("Invalid operation")

if __name__ == "__main__":
    main()

