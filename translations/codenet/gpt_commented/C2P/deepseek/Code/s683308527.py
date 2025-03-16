import sys

def main():
    n = int(input().strip())  # Read the number of lines to process

    for _ in range(n):
        s = input().strip()  # Read a line of input from stdin
        s = s.replace("Hoshino", "Hosha")  # Replace "Hoshino" with "Hosha"
        print(s)  # Print the modified line

if __name__ == "__main__":
    main()
