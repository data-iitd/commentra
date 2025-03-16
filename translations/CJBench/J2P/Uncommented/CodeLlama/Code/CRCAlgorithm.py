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
        self.p = []
        for i in range(len(divisor)):
            self.p.append(int(divisor[i]))
    def refactor(self):
        self.messageChanged = False
        self.message = []
    def generateRandomMess(self):
        for i in range(self.messageSize):
            self.message.append(random.randint(0, 1))
    def divideMessageWithP(self, check):
        x = []
        k = self.message[:]
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
        if self.messageChanged:
            self.wrongMess += 1
    def main(self):
        for i in range(numMessages):
            self.refactor()
            self.generateRandomMess()
            self.divideMessageWithP(False)
            self.changeMess()
            self.divideMessageWithP(True)
        print("Correct Messages: " + str(self.correctMess))
        print("Wrong Messages: " + str(self.wrongMess))
        print("Wrong Messages Caught: " + str(self.wrongMessCaught))
        print("Wrong Messages Not Caught: " + str(self.wrongMessNotCaught))
if __name__ == "__main__":
    divisor = input()
    messageSize = int(input())
    ber = float(input())
    numMessages = int(input())
    crc = Main(divisor, messageSize, ber)
    crc.main()
    # 