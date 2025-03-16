def main():
    # Read height and width of the grid
    h, w = map(int, input().split())

    # Initialize a temporary character array and the target string
    s = "snuke"

    # Iterate through the grid to find the target string
    for i in range(h):
        for j in range(w):
            # Read the current string from input
            t = input().strip()
            # Check if the current string matches the target string
            if t == s:
                # If found, calculate the position and print it
                c = chr(ord('A') + j)  # Convert column index to character
                print(f"{c}{i + 1}")  # Output the position in the required format
                return  # Exit the program after finding the target


# Call the main function
if __name__ == "__main__":
    main()
