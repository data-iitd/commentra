
import string

def encode(message, cipher_small):
    encoded = ""
    cipher_map = dict(zip(string.ascii_lowercase, cipher_small))
    for char in message:
        if char.isalpha():
            encoded += cipher_map[char.lower()]
        else:
            encoded += char
    return encoded

def decode(encrypted_message, cipher_small):
    decoded = ""
    cipher_map = dict(zip(cipher_small, string.ascii_lowercase))
    for char in encrypted_message:
        if char.isalpha():
            decoded += cipher_map[char]
        else:
            decoded += char
    return decoded

if __name__ == "__main__":
    cipher_alphabet = input("Enter the cipher alphabet: ")
    operation = input("Enter the operation (encode/decode): ")

    if operation.lower() == "encode":
        message = input("Enter the message to encode: ")
        encrypted_message = encode(message, cipher_alphabet)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decode":
        encrypted_message = input("Enter the encrypted message to decode: ")
        decrypted_message = decode(encrypted_message, cipher_alphabet)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.")