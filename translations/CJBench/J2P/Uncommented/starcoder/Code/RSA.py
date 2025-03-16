
import random
import math
import sys

class Main:
    def __init__(self, bits):
        self.generateKeys(bits)

    def encrypt(self, message):
        if message == "":
            raise Exception("Message is empty")
        return (int(message.encode("hex"), 16) ** self.publicKey) % self.modulus

    def decrypt(self, encryptedMessage):
        if encryptedMessage == "":
            raise Exception("Message is empty")
        return hex(int(encryptedMessage, 16) ** self.privateKey % self.modulus)[2:].decode("hex")

    def generateKeys(self, bits):
        random.seed()
        p = random.getrandbits(bits / 2)
        q = random.getrandbits(bits / 2)
        self.modulus = p * q
        phi = (p - 1) * (q - 1)
        self.publicKey = 3
        while math.gcd(phi, self.publicKey) > 1:
            self.publicKey += 2
        self.privateKey = pow(self.publicKey, -1, phi)

if __name__ == "__main__":
    bits = int(sys.argv[1])
    rsa = Main(bits)
    print "Public Key: " + str(rsa.publicKey)
    print "Modulus: " + str(rsa.modulus)
    operation = sys.argv[2]
    if operation.lower() == "encrypt":
        message = sys.stdin.read()
        encryptedMessage = rsa.encrypt(message)
        print "Encrypted Message: " + str(encryptedMessage)
    elif operation.lower() == "decrypt":
        encryptedMessage = int(sys.stdin.read())
        decryptedMessage = rsa.decrypt(encryptedMessage)
        print "Decrypted Message: " + decryptedMessage
    else:
        print "Invalid operation"

