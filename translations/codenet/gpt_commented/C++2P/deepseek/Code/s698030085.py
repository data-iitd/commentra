def main():
    # Read two integers from the standard input
    a, b = map(int, input().split())

    # Check if the sum of a and b is even
    if (a + b) % 2 == 0:
        # If the sum is even, calculate and output the average
        print((a + b) // 2)
    else:
        # If the sum is odd, output "IMPOSSIBLE"
        print("IMPOSSIBLE")


main()
