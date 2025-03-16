import binascii
import sys

# Define the default charset to be used for encoding and decoding
CS_DEFAULT = "utf-8"

# Private constructor to prevent instantiation
def __init__(self):
    pass

# Convert byte array to a hexadecimal string
def bytesToHex(bytes):
    hexString = ""
    for b in bytes:
        hex = hex(b & 0xFF)
        if len(hex) == 1:
            hex = "0" + hex
        hexString += hex
    return hexString

# Convert a hexadecimal string to a byte array
def hexToBytes(hex):
    len = hex.length()
    data = bytearray(len / 2)
    for i in range(0, len, 2):
        data[i / 2] = (byte) ((Character.digit(hex.charAt(i), 16) << 4)
                                + Character.digit(hex.charAt(i + 1), 16))
    return data

# Perform a XOR operation between two byte arrays
def xor(inputBytes, keyBytes):
    outputBytes = bytearray(inputBytes.length)
    for i in range(0, inputBytes.length):
        outputBytes[i] = (byte) (inputBytes[i] ^ keyBytes[i % keyBytes.length])
    return outputBytes

# Encrypt the given plain text using the provided key
def encrypt(plainText, key):
    if key.isEmpty():
        raise Exception("Key must not be empty")
    # Convert plain text to byte array using the default charset
    plainTextBytes = plainText.getBytes(CS_DEFAULT)
    # Convert key to byte array using the default charset
    keyBytes = key.getBytes(CS_DEFAULT)
    # Perform XOR operation to encrypt the data
    xorResult = xor(plainTextBytes, keyBytes)
    # Convert the encrypted byte array to a hexadecimal string
    return bytesToHex(xorResult)

# Decrypt the given cipher text using the provided key
def decrypt(cipherText, key):
    if key.isEmpty():
        raise Exception("Key must not be empty")
    # Convert cipher text from hexadecimal string to byte array
    cipherBytes = hexToBytes(cipherText)
    # Convert key to byte array using the default charset
    keyBytes = key.getBytes(CS_DEFAULT)
    # Perform XOR operation to decrypt the data
    xorResult = xor(cipherBytes, keyBytes)
    # Convert the decrypted byte array to a string using the default charset
    return xorResult.decode(CS_DEFAULT)

# Main method to handle user input for encryption or decryption
def main(args):
    scanner = sys.stdin
    operation = scanner.readline().lower()
    print("Enter the key: ")
    key = scanner.readline()
    if operation.equals("encrypt"):
        plainText = scanner.readline()
        try:
            cipherText = encrypt(plainText, key)
            print("Encrypted Message: " + cipherText)
        except Exception as e:
            print(e.getMessage())
    elif operation.equals("decrypt"):
        cipherText = scanner.readline()
        try:
            plainText = decrypt(cipherText, key)
            print("Decrypted Message: " + plainText)
        except Exception as e:
            print(e.getMessage())
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")
    scanner.close()

# Start the program
if __name__ == "__main__":
    main(sys.argv)

