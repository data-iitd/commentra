

# Python implementation of Main Cipher
# It is a type of substitution cipher in which each letter in the plaintext
# is replaced by a letter some fixed number of positions down the alphabet.

def main():
    operation = input().strip().lower()

    if operation == "encode":
        plaintext = input()
        shift = int(input())
        cipher = Main()
        print("Encoded Message:", cipher.encode(plaintext, shift))
    elif operation == "decode":
        print("Enter the encrypted text:")
        encrypted_text = input()
        print("Enter the shift value:")
        shift = int(input())
        cipher = Main()
        print("Decoded Message:", cipher.decode(encrypted_text, shift))
    elif operation == "bruteforce":
        print("Enter the encrypted text:")
        encrypted_text = input()
        cipher = Main()
        possible_solutions = cipher.bruteforce(encrypted_text)
        print("Possible Decoded Messages:")
        for i in range(len(possible_solutions)):
            print("Shift", i, ":", possible_solutions[i])
    else:
        print("Invalid operation. Please enter encode, decode, or bruteforce.")

# Encrypt text by shifting every Latin char by add number shift for ASCII
# Example : A + 1 -> B
def encode(self, message, shift):
    encoded = ""
    shift %= 26

    for current in message:
        if current.isupper():
            #            int current = message.charAt(i); //using char to shift characters because
            #            ascii
            # is in-order latin alphabet
            current = chr((ord(current) - 65 + shift) % 26 + 65)
        elif current.islower():
            current = chr((ord(current) - 97 + shift) % 26 + 97)
        encoded += current

    return encoded

# Decrypt message by shifting back every Latin char to previous the ASCII
# Example : B - 1 -> A
def decode(self, encrypted_message, shift):
    decoded = ""
    shift %= 26

    for current in encrypted_message:
        if current.isupper():
            current = chr((ord(current) - 65 - shift) % 26 + 65)
        elif current.islower():
            current = chr((ord(current) - 97 - shift) % 26 + 97)
        decoded += current

    return decoded

# @return string array which contains all the possible decoded combination.
def bruteforce(self, encrypted_message):
    all_the_answers = []
    for i in range(27):
        all_the_answers.append(self.decode(encrypted_message, i))
    return all_the_answers

if __name__ == "__main__":
    main()

