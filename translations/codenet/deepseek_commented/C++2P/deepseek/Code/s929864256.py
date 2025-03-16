def main():
    a, b = map(int, input().split())  # Read two integers from standard input

    # Compute the maximum value among a+b, a-b, and a*b
    result = max(a+b, max(a-b, a*b))  # Calculate the maximum value
    print(result)  # Print the maximum value


if __name__ == "__main__":
    main()
