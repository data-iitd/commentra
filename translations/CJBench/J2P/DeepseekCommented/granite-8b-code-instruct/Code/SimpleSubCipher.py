
import string

def encode(message, cipher_small):
    cipher_map = dict(zip(string.ascii_lowercase, cipher_small))
    encoded = ''.join(cipher_map.get(c, c) for c in message)
    return encoded

def decode(encrypted_message, cipher_small):
    cipher_map = dict(zip(cipher_small, string.ascii_lowercase))
    decoded = ''.join(cipher_map.get(c, c) for c in encrypted_message)
    return decoded

if __name__ == "__main__":
    cipher_alphabet = input("Enter the cipher alphabet: ")
    operation = input("Enter the operation type (encode or decode): ")
    if operation.lower() == "encode":
        message = input("Enter the message to be encoded: ")
        encrypted_message = encode(message, cipher_alphabet)
        print("Encrypted Message:", encrypted_message)
    elif operation.lower() == "decode":
        encrypted_message = input("Enter the encrypted message to be decoded: ")
        decrypted_message = decode(encrypted_message, cipher_alphabet)
        print("Decrypted Message:", decrypted_message)
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.")

