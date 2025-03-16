def main():
    s = input()  # Step 1: The program starts by taking a string input from the user.

    count = 0  # Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
    counter = []

    if s == "":  # Step 3: It checks if the input string is empty and returns immediately if it is.
        return

    counter.append(0)  # Step 4: It splits the input string into individual characters.
    li = list(s)

    for char in li:  # Step 5: It iterates through each character in the split string, incrementing the count for valid characters and resetting the count for invalid characters.
        if char in "ACGT":
            count += 1
        else:
            counter.append(count)
            count = 0

    counter.append(count)  # Step 6: It appends the final count to the counter array and sorts the array.
    counter.sort()
    print(counter[-1])  # Step 7: Finally, it prints the maximum value in the sorted counter array.

if __name__ == "__main__":
    main()

# <END-OF-CODE>
