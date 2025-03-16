
import random

class Main:
    # Variables to track message statistics
    correct_mess = 0  # Count of correctly received messages
    wrong_mess = 0  # Count of total wrong messages
    wrong_mess_caught = 0  # Count of wrong messages that were detected
    wrong_mess_not_caught = 0  # Count of wrong messages that were not detected
    mess_size = 0  # Size of the message to be generated
    ber = 0.0  # Bit Error Rate
    message_changed = False  # Flag to indicate if the message has been altered
    message = []  # List to hold the generated message
    p = []  # List to hold the divisor polynomial coefficients

    # Constructor to initialize the Main class with a divisor string, message size, and bit error rate
    def __init__(self, str, size, ber):
        self.message_changed = False  # Initialize messageChanged to false
        self.message = []  # Initialize the message list
        self.mess_size = size  # Set the size of the message
        self.p = []  # Initialize the divisor list

        # Convert the divisor string into a list of integers
        for i in range(len(str)):
            self.p.append(int(str[i]))

        # Initialize message statistics counters
        self.correct_mess = 0
        self.wrong_mess = 0
        self.wrong_mess_caught = 0
        self.wrong_mess_not_caught = 0
        self.ber = ber  # Set the bit error rate

    # Getter methods to retrieve message statistics
    def get_wrong_mess(self):
        return self.wrong_mess

    def get_wrong_mess_caught(self):
        return self.wrong_mess_caught

    def get_wrong_mess_not_caught(self):
        return self.wrong_mess_not_caught

    def get_correct_mess(self):
        return self.correct_mess

    # Method to reset the message and the messageChanged flag
    def refactor(self):
        self.message_changed = False  # Reset the messageChanged flag
        self.message = []  # Clear the message list

    # Method to generate a random message of specified size
    def generate_random_mess(self):
        for i in range(self.mess_size):
            # Generate a random bit (0 or 1) and add it to the message list
            self.message.append(random.randint(0, 1))

    # Method to divide the message by the polynomial p and check for errors
    def divide_message_with_p(self, check):
        x = []  # Temporary list to hold the current segment of the message
        k = self.message.copy()  # Copy of the message for processing

        # If not checking for errors, append zeros to the message
        if not check:
            for i in range(len(self.p) - 1):
                k.append(0)

        # Perform polynomial division
        while len(k) > 0:
            # Fill the temporary list x with bits from k
            while len(x) < len(self.p) and len(k) > 0:
                x.append(k.pop(0))
            # If x is filled, perform XOR operation with the polynomial p
            if len(x) == len(self.p):
                for i in range(len(self.p)):
                    x[i] = x[i] ^ self.p[i]
                # Remove leading zeros from x
                while len(x) > 0 and x[0] == 0:
                    x.pop(0)

        # If not checking, append the result to the message
        if not check:
            self.message.extend(x)
        else:
            # Check for errors in the received message
            if 1 in x and self.message_changed:
                self.wrong_mess_caught += 1  # Increment caught wrong messages
            elif 0 not in x and self.message_changed:
                self.wrong_mess_not_caught += 1  # Increment not caught wrong messages
            elif not self.message_changed:
                self.correct_mess += 1  # Increment correct messages

    # Method to change bits in the message based on the bit error rate
    def change_mess(self):
        for i in range(len(self.message)):
            # Randomly change bits based on the bit error rate
            if random.random() < self.ber:
                self.message_changed = True  # Mark the message as changed
                self.message[i] = 1 - self.message[i]  # Flip the bit
        # If the message was changed, increment the wrong message count
        if self.message_changed:
            self.wrong_mess += 1

# Main method to execute the program
if __name__ == "__main__":
    divisor = input()  # Read the divisor polynomial as a string
    message_size = int(input())  # Read the size of the message
    ber = float(input())  # Read the bit error rate
    num_messages = int(input())  # Read the number of messages to process

    # Create an instance of the Main class with the provided parameters
    crc = Main(divisor, message_size, ber)

    # Process the specified number of messages
    for i in range(num_messages):
        crc.refactor()  # Reset the message
        crc.generate_random_mess()  # Generate a new random message
        crc.divide_message_with_p(False)  # Divide the message to append CRC
        crc.change_mess()  # Introduce errors in the message
        crc.divide_message_with_p(True)  # Check for errors in the modified message

    # Output the results of the message processing
    print("Correct Messages:", crc.get_correct_mess())
    print("Wrong Messages:", crc.get_wrong_mess())
    print("Wrong Messages Caught:", crc.get_wrong_mess_caught())
    print("Wrong Messages Not Caught:", crc.get_wrong_mess_not_caught())

