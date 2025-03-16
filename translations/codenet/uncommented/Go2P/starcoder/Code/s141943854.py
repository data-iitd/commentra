import sys

def main():
    if sys.argv[1] == "1":
        print("Hello World")
    elif sys.argv[1] == "2":
        sum = 0
        for i in range(2):
            sum += int(sys.stdin.readline())
        print(sum)

main()

