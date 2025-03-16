# Define the main function
def main():
    # Read input values for q, h, s, d and n
    q, h, s, d = map(int, input().split())
    n = int(input())

    # Calculate the minimum value among q*4, h*2, q*2+h, s
    min_1 = min(q*4, h*2, q*2+h, s)

    # Calculate the minimum value among min_1*2 and d
    min_2 = min(min_1*2, d)

    # Print the result
    print((n % 2)*min_1 + (n // 2)*min_2)

# Run the main function if the script is executed directly
if __name__ == '__main__':
    main()
