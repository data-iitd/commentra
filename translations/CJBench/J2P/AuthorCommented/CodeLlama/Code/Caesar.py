
import sys


def main():
    operation = sys.stdin.readline().strip().lower()

    if operation == "encode":
        plaintext = sys.stdin.readline().strip()
        shift = int(sys.stdin.readline().strip())
        cipher = Main()
        print("Encoded Message: " + cipher.encode(plaintext, shift))
    elif operation == "decode":
        encrypted_text = sys.stdin.readline().strip()
        shift = int(sys.stdin.readline().strip())
        cipher = Main()
        print("Decoded Message: " + cipher.decode(encrypted_text, shift))
    elif operation == "bruteforce":
        encrypted_text = sys.stdin.readline().strip()
        cipher = Main()
        possible_solutions = cipher.bruteforce(encrypted_text)
        print("Possible Decoded Messages:")
        for i in range(len(possible_solutions)):
            print("Shift " + str(i) + ": " + possible_solutions[i])
    else:
        print("Invalid operation. Please enter encode, decode, or bruteforce.")


class Main:

    def encode(self, message, shift):
        encoded = ""
        shift %= 26

        for current in message:
            if current.isupper():
                #            int current = message.charAt(i); //using char to shift characters because
                #            ascii
                # is in-order latin alphabet
                current += shift
                encoded += chr(current if current <= ord('Z') else current - 26)
            elif current.islower():
                current += shift
                encoded += chr(current if current <= ord('z') else current - 26)
            else:
                encoded += current

        return encoded

    def decode(self, encrypted_message, shift):
        decoded = ""
        shift %= 26

        for current in encrypted_message:
            if current.isupper():
                current -= shift
                decoded += chr(current if current >= ord('A') else current + 26)
            elif current.islower():
                current -= shift
                decoded += chr(current if current >= ord('a') else current + 26)
            else:
                decoded += current

        return decoded

    def bruteforce(self, encrypted_message):
        list_of_all_the_answers = [""] * 27
        for i in range(27):
            list_of_all_the_answers[i] = self.decode(encrypted_message, i)

        return list_of_all_the_answers


if __name__ == "__main__":
    main()

