def main():
    # Read four integers from the standard input
    a, b, c, d = map(int, input().split())

    # Check the comparison between the sums of a+b and c+d
    if a + b > c + d:
        print("Left")  # Print "Left" if the sum of a and b is greater than the sum of c and d
    elif a + b < c + d:
        print("Right")  # Print "Right" if the sum of a and b is less than the sum of c and d
    else:
        print("Balanced")  # Print "Balanced" if the sums are equal

# Call the main function
main()

