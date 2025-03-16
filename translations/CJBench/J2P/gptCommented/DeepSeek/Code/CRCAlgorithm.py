import random
import sys

class Main:
    # Variables to track message statistics
    correctMess = 0
    wrongMess = 0
    wrongMessCaught = 0
    wrongMessNotCaught = 0
    messSize = 0
    ber = 0.0
    messageChanged = False
    message = []
    p = []

    # Constructor to initialize the Main class with a divisor string, message size, and bit error rate
    def __init__(self, str, size, ber):
        self.messageChanged = False
        self.message = []
        self.messSize = size
        self.p = []
        self.correctMess = 0
        self.wrongMess = 0
        self.wrongMessCaught = 0
        self.wrongMessNotCaught = 0
        self.ber = ber

        # Convert the divisor string into a list of integers
        for i in range(len(str)):
            self.p.append(int(str[i]))

    # Getter methods to retrieve message statistics
    def getWrongMess(self):
        return self.wrongMess

    def getWrongMessCaught(self):
        return self.wrongMessCaught

    def getWrongMessNotCaught(self):
        return self.wrongMessNotCaught

    def getCorrectMess(self):
        return self.correctMess

    # Method to reset the message and the messageChanged flag
    def refactor(self):
        self.messageChanged = False
        self.message = []

    # Method to generate a random message of specified size
    def generateRandomMess(self):
        for i in range(self.messSize):
            # Generate a random bit (0 or 1) and add it to the message list
            x = random.randint(0, 1)
            self.message.append(x)

    # Method to divide the message by the polynomial p and check for errors
    def divideMessageWithP(self, check):
        x = []
        k = self.message.copy()

        # If not checking for errors, append zeros to the message
        if not check:
            for i in range(len(self.p) - 1):
                k.append(0)

        # Perform polynomial division
        while k:
            # Fill the temporary list x with bits from k
            while len(x) < len(self.p) and k:
                x.append(k.pop(0))
            # If x is filled, perform XOR operation with the polynomial p
            if len(x) == len(self.p):
                for i in range(len(self.p)):
                    x[i] ^= self.p[i]
                # Remove leading zeros from x
                while x and x[0] == 0:
                    x.pop(0)

        # If not checking, append the result to the message
        if not check:
            self.message.extend(x)
        else:
            # Check for errors in the received message
            if 1 in x and self.messageChanged:
                self.wrongMessCaught += 1
            elif 1 not in x and self.messageChanged:
                self.wrongMessNotCaught += 1
            elif not self.messageChanged:
                self.correctMess += 1

    # Method to change bits in the message based on the bit error rate
    def changeMess(self):
        for i in range(len(self.message)):
            # Randomly change bits based on the bit error rate
            if random.random() < self.ber:
                self.messageChanged = True
                self.message[i] ^= 1
        if self.messageChanged:
            self.wrongMess += 1

    # Main method to execute the program
    @staticmethod
    def main():
        # Read the divisor polynomial as a string
        divisor = input()
        # Read the size of the message
        messageSize = int(input())
        # Read the bit error rate
        ber = float(input())
        # Read the number of messages to process
        numMessages = int(input())

        # Create an instance of the Main class with the provided parameters
        crc = Main(divisor, messageSize, ber)

        # Process the specified number of messages
        for i in range(numMessages):
            crc.refactor()
            crc.generateRandomMess()
            crc.divideMessageWithP(False)
            crc.changeMess()
            crc.divideMessageWithP(True)

        # Output the results of the message processing
        print("Correct Messages: " + str(crc.getCorrectMess()))
        print("Wrong Messages: " + str(crc.getWrongMess()))
        print("Wrong Messages Caught: " + str(crc.getWrongMessCaught()))
        print("Wrong Messages Not Caught: " + str(crc.getWrongMessNotCaught()))

# Execute the main method
if __name__ == "__main__":
    Main.main()
