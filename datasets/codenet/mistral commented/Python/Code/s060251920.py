def main():
    # Get user input as a list of strings
    input_list = input().split()

    # Transform the list into a list of integers
    a, b = map(int, input_list)

    # Calculate the product of a and b
    product = a * b

    # Print the product
    print(product)

main()
