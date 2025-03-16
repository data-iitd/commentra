import sys

# max function: Returns the larger of two integers.
def max_value(a, b):
    return b if a < b else a

# Main function: Reads two integers A and B,
# and calculates the maximum value among A+B, A-B, and A*B.
def main():
    A, B = map(int, sys.stdin.readline().split())
    
    mx = max_value(A + B, A - B)
    mx = max_value(mx, A * B)
    print(mx)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
