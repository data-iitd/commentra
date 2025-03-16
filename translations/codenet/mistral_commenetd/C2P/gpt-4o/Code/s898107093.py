# Declare variables
def main():
    n = int(input())  # Read the number of strings to be compared from the standard input
    taro = 0  # score for Taro
    hanako = 0  # score for Hanako

    # Initialize the loops for t and h arrays
    for _ in range(n):
        t = input()  # Read string for Taro
        h = input()  # Read string for Hanako

        # Compare the strings and update the scores accordingly
        if t < h:
            hanako += 3  # Hanako gets 3 points if the current string in t is smaller than the corresponding string in h
        elif t > h:
            taro += 3  # Taro gets 3 points if the current string in t is larger than the corresponding string in h
        else:  # If the strings are equal
            taro += 1  # Taro gets 1 point if the strings are equal
            hanako += 1  # Hanako gets 1 point if the strings are equal

    # Print the scores for Taro and Hanako
    print(taro, hanako)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
