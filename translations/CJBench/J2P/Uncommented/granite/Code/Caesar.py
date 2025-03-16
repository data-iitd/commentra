

import string

class Main:
    def __init__(self):
        self.alphabet = string.ascii_lowercase
        self.shift = 0

    def encode(self, message, shift):
        encoded = ""
        shift %= 26
        for current in message:
            if current in self.alphabet:
                encoded += self.alphabet[(self.alphabet.index(current) + shift) % 26]
            else:
                encoded += current
        return encoded

    def decode(self, encrypted_message, shift):
        decoded = ""
        shift %= 26
        for current in encrypted_message:
            if current in self.alphabet:
                decoded += self.alphabet[(self.alphabet.index(current) - shift) % 26]
            else:
                decoded += current
        return decoded

    def bruteforce(self, encrypted_message):
        answers = []
        for i in range(27):
            answers.append(self.decode(encrypted_message, i))
        return answers

# 