import random
import sys

class Main:
    def __init__(self, divisor, messageSize, ber):
        self.correctMess = 0
        self.wrongMess = 0
        self.wrongMessCaught = 0
        self.wrongMessNotCaught = 0
        self.messSize = messageSize
        self.ber = ber
        self.messageChanged = False
        self.message = []
        self.p = []
        for i in range(len(divisor)):
            self.p.append(int(divisor[i]))
        self.message = [0] * self.messSize

    def getWrongMess(self):
        return self.wrongMess

    def getWrongMessCaught(self):
        return self.wrongMessCaught

    def getWrongMessNotCaught(self):
        return self.wrongMessNotCaught

    def getCorrectMess(self):
        return self.correctMess

    def refactor(self):
        self.messageChanged = False
        self.message = [0] * self.messSize

    def generateRandomMess(self):
        for i in range(self.messSize):
            x = random.randint(0, 1)
            self.message[i] = x

    def divideMessageWithP(self, check):
        x = []
        k = self.message.copy()
        if not check:
            for i in range(len(self.p) - 1):
                k.append(0)
        while len(k) > 0:
            while len(x) < len(self.p) and len(k) > 0:
                x.append(k.pop(0))
            if len(x) == len(self.p):
                for i in range(len(self.p)):
                    x[i] = x[i] ^ self.p[i]
                while len(x) > 0 and x[0] == 0:
                    x.pop(0)
            if not check:
                self.message.extend(x)
            else:
                if 1 in x and self.messageChanged:
                    self.wrongMessCaught += 1
                elif 1 not in x and self.messageChanged:
                    self.wrongMessNotCaught += 1
                elif not self.messageChanged:
                    self.correctMess += 1

    def changeMess(self):
        for i in range(len(self.message)):
            if random.random() < self.ber:
                self.messageChanged = True
                self.message[i] = self.message[i] ^ 1
        if self.messageChanged:
            self.wrongMess += 1

if __name__ == "__main__":
    divisor = sys.stdin.readline().strip()
    messageSize = int(sys.stdin.readline().strip())
    ber = float(sys.stdin.readline().strip())
    numMessages = int(sys.stdin.readline().strip())
    crc = Main(divisor, messageSize, ber)
    for i in range(numMessages):
        crc.refactor()
        crc.generateRandomMess()
        crc.divideMessageWithP(False)
        crc.changeMess()
        crc.divideMessageWithP(True)
    print("Correct Messages: " + str(crc.getCorrectMess()))
    print("Wrong Messages: " + str(crc.getWrongMess()))
    print("Wrong Messages Caught: " + str(crc.getWrongMessCaught()))
    print("Wrong Messages Not Caught: " + str(crc.getWrongMessNotCaught()))

