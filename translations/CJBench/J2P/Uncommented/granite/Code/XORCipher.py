

import sys
CS_DEFAULT = 'utf-8'
def bytes_to_hex(bytes):
    hex_string = ''.join(format(b, '02x') for b in bytes)
    return hex_string
def hex_to_bytes(hex_string):
    bytes = bytes.fromhex(hex_string)
    return bytes
def xor(input_bytes, key_bytes):
    output_bytes = bytearray()
    for i in range(len(input_bytes)):
        output_bytes.append(input_bytes[i] ^ key_bytes[i % len(key_bytes)])
    return output_bytes
def encrypt(plain_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    plain_text_bytes = plain_text.encode(CS_DEFAULT)
    key_bytes = key.encode(CS_DEFAULT)
    xor_result = xor(plain_text_bytes, key_bytes)
    return bytes_to_hex(xor_result)
def decrypt(cipher_text, key):
    if not key:
        raise ValueError("Key must not be empty")
    cipher_bytes = hex_to_bytes(cipher_text)
    key_bytes = key.encode(CS_DEFAULT)
    xor_result = xor(cipher_bytes, key_bytes)
    return xor_result.decode(CS_DEFAULT)
if __name__ == '__main__':
    operation = input().lower()
    print("Enter the key: ", end='')
    key = input()
    if operation == 'encrypt':
        plain_text = input()
        try:
            cipher_text = encrypt(plain_text, key)
            print("Encrypted Message: ", cipher_text)
        except ValueError as e:
            print(e)
    elif operation == 'decrypt':
        cipher_text = input()
        try:
            plain_text = decrypt(cipher_text, key)
            print("Decrypted Message: ", plain_text)
        except ValueError as e:
            print(e)
    else:
        print("Invalid operation. Please choose 'encrypt' or 'decrypt'.")
