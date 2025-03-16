def bin_print(x, bits):
    # Loop through each bit from the most significant to the least significant
    for i in range(bits - 1, -1, -1):
        # Print 1 if the ith bit is set, otherwise print 0
        print(1 if (x & (1 << i)) else 0, end='')
    # Print a newline after the binary representation
    print()

def main():
    # Read two unsigned integers from standard input
    a, b = map(int, input().split())

    # Print the binary representation of the bitwise AND of a and b
    bin_print(a & b, 32)
    
    # Print the binary representation of the bitwise OR of a and b
    bin_print(a | b, 32)
    
    # Print the binary representation of the bitwise XOR of a and b
    bin_print(a ^ b, 32)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
