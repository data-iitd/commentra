import sys

class Main:
    def __init__(self):
        tokens = sys.stdin.read().strip().split()
        self.A = int(tokens[0])
        self.B = int(tokens[1])
        self.K = int(tokens[2])
        self.x = self.A
        self.y = self.B

    def calc(self):
        self.x = self.A - self.K  # Subtract K from A to get the new value of x
        if self.x < 0:
            self.y = self.B + self.x  # Adjust B by the negative value of x
            self.x = 0  # Set x to 0 if it becomes negative
            if self.y < 0:
                self.y = 0  # Set y to 0 if it becomes negative

    def show_result(self):
        print(self.x, self.y)  # Print the final values of x and y

if __name__ == "__main__":
    ins = Main()
    ins.calc()
    ins.show_result()

# <END-OF-CODE>
