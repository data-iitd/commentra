
import random

class Main:
    # Declare instance variables
    def __init__(self, divisor, messageSize, ber):
        # Initialize instance variables
        self.correctMess = 0
        self.wrongMess = 0
        self.wrongMessCaught = 0
        self.wrongMessNotCaught = 0
        self.messSize = messageSize
        self.ber = ber
        self.messageChanged = False
        self.message = []
        self.p = []

        # Initialize p list with the given divisor string
        for i in range(len(divisor)):
            self.p.append(int(divisor[i]))

        # Initialize counter variables
        self.correctMess = 0
        self.wrongMess = 0
        self.wrongMessCaught = 0
        self.wrongMessNotCaught = 0
        self.ber = ber

    # Getters for counter variables
    def getWrongMess(self):
        return self.wrongMess

    def getWrongMessCaught(self):
        return self.wrongMessCaught

    def getWrongMessNotCaught(self):
        return self.wrongMessNotCaught

    def getCorrectMess(self):
        return self.correctMess

    # Refactor method to reset instance variables
    def refactor(self):
        self.messageChanged = False
        self.message = []

    # Generate random message method
    def generateRandomMess(self):
        # Generate random message of given size
        for i in range(self.messSize):
            x = random.randint(0, 1)
            self.message.append(x)

    # Divide message with p method without checking
    def divideMessageWithP(self, check):
        x = [] # Initialize x list
        k = self.message.copy() # Initialize k list as a copy of message list

        # If not checking, fill k list with zeros
        if not check:
            for i in range(len(self.p) - 1):
                k.append(0)

        # Divide message with p
        while len(k) > 0:
            while len(x) < len(self.p) and len(k) > 0:
                x.append(k.pop(0))

            # If message size is equal to p size
            if len(x) == len(self.p):
                # Xor each element in x list with corresponding element in p list
                for i in range(len(self.p)):
                    x[i] = x[i] ^ self.p[i]

                # Remove leading zeros from x list
                while len(x) > 0 and x[0] == 0:
                    x.pop(0)
            else:
                break

        # Update counter variables based on the result
        if not check:
            self.message.extend(x)
        else:
            # If message has been changed and 1 is present in x list
            if self.messageChanged and 1 in x:
                self.wrongMessCaught += 1
            # If message has been changed and 1 is not present in x list
            elif self.messageChanged and 1 not in x:
                self.wrongMessNotCaught += 1
            # If message has not been changed
            else:
                self.correctMess += 1

    # Change message method
    def changeMess(self):
        # Change each element in message list with probability ber
        for i in range(len(self.message)):
            if random.random() < self.ber:
                self.messageChanged = True
                self.message[i] = self.message[i] ^ 1

        # Update counter variable if message has been changed
        if self.messageChanged:
            self.wrongMess += 1

# Main method to run the simulation
if __name__ == "__main__":
    # Read input from user
    divisor = input()
    messageSize = int(input())
    ber = float(input())
    numMessages = int(input())

    # Create Main object with given input
    crc = Main(divisor, messageSize, ber)

    # Generate and check messages for given number of times
    for i in range(numMessages):
        crc.refactor() # Refactor before each iteration
        crc.generateRandomMess() # Generate random message
        crc.divideMessageWithP(False) # Divide message with p without checking
        crc.changeMess() # Change message
        crc.divideMessageWithP(True) # Divide message with p and check

    # Print the results
    print("Correct Messages: " + str(crc.getCorrectMess()))
    print("Wrong Messages: " + str(crc.getWrongMess()))
    print("Wrong Messages Caught: " + str(crc.getWrongMessCaught()))
    print("Wrong Messages Not Caught: " + str(crc.getWrongMessNotCaught()))

