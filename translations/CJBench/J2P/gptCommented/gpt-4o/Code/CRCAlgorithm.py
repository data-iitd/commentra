import random

class Main:
    def __init__(self, str_divisor, size, ber):
        self.correct_mess = 0  # Count of correctly received messages
        self.wrong_mess = 0  # Count of total wrong messages
        self.wrong_mess_caught = 0  # Count of wrong messages that were detected
        self.wrong_mess_not_caught = 0  # Count of wrong messages that were not detected
        self.mess_size = size  # Size of the message to be generated
        self.ber = ber  # Bit Error Rate
        self.message_changed = False  # Flag to indicate if the message has been altered
        self.message = []  # List to hold the generated message
        self.p = [int(bit) for bit in str_divisor]  # List to hold the divisor polynomial coefficients

    # Getter methods to retrieve message statistics
    def get_wrong_mess(self):
        return self.wrong_mess

    def get_wrong_mess_caught(self):
        return self.wrong_mess_caught

    def get_wrong_mess_not_caught(self):
        return self.wrong_mess_not_caught

    def get_correct_mess(self):
        return self.correct_mess

    # Method to reset the message and the message_changed flag
    def refactor(self):
        self.message_changed = False  # Reset the messageChanged flag
        self.message = []  # Clear the message list

    # Method to generate a random message of specified size
    def generate_random_mess(self):
        self.message = [random.randint(0, 1) for _ in range(self.mess_size)]

    # Method to divide the message by the polynomial p and check for errors
    def divide_message_with_p(self, check):
        x = []  # Temporary list to hold the current segment of the message
        k = self.message.copy()  # Copy of the message for processing

        # If not checking for errors, append zeros to the message
        if not check:
            k.extend([0] * (len(self.p) - 1))

        # Perform polynomial division
        while k:
            # Fill the temporary list x with bits from k
            while len(x) < len(self.p) and k:
                x.append(k.pop(0))
            # If x is filled, perform XOR operation with the polynomial p
            if len(x) == len(self.p):
                x = [x[i] ^ self.p[i] for i in range(len(self.p))]
                # Remove leading zeros from x
                while x and x[0] == 0:
                    x.pop(0)

        # If not checking, append the result to the message
        if not check:
            self.message.extend(x)
        else:
            # Check for errors in the received message
            if 1 in x and self.message_changed:
                self.wrong_mess_caught += 1  # Increment caught wrong messages
            elif 1 not in x and self.message_changed:
                self.wrong_mess_not_caught += 1  # Increment not caught wrong messages
            elif not self.message_changed:
                self.correct_mess += 1  # Increment correct messages

    # Method to change bits in the message based on the bit error rate
    def change_mess(self):
        for i in range(len(self.message)):
            # Randomly change bits based on the bit error rate
            if random.random() < self.ber:
                self.message_changed = True  # Mark the message as changed
                self.message[i] ^= 1  # Flip the bit
        # If the message was changed, increment the wrong message count
        if self.message_changed:
            self.wrong_mess += 1

# Main execution
if __name__ == "__main__":
    divisor = input()  # Read the divisor polynomial as a string
    message_size = int(input())  # Read the size of the message
    ber = float(input())  # Read the bit error rate
    num_messages = int(input())  # Read the number of messages to process

    # Create an instance of the Main class with the provided parameters
    crc = Main(divisor, message_size, ber)

    # Process the specified number of messages
    for _ in range(num_messages):
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

# <END-OF-CODE>
