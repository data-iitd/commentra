
import random

class Main:
    def __init__(self, divisor, messageSize, ber):
        self.divisor = divisor
        self.messageSize = messageSize
        self.ber = ber
        self.correctMess = 0
        self.wrongMess = 0
        self.wrongMessCaught = 0
        self.wrongMessNotCaught = 0
        self.messageChanged = False
        self.message = []

    def generateRandomMess(self):
        for i in range(self.messageSize):
            x = random.randint(0, 1)
            self.message.append(x)

    def divideMessageWithP(self, check):
        x = []
        k = self.message[:]
        if not check:
            for i in range(len(self.divisor) - 1):
                k.append(0)
        while k:
            while len(x) < len(self.divisor) and k:
                x.append(k.pop(0))
            if len(x) == len(self.divisor):
                for i in range(len(self.divisor)):
                    x[i] = x[i] ^ int(self.divisor[i])
                while x and x[0] == 0:
                    x.pop(0)
        if not check:
            self.message.extend(x)
        else:
            if 1 in x and self.messageChanged:
                self.wrongMessCaught += 1
            elif not 1 in x and self.messageChanged:
                self.wrongMessNotCaught += 1
            elif not self.messageChanged:
                self.correctMess += 1

    def changeMess(self):
        for i in range(len(self.message)):
            if random.random() < self.ber:
                self.messageChanged = True
                self.message[i] = self.message[i] ^ 1

    def main(self):
        # Read CRC divisor (binary string), message size, and BER
        divisor = input()
        messageSize = int(input())
        ber = float(input())

        # Number of messages to transmit
        numMessages = int(input())

        crc = Main(divisor, messageSize, ber)

        for i in range(numMessages):
            crc.refactor()
            crc.generateRandomMess()
            crc.divideMessageWithP(False) # Append CRC to the message
            crc.changeMess() # Simulate errors in transmission
            crc.divideMessageWithP(True) # Check received message

        # Output results
        print("Correct Messages:", crc.correctMess)
        print("Wrong Messages:", crc.wrongMess)
        print("Wrong Messages Caught:", crc.wrongMessCaught)
        print("Wrong Messages Not Caught:", crc.wrongMessNotCaught)

if __name__ == "__main__":
    crc = Main()
    crc.main()

