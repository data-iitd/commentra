class Cipher:
    # Method to encode a message using a given cipher alphabet
    @staticmethod
    def encode(message, cipher_small):
        encoded = []  # Initialize an empty list to store the encoded message

        cipher_map = {}  # Create an empty dictionary to store the cipher mapping

        begin_small_letter = ord('a')  # Initialize the small letter index to 'a'
        begin_capital_letter = ord('A')  # Initialize the capital letter index to 'A'

        # Set the cipher alphabet for small and capital letters
        cipher_small = cipher_small.lower()
        cipher_capital = cipher_small.upper()

        # Build the cipher map by iterating through the cipher alphabet
        for i in range(len(cipher_small)):
            cipher_map[chr(begin_small_letter)] = cipher_small[i]  # Map small letters
            cipher_map[chr(begin_capital_letter)] = cipher_capital[i]  # Map capital letters
            begin_small_letter += 1
            begin_capital_letter += 1

        # Iterate through the message and encode each character
        for char in message:
            if char.isalpha():  # If the character is alphabetic
                encoded.append(cipher_map[char])  # Append the encoded character to the list
            else:
                encoded.append(char)  # If the character is not alphabetic, append it as is

        # Return the encoded message as a string
        return ''.join(encoded)

    # Method to decode a message using a given cipher alphabet
    @staticmethod
    def decode(encrypted_message, cipher_small):
        decoded = []  # Initialize an empty list to store the decoded message

        cipher_map = {}  # Create an empty dictionary to store the cipher mapping

        begin_small_letter = ord('a')  # Initialize the small letter index to 'a'
        begin_capital_letter = ord('A')  # Initialize the capital letter index to 'A'

        # Set the cipher alphabet for small and capital letters
        cipher_small = cipher_small.lower()
        cipher_capital = cipher_small.upper()

        # Build the cipher map by iterating through the cipher alphabet
        for i in range(len(cipher_small)):
            cipher_map[cipher_small[i]] = chr(begin_small_letter)  # Map small letters
            cipher_map[cipher_capital[i]] = chr(begin_capital_letter)  # Map capital letters
            begin_small_letter += 1
            begin_capital_letter += 1

        # Iterate through the encrypted message and decode each character
        for char in encrypted_message:
            if char.isalpha():  # If the character is alphabetic
                decoded.append(cipher_map[char])  # Append the decoded character to the list
            else:
                decoded.append(char)  # If the character is not alphabetic, append it as is

        # Return the decoded message as a string
        return ''.join(decoded)

# Main function to read user input and call the appropriate encoding or decoding method
if __name__ == "__main__":
    cipher_alphabet = input()  # Read the cipher alphabet from user input
    operation = input()  # Read the operation ('encode' or 'decode') from user input

    if operation.lower() == "encode":  # If the operation is 'encode'
        message = input()  # Read the message to be encoded from user input
        encrypted_message = Cipher.encode(message, cipher_alphabet)  # Call the encode method and store the result
        print("Encrypted Message:", encrypted_message)  # Print the encrypted message to the console
    elif operation.lower() == "decode":  # If the operation is 'decode'
        encrypted_message = input()  # Read the encrypted message from user input
        decrypted_message = Cipher.decode(encrypted_message, cipher_alphabet)  # Call the decode method and store the result
        print("Decrypted Message:", decrypted_message)  # Print the decrypted message to the console
    else:  # If the operation is not 'encode' or 'decode'
        print("Invalid operation. Please enter 'encode' or 'decode'.")  # Print an error message to the console

# <END-OF-CODE>
