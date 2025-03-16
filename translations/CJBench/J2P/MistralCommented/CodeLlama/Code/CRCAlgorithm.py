
import random

class Main:
    # Declare instance variables
    correct_mess = 0
    wrong_mess = 0
    wrong_mess_caught = 0
    wrong_mess_not_caught = 0
    mess_size = 0
    ber = 0.0
    message_changed = False
    message = []
    p = []

    def __init__(self, divisor, message_size, ber):
        # Initialize instance variables
        self.message_changed = False
        self.message = []
        self.mess_size = message_size
        self.p = []

        # Initialize p list with the given divisor string
        for i in range(len(divisor)):
            self.p.append(int(divisor[i]))

        # Initialize counter variables
        self.correct_mess = 0
        self.wrong_mess = 0
        self.wrong_mess_caught = 0
        self.wrong_mess_not_caught = 0
        self.ber = ber

    # Getters for counter variables
    def get_wrong_mess(self):
        return self.wrong_mess

    def get_wrong_mess_caught(self):
        return self.wrong_mess_caught

    def get_wrong_mess_not_caught(self):
        return self.wrong_mess_not_caught

    def get_correct_mess(self):
        return self.correct_mess

    # Refactor method to reset instance variables
    def refactor(self):
        self.message_changed = False
        self.message = []

    # Generate random message method
    def generate_random_mess(self):
        # Generate random message of given size
        for i in range(self.mess_size):
            self.message.append(random.randint(0, 1))

    # Divide message with p method without checking
    def divide_message_with_p(self, check):
        x = []  # Initialize x list
        k = self.message[:]  # Initialize k list as a copy of message list

        # If not checking, fill k list with zeros
        if not check:
            for i in range(len(self.p) - 1):
                k.append(0)

        # Divide message with p
        while k:
            while len(x) < len(self.p) and k:
                x.append(k.pop(0))

            # If message size is equal to p size
            if len(x) == len(self.p):
                # Xor each element in x list with corresponding element in p list
                for i in range(len(self.p)):
                    x[i] = x[i] ^ self.p[i]

                # Remove leading zeros from x list
                while x and x[0] == 0:
                    x.pop(0)

        # Update counter variables based on the result
        if not check:
            self.message.extend(x)
        else:
            # If message has been changed and 1 is present in x list
            if self.message_changed and 1 in x:
                self.wrong_mess_caught += 1
            # If message has been changed and 1 is not present in x list
            elif self.message_changed and 1 not in x:
                self.wrong_mess_not_caught += 1
            # If message has not been changed
            elif not self.message_changed:
                self.correct_mess += 1

    # Change message method
    def change_mess(self):
        # Change each element in message list with probability ber
        for i in range(len(self.message)):
            if random.random() < self.ber:
                self.message_changed = True
                self.message[i] = self.message[i] ^ 1

        # Update counter variable if message has been changed
        if self.message_changed:
            self.wrong_mess += 1

    # Main method to run the simulation
    def main(self, divisor, message_size, ber, num_messages):
        # Create Main object with given input
        crc = Main(divisor, message_size, ber)

        # Generate and check messages for given number of times
        for i in range(num_messages):
            crc.refactor()  # Refactor before each iteration
            crc.generate_random_mess()  # Generate random message
            crc.divide_message_with_p(False)  # Divide message with p without checking
            crc.change_mess()  # Change message
            crc.divide_message_with_p(True)  # Divide message with p and check

        # Print the results
        print("Correct Messages:", crc.get_correct_mess())
        print("Wrong Messages:", crc.get_wrong_mess())
        print("Wrong Messages Caught:", crc.get_wrong_mess_caught())
        print("Wrong Messages Not Caught:", crc.get_wrong_mess_not_caught())


# Read input from user
divisor = input()
message_size = int(input())
ber = float(input())
num_messages = int(input())

# Run the simulation
crc = Main(divisor, message_size, ber)
crc.main(divisor, message_size, ber, num_messages)

# End of code
