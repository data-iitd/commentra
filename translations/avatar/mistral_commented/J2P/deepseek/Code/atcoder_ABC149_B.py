import sys

class Main:
    def __init__(self, input_lines):
        self.A, self.B, self.K = map(int, input_lines[0].split())
        self.x, self.y = self.A, self.B

    def calc(self):
        self.x = self.A - self.K
        if self.x < 0:
            self.y = self.B + self.x
            self.x = 0
        if self.y < 0:
            self.y = 0

    def show_result(self):
        print(self.x, self.y)

if __name__ == "__main__":
    input_lines = sys.stdin.readline().strip().split()
    main_instance = Main(input_lines)
    main_instance.calc()
    main_instance.show_result()

