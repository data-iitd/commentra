from typing import Dict

def encode(message: str, cipher_small: str) -> str:
    encoded = []  # List to hold the encoded message
    cipher_map: Dict[str, str] = {}  # Dictionary to hold the character mapping for encoding
    begin_small_letter = 'a'  # Starting character for lowercase letters
    begin_capital_letter = 'A'  # Starting character for uppercase letters
    
    # Convert the cipher to lowercase and uppercase
    cipher_small = cipher_small.lower()
    cipher_capital = cipher_small.upper()
    
    # Populate the cipher_map with character mappings for both lowercase and uppercase letters
    for i in range(len(cipher_small)):
        cipher_map[chr(ord(begin_small_letter) + i)] = cipher_small[i]  # Map lowercase letters
        cipher_map[chr(ord(begin_capital_letter) + i)] = cipher_capital[i]  # Map uppercase letters
    
    # Encode the message using the cipher_map
    for char in message:
        if char.isalpha():  # Check if the character is alphabetic
            encoded.append(cipher_map.get(char, char))  # Append the encoded character or the original character if not in map
        else:
            encoded.append(char)  # Append non-alphabetic characters unchanged
    return ''.join(encoded)  # Return the encoded message

def decode(encrypted_message: str, cipher_small: str) -> str:
    decoded = []  # List to hold the decoded message
    cipher_map: Dict[str, str] = {}  # Dictionary to hold the character mapping for decoding
    begin_small_letter = 'a'  # Starting character for lowercase letters
    begin_capital_letter = 'A'  # Starting character for uppercase letters
    
    # Convert the cipher to lowercase and uppercase
    cipher_small = cipher_small.lower()
    cipher_capital = cipher_small.upper()
    
    # Populate the cipher_map with character mappings for decoding
    for i in range(len(cipher_small)):
        cipher_map[cipher_small[i]] = chr(ord(begin_small_letter) + i)  # Map lowercase letters
        cipher_map[cipher_capital[i]] = chr(ord(begin_capital_letter) + i)  # Map uppercase letters
    
    # Decode the encrypted message using the cipher_map
    for char in encrypted_message:
        if char.isalpha():  # Check if the character is alphabetic
            decoded.append(cipher_map.get(char, char))  # Append the decoded character or the original character if not in map
        else:
            decoded.append(char)  # Append non-alphabetic characters unchanged
    return ''.join(decoded)  # Return the decoded message

def main():
    cipher_alphabet = input()  # Read the cipher alphabet from user input
    operation = input()  # Read the operation (encode/decode) from user input
    
    # Check if the operation is to encode
    if operation.lower() == 'encode':
        message = input()  # Read the message to encode
        encrypted_message = encode(message, cipher_alphabet)  # Encode the message
        print("Encrypted Message:", encrypted_message)  # Output the encoded message
    # Check if the operation is to decode
    elif operation.lower() == 'decode':
        encrypted_message = input()  # Read the encrypted message to decode
        decrypted_message = decode(encrypted_message, cipher_alphabet)  # Decode the message
        print("Decrypted Message:", decrypted_message)  # Output the decoded message
    # Handle invalid operation input
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.")

if __name__ == "__main__":
    main()
