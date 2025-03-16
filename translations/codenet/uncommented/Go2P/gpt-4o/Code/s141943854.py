import sys

def main():
    sage = input().strip()

    if sage == "1":
        print("Hello World")
    elif sage == "2":
        total = 0
        for _ in range(2):
            num = int(input().strip())
            total += num
        print(total)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
