import sys
import io

# Reads an integer from the standard input using a StringTokenizer.
def read_int():
    while not st or not st.has_next():
        st = next(tokens)
    return int(st.next())

# The main method is the entry point of the program.
def main():
    print(solve())

# This method contains the logic to solve the problem.
def solve():
    K = read_int()

    # Check if K is divisible by 2 or 5, return -1 if true.
    if K % 2 == 0 or K % 5 == 0:
        return -1

    # If K is divisible by 7, divide K by 7.
    if K % 7 == 0:
        K //= 7

    # Multiply K by 9.
    K *= 9

    # Initialize the answer and the remainder.
    ans = 1
    remainder = 10 % K

    # Loop to find the number of digits required to form a number that is a multiple of K.
    while remainder != 1:
        ans += 1
        remainder = (remainder * 10) % K

    return ans

# Read from standard input
input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
tokens = iter(input_stream.readline, "")
st = None

if __name__ == "__main__":
    main()
