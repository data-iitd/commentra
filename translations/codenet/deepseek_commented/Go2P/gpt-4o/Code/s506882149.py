def comp(x, a):
    # Check if x is less than a
    if x < a:
        return 0
    return 10  # Return 10 if x is not less than a

if __name__ == "__main__":
    x, a = map(int, input().split())  # Read two integers from standard input
    print(comp(x, a))  # Call the comp function with x and a, and print the result

# <END-OF-CODE>
