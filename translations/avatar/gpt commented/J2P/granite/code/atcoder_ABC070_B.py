
import sys

def main():
    # Read four integers from input
    a, b, c, d = map(int, sys.stdin.readline().split())

    # Check conditions to determine the output
    if c > b:
        # If c is greater than b, output 0
        print(0)
    elif a > d:
        # If a is greater than d, output 0
        print(0)
    elif a < c:
        # If a is less than c, calculate and output the difference
        print(min(b, d) - c)
    else:
        # Create a list to hold the four integers
        l = [a, b, c, d]

        # Sort the list to find the second largest and third largest values
        l.sort()

        # Output the difference between the second largest and third largest values
        print(l[2] - l[1])

if __name__ == "__main__":
    main()

