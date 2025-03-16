import random

class Main:
    def __init__(self, str, size, ber):
        self.correctMess = 0
        self.wrongMess = 0
        self.wrongMessCaught = 0
        self.wrongMessNotCaught = 0
        self.messSize = size
        self.ber = ber
        self.messageChanged = False
        self.message = []
        self.p = [int(char) for char in str]

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
        self.message = []

    def generateRandomMess(self):
        self.message = [random.randint(0, 1) for _ in range(self.messSize)]

    def divideMessageWithP(self, check):
        x = []
        k = self.message.copy()
        if not check:
            k.extend([0] * (len(self.p) - 1))
        
        while k:
            while len(x) < len(self.p) and k:
                x.append(k.pop(0))
            if len(x) == len(self.p):
                x = [x[i] ^ self.p[i] for i in range(len(self.p))]
                while x and x[0] == 0:
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
                self.message[i] ^= 1
        if self.messageChanged:
            self.wrongMess += 1

if __name__ == "__main__":
    divisor = input()
    messageSize = int(input())
    ber = float(input())
    numMessages = int(input())
    
    crc = Main(divisor, messageSize, ber)
    for _ in range(numMessages):
        crc.refactor()
        crc.generateRandomMess()
        crc.divideMessageWithP(False)
        crc.changeMess()
        crc.divideMessageWithP(True)

    print("Correct Messages:", crc.getCorrectMess())
    print("Wrong Messages:", crc.getWrongMess())
    print("Wrong Messages Caught:", crc.getWrongMessCaught())
    print("Wrong Messages Not Caught:", crc.getWrongMessNotCaught())

# <END-OF-CODE>
