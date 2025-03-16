
import sys

def main():
    for line in sys.stdin:
        line = line.strip()
        if line == "1":
            print("Hello World")
        elif line == "2":
            sum = 0
            for _ in range(2):
                line = sys.stdin.readline().strip()
                num = int(line)
                sum += num
            print(sum)

