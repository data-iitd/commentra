import random

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

        # Convert the divisor string into a list of integers
        for i in range(len(str)):
            self.p.append(int(str[i]))

        # Initialize message statistics counters
        self.correctMess = 0
        self.wrongMess = 0
        self.wrongMessCaught = 0
        self.wrongMessNotCaught = 0
        self.ber = ber

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
        x = [] # Temporary list to hold the current segment of the message
        k = self.message[:] # Copy of the message for processing

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
        if not check:
            self.message.extend(x)
        else:
            # Check for errors in the received message
            if 1 in x and self.messageChanged:
                self.wrongMessCaught += 1 # Increment caught wrong messages
            elif 1 not in x and self.messageChanged:
                self.wrongMessNotCaught += 1 # Increment not caught wrong messages
            elif not self.messageChanged:
                self.correctMess += 1 # Increment correct messages

    # Method to change bits in the message based on the bit error rate
    def changeMess(self):
        for i in range(len(self.message)):
            # Randomly change bits based on the bit error rate
            if random.random() < self.ber:
                self.messageChanged = True # Mark the message as changed
                self.message[i] = self.message[i] ^ 1 # Flip the bit
        # If the message was changed, increment the wrong message count
        if self.messageChanged:
            self.wrongMess += 1

    # Main method to execute the program
    def main(self):
        divisor = input() # Read the divisor polynomial as a string
        messageSize = int(input()) # Read the size of the message
        ber = float(input()) # Read the bit error rate
        numMessages = int(input()) # Read the number of messages to process

        # Create an instance of the Main class with the provided parameters
        crc = Main(divisor, messageSize, ber)

        # Process the specified number of messages
        for i in range(numMessages):
            crc.refactor() # Reset the message
            crc.generateRandomMess() # Generate a new random message
            crc.divideMessageWithP(False) # Divide the message to append CRC
            crc.changeMess() # Introduce errors in the message
            crc.divideMessageWithP(True) # Check for errors in the modified message

        # Output the results of the message processing
        print("Correct Messages: " + str(crc.getCorrectMess()))
        print("Wrong Messages: " + str(crc.getWrongMess()))
        print("Wrong Messages Caught: " + str(crc.getWrongMessCaught()))
        print("Wrong Messages Not Caught: " + str(crc.getWrongMessNotCaught()))

if __name__ == "__main__":
    Main().main()


