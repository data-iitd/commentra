import sys

def main():
    z = input().strip()  # Read input string from standard input
    for i in range(len(z) - 1):  # Iterate through the string
        if z[i] == z[i + 1]:  # Check if any two consecutive characters are the same
            print("Bad")  # Print "Bad" if a pair is found and exit
            return
    print("Good")  # Print "Good" if no pair is found

if __name__ == "__main__":
    main()
