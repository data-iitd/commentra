def main():
    # Read the input string from the user
    str = input()

    # Create a dictionary to count the frequency of each character in the input string
    map = {}

    # Initialize a counter for characters with odd frequencies
    odd_count = 0

    # Iterate through the input string to populate the frequency map
    for ch in str:
        if ch in map:
            map[ch] += 1
        else:
            map[ch] = 1

    # Iterate through the map to count characters with odd frequencies
    for value in map.values():
        if value % 2 != 0:
            odd_count += 1

    # Determine the winner based on the count of characters with odd frequencies
    if odd_count <= 1 or odd_count % 2 != 0:
        print("First")
    else:
        print("Second")


# Call the main function
main()
