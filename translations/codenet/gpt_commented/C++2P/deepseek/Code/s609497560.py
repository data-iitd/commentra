def main():
    a = int(input("Enter a number: "))  # Read the input value from the user and convert it to an integer

    # Calculate the expression a + a^2 + a^3 and output the result
    result = a + (a * a) + (a * a * a)
    print(result)


if __name__ == "__main__":
    main()

