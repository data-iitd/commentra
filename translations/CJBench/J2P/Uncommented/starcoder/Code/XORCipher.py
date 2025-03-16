
import binascii
import sys

def bytes_to_hex(bytes):
    return binascii.hexlify(bytes).decode('utf-8')

def hex_to_bytes(hex):
    return binascii.unhexlify(hex)

def xor(input_bytes, key_bytes):
    output_bytes = bytearray(len(input_bytes))
    for i in range(len(input_bytes)):
        output_bytes[i] = input_bytes[i] ^ key_bytes[i % len(key_bytes)]
    return output_bytes

def encrypt(plain_text, key):
    if key == "":
        raise ValueError("Key must not be empty")
    plain_text_bytes = plain_text.encode('utf-8')
    key_bytes = key.encode('utf-8')
    xor_result = xor(plain_text_bytes, key_bytes)
    return bytes_to_hex(xor_result)

def decrypt(cipher_text, key):
    if key == "":
        raise ValueError("Key must not be empty")
    cipher_bytes = hex_to_bytes(cipher_text)
    key_bytes = key.encode('utf-8')
    xor_result = xor(cipher_bytes, key_bytes)
    return xor_result.decode('utf-8')

if __name__ == '__main__':
    operation = sys.stdin.readline().strip().lower()
    if operation == "encrypt":
        key = sys.stdin.readline().strip()
        plain_text = sys.stdin.readline().strip()
        try:
            cipher_text = encrypt(plain_text, key)
            print("Encrypted Message: " + cipher_text)
        except ValueError as e:
            print(e)
    elif operation == "decrypt":
        key = sys.stdin.readline().strip()
        cipher_text = sys.stdin.readline().strip()
        try:
            plain_text = decrypt(cipher_text, key)
            print("Decrypted Message: " + plain_text)
        except ValueError as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")

