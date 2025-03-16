import random
import sys

class Main:
    # Variables to hold the modulus, private key, and public key
    modulus = None
    privateKey = None
    publicKey = None

    # Constructor that initializes the Main keys based on the specified bit length
    def __init__(self, bits):
        self.generateKeys(bits)

    # Method to encrypt a message using the public key
    def encrypt(self, message):
        # Check if the message is empty and throw an exception if it is
        if message.strip() == "":
            raise Exception("Message is empty")
        # Convert the message to a BigInteger, encrypt it, and return the encrypted string
        return (int(message.encode("hex"), 16)).to_bytes(len(message) / 2, byteorder="big").encode("hex")

    # Method to decrypt an encrypted message using the private key
    def decrypt(self, encryptedMessage):
        # Check if the encrypted message is empty and throw an exception if it is
        if encryptedMessage.strip() == "":
            raise Exception("Message is empty")
        # Convert the encrypted message to a BigInteger, decrypt it, and return the original message
        return int(encryptedMessage, 16).to_bytes(len(encryptedMessage) / 2, byteorder="big").encode("hex")

    # Method to generate Main keys (public and private) based on the specified bit length
    def generateKeys(self, bits):
        # Generate two large prime numbers p and q
        p = random.SystemRandom().getrandbits(bits / 2)
        q = random.SystemRandom().getrandbits(bits / 2)
        
        # Calculate the modulus as p * q
        self.modulus = p * q
        
        # Calculate phi(n) = (p-1)(q-1)
        phi = (p - 1) * (q - 1)
        
        # Initialize the public key with a small odd number
        self.publicKey = 3
        
        # Ensure that publicKey is coprime to phi(n)
        while phi % self.publicKey!= 1:
            self.publicKey += 2
        
        # Calculate the private key as the modular inverse of publicKey mod phi(n)
        self.privateKey = pow(self.publicKey, -1, phi)

# Main method to run the Main encryption/decryption program
if __name__ == "__main__":
    # Read the bit length for key generation from user input
    bits = int(raw_input("Enter bit length for key generation: "))
    
    # Create an instance of Main to generate Main keys
    rsa = Main(bits)
    
    # Display the generated public key and modulus
    print "Public Key: " + str(rsa.publicKey)
    print "Modulus: " + str(rsa.modulus)
    
    # Read the operation type (encrypt or decrypt) from user input
    operation = raw_input("Enter operation (encrypt/decrypt): ")
    
    # Perform encryption if the user chose "encrypt"
    if operation.lower() == "encrypt":
        message = raw_input("Enter message to encrypt: ")
        encryptedMessage = rsa.encrypt(message) # Encrypt the message
        print "Encrypted Message: " + encryptedMessage # Display the encrypted message
    # Perform decryption if the user chose "decrypt"
    elif operation.lower() == "decrypt":
        encryptedMessage = raw_input("Enter encrypted message to decrypt: ")
        decryptedMessage = rsa.decrypt(encryptedMessage) # Decrypt the message
        print "Decrypted Message: " + decryptedMessage # Display the decrypted message
    # Handle invalid operation input
    else:
        print "Invalid operation"

