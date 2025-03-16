
import binascii
import sys

# Converts a byte array to a hexadecimal string
def bytesToHex(bytes):
    return binascii.hexlify(bytes).decode('utf-8')

# Converts a hexadecimal string to a byte array
def hexToBytes(hex):
    return binascii.unhexlify(hex)

# Applies the XOR operation between the input bytes and the key bytes.
# If the key is shorter than the input, it wraps around (cyclically).
def xor(inputBytes, keyBytes):
    outputBytes = bytearray(inputBytes)
    for i in range(len(inputBytes)):
        outputBytes[i] ^= keyBytes[i % len(keyBytes)]
    return outputBytes

# Encrypts the given plaintext using the XOR cipher with the specified key.
# The result is a hexadecimal-encoded string representing the ciphertext.
def encrypt(plainText, key):
    if key == "":
        raise Exception("Key must not be empty")
    plainTextBytes = plainText.encode('utf-8')
    keyBytes = key.encode('utf-8')
    xorResult = xor(plainTextBytes, keyBytes)
    return bytesToHex(xorResult)

# Decrypts the given ciphertext (in hexadecimal format) using the XOR cipher
# with the specified key. The result is the original plaintext.
def decrypt(cipherText, key):
    if key == "":
        raise Exception("Key must not be empty")
    cipherBytes = hexToBytes(cipherText)
    keyBytes = key.encode('utf-8')
    xorResult = xor(cipherBytes, keyBytes)
    return xorResult.decode('utf-8')

if __name__ == "__main__":
    operation = sys.stdin.readline().strip().lower()
    key = sys.stdin.readline().strip()

    if operation == "encrypt":
        plainText = sys.stdin.readline().strip()
        try:
            cipherText = encrypt(plainText, key)
            print("Encrypted Message: " + cipherText)
        except Exception as e:
            print(e)
    elif operation == "decrypt":
        cipherText = sys.stdin.readline().strip()
        try:
            plainText = decrypt(cipherText, key)
            print("Decrypted Message: " + plainText)
        except Exception as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

