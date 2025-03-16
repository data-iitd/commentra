import random
import sys

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
        if message == "":
            raise Exception("Message is empty")
        # Convert message to BigInteger, encrypt it, and return as string
        return (int(message.encode('hex'), 16)).to_bytes(len(message) / 2, byteorder='big').encode('hex')

    # Method to decrypt an encrypted message using Main private key
    def decrypt(self, encryptedMessage):
        if encryptedMessage == "":
            raise Exception("Message is empty")
        # Convert encrypted message to BigInteger, decrypt it, and convert back to string
        return int(encryptedMessage, 16).to_bytes(len(encryptedMessage) / 2, byteorder='big').encode('hex')

    # Method to generate Main keys of the specified bit size
    def generateKeys(self, bits):
        random.seed()
        # Generate two large prime numbers p and q
        p = random.getrandbits(bits / 2)
        q = random.getrandbits(bits / 2)
        # Calculate modulus as the product of p and q
        self.modulus = p * q
        # Calculate the totient function phi
        phi = (p - 1) * (q - 1)
        # Initialize public key to 3 and ensure it is coprime with phi
        self.publicKey = 3
        while (phi % self.publicKey)!= 1:
            self.publicKey += 2
        # Calculate private key as the modular inverse of public key mod phi
        self.privateKey = pow(self.publicKey, -1, phi)

if __name__ == "__main__":
    # Read the number of bits for the key size
    bits = int(sys.argv[1])
    rsa = Main(bits)
    # Print the public key and modulus
    print "Public Key: " + str(rsa.publicKey)
    print "Modulus: " + str(rsa.modulus)
    # Read the operation (encrypt or decrypt) and the message
    operation = sys.argv[2]
    message = sys.argv[3]
    if operation.lower() == "encrypt":
        encryptedMessage = rsa.encrypt(message)
        print "Encrypted Message: " + encryptedMessage
    elif operation.lower() == "decrypt":
        decryptedMessage = rsa.decrypt(message)
        print "Decrypted Message: " + decryptedMessage
    else:
        print "Invalid operation"

