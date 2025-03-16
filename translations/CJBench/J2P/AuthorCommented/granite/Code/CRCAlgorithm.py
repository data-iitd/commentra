
import random

class Main:
    def __init__(self, str, size, ber):
        self.correct_mess = 0
        self.wrong_mess = 0
        self.wrong_mess_caught = 0
        self.wrong_mess_not_caught = 0
        self.mess_size = size
        self.p = [int(i) for i in str]
        self.ber = ber
        self.message_changed = False
        self.message = []

    def get_wrong_mess(self):
        return self.wrong_mess

    def get_wrong_mess_caught(self):
        return self.wrong_mess_caught

    def get_wrong_mess_not_caught(self):
        return self.wrong_mess_not_caught

    def get_correct_mess(self):
        return self.correct_mess

    def refactor(self):
        self.message_changed = False
        self.message = []

    def generate_random_mess(self):
        for i in range(self.mess_size):
            self.message.append(random.randint(0, 1))

    def divide_message_with_p(self, check):
        divided_message = []
        message = self.message[:]
        if not check:
            message += [0] * (len(self.p) - 1)
        while message:
            divided_message += message[:len(self.p)]
            message = message[len(self.p):]
            for i in range(len(self.p)):
                divided_message[i] ^= self.p[i]
            while divided_message and divided_message[0] == 0:
                divided_message = divided_message[1:]
        if not check:
            self.message += divided_message
        else:
            if any(x == 1 for x in divided_message) and self.message_changed:
                self.wrong_mess_caught += 1
            elif not any(x == 1 for x in divided_message) and self.message_changed:
                self.wrong_mess_not_caught += 1
            elif not self.message_changed:
                self.correct_mess += 1

    def change_mess(self):
        for i in range(len(self.message)):
            if random.random() < self.ber:
                self.message_changed = True
                self.message[i] = 1 - self.message[i]
        if self.message_changed:
            self.wrong_mess += 1

if __name__ == "__main__":
    # Read CRC divisor (binary string), message size, and BER
    divisor = input()
    message_size = int(input())
    ber = float(input())

    # Number of messages to transmit
    num_messages = int(input())

    crc = Main(divisor, message_size, ber)

    for i in range(num_messages):
        crc.refactor()
        crc.generate_random_mess()
        crc.divide_message_with_p(False)  # Append CRC to the message
        crc.change_mess()  # Simulate errors in transmission
        crc.divide_message_with_p(True)  # Check received message

    # Output results
    print("Correct Messages:", crc.get_correct_mess())
    print("Wrong Messages:", crc.get_wrong_mess())
    print("Wrong Messages Caught:", crc.get_wrong_mess_caught())
    print("Wrong Messages Not Caught:", crc.get_wrong_mess_not_caught())

