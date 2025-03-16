class Main:
    def __init__(self, reader):
        tokens = reader.readline().split()
        self.A = int(tokens[0])
        self.B = int(tokens[1])
        self.K = int(tokens[2])
        self.x, self.y = self.A, self.B

    def calc(self):
        self.x = self.A - self.K
        if self.x < 0:
            self.y = self.B + self.x
            self.x = 0
            if self.y < 0:
                self.y = 0

    def showResult(self):
        print(f"{self.x} {self.y}")


# Main function to run the program
def main():
    import sys
    reader = sys.stdin
    ins = Main(reader)
    ins.calc()
    ins.showResult()


if __name__ == "__main__":
    main()
