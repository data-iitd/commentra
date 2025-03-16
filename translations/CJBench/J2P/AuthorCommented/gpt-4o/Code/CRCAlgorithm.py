import random

class Main:
    def __init__(self, str_p, size, ber):
        self.correct_mess = 0
        self.wrong_mess = 0
        self.wrong_mess_caught = 0
        self.wrong_mess_not_caught = 0
        self.mess_size = size
        self.ber = ber
        self.message_changed = False
        self.message = []
        self.p = [int(bit) for bit in str_p]

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
        self.message = [random.randint(0, 1) for _ in range(self.mess_size)]

    def divide_message_with_p(self, check):
        x = []
        k = self.message.copy()
        if not check:
            k.extend([0] * (len(self.p) - 1))

        while k:
            while len(x) < len(self.p) and k:
                x.append(k.pop(0))
            if len(x) == len(self.p):
                x = [x[i] ^ self.p[i] for i in range(len(self.p))]  # XOR operation
                while x and x[0] == 0:
                    x.pop(0)

        if not check:
            self.message.extend(x)
        else:
            if 1 in x and self.message_changed:
                self.wrong_mess_caught += 1
            elif 1 not in x and self.message_changed:
                self.wrong_mess_not_caught += 1
            elif not self.message_changed:
                self.correct_mess += 1

    def change_mess(self):
        for i in range(len(self.message)):
            if random.random() < self.ber:
                self.message_changed = True
                self.message[i] ^= 1  # Flip bit
        if self.message_changed:
            self.wrong_mess += 1

if __name__ == "__main__":
    divisor = input()
    message_size = int(input())
    ber = float(input())
    num_messages = int(input())

    crc = Main(divisor, message_size, ber)

    for _ in range(num_messages):
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

# <END-OF-CODE>
