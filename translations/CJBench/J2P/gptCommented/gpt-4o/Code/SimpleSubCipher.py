class Cipher:
    # Method to encode a message using a given cipher
    @staticmethod
    def encode(message, cipher_small):
        encoded = []  # List to hold the encoded message
        cipher_map = {}  # Dictionary to hold the character mapping for encoding
        begin_small_letter = ord('a')  # Starting character for lowercase letters
        begin_capital_letter = ord('A')  # Starting character for uppercase letters
        
        # Convert the cipher to lowercase and uppercase
        cipher_small = cipher_small.lower()
        cipher_capital = cipher_small.upper()
        
        # Populate the cipher_map with character mappings for both lowercase and uppercase letters
        for i in range(len(cipher_small)):
            cipher_map[chr(begin_small_letter)] = cipher_small[i]  # Map lowercase letters
            cipher_map[chr(begin_capital_letter)] = cipher_capital[i]  # Map uppercase letters
            begin_small_letter += 1
            begin_capital_letter += 1
        
        # Encode the message using the cipher_map
        for char in message:
            if char.isalpha():  # Check if the character is alphabetic
                encoded.append(cipher_map[char])  # Append the encoded character
            else:
                encoded.append(char)  # Append non-alphabetic characters unchanged
        
        return ''.join(encoded)  # Return the encoded message

    # Method to decode an encrypted message using a given cipher
    @staticmethod
    def decode(encrypted_message, cipher_small):
        decoded = []  # List to hold the decoded message
        cipher_map = {}  # Dictionary to hold the character mapping for decoding
        begin_small_letter = ord('a')  # Starting character for lowercase letters
        begin_capital_letter = ord('A')  # Starting character for uppercase letters
        
        # Convert the cipher to lowercase and uppercase
        cipher_small = cipher_small.lower()
        cipher_capital = cipher_small.upper()
        
        # Populate the cipher_map with character mappings for decoding
        for i in range(len(cipher_small)):
            cipher_map[cipher_small[i]] = chr(begin_small_letter)  # Map lowercase letters
            cipher_map[cipher_capital[i]] = chr(begin_capital_letter)  # Map uppercase letters
            begin_small_letter += 1
            begin_capital_letter += 1
        
        # Decode the encrypted message using the cipher_map
        for char in encrypted_message:
            if char.isalpha():  # Check if the character is alphabetic
                decoded.append(cipher_map[char])  # Append the decoded character
            else:
                decoded.append(char)  # Append non-alphabetic characters unchanged
        
        return ''.join(decoded)  # Return the decoded message

# Main function to execute the program
if __name__ == "__main__":
    cipher_alphabet = input()  # Read the cipher alphabet from user input
    operation = input()  # Read the operation (encode/decode) from user input
    
    # Check if the operation is to encode
    if operation.lower() == "encode":
        message = input()  # Read the message to encode
        encrypted_message = Cipher.encode(message, cipher_alphabet)  # Encode the message
        print("Encrypted Message:", encrypted_message)  # Output the encoded message
    # Check if the operation is to decode
    elif operation.lower() == "decode":
        encrypted_message = input()  # Read the encrypted message to decode
        decrypted_message = Cipher.decode(encrypted_message, cipher_alphabet)  # Decode the message
        print("Decrypted Message:", decrypted_message)  # Output the decoded message
    # Handle invalid operation input
    else:
        print("Invalid operation. Please enter 'encode' or 'decode'.")

# <END-OF-CODE>
