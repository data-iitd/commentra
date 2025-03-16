import random

class Main:
    def __init__(self, divisor, message_size, ber):
        self.correct_mess = 0
        self.wrong_mess = 0
        self.wrong_mess_caught = 0
        self.wrong_mess_not_caught = 0
        self.message_size = message_size
        self.ber = ber
        self.message = []
        self.p = []
        for i in range(len(divisor)):
            self.p.append(int(divisor[i]))

    def get_wrong_mess(self):
        return self.wrong_mess

    def get_wrong_mess_caught(self):
        return self.wrong_mess_caught

    def get_wrong_mess_not_caught(self):
        return self.wrong_mess_not_caught

    def get_correct_mess(self):
        return self.correct_mess

    def refactor(self):
        self.message = []

    def generate_random_mess(self):
        for i in range(self.message_size):
            x = random.randint(0, 1)
            self.message.append(x)

    def divide_message_with_p(self, check):
        x = []
        k = self.message
        if not check:
            for i in range(len(self.p) - 1):
                k.append(0)
        while k:
            while len(x) < len(self.p) and k:
                x.append(k.pop(0))
            if len(x) == len(self.p):
                for i in range(len(self.p)):
                    x[i] = x[i] ^ self.p[i]
                while x and x[0] == 0:
                    x.pop(0)
        if not check:
            self.message.extend(x)
        else:
            if 1 in x and self.message_changed:
                self.wrong_mess_caught += 1
            elif not 1 in x and self.message_changed:
                self.wrong_mess_not_caught += 1
            elif not self.message_changed:
                self.correct_mess += 1

    def change_mess(self):
        self.message_changed = False
        for i in range(len(self.message)):
            if random.random() < self.ber:
                self.message_changed = True
                self.message[i] = self.message[i] ^ 1
        if self.message_changed:
            self.wrong_mess += 1

    def main(self, divisor, message_size, ber, num_messages):
        self.refactor()
        self.generate_random_mess()
        self.divide_message_with_p(False)
        self.change_mess()
        self.divide_message_with_p(True)

if __name__ == "__main__":
    divisor = input()
    message_size = int(input())
    ber = float(input())
    num_messages = int(input())
    crc = Main(divisor, message_size, ber)
    for i in range(num_messages):
        crc.refactor()
        crc.generate_random_mess()
        crc.divide_message_with_p(False)
        crc.change_mess()
        crc.divide_message_with_p(True)
    print("Correct Messages: " + str(crc.get_correct_mess()))
    print("Wrong Messages: " + str(crc.get_wrong_mess()))
    print("Wrong Messages Caught: " + str(crc.get_wrong_mess_caught()))
    print("Wrong Messages Not Caught: " + str(crc.get_wrong_mess_not_caught()))


