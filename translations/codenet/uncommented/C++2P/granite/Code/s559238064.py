
import sys

def main():
    z = input()
    a = len(z)
    for i in range(a - 1):
        if z[i] == z[i + 1]:
            print("Bad")
            sys.exit(0)
    print("Good")

if __name__ == "__main__":
    main()

