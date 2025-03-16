import sys

def main():
    # Reading the first integer from the standard input
    n = int(input().strip())
    # Initializing the answer variable
    ans = 0.0

    # Iterating through the given number of integers
    for i in range(n):
        # Reading the next integer from the standard input
        tmp = 1 / int(input().strip())
        # Adding the reciprocal of the current integer to the answer
        ans += tmp

    # Printing the final answer
    print("{:.10f}".format(1 / ans))

# Main function call
if __name__ == "__main__":
    main()
