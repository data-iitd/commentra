# Include the standard input/output library

def main():  # Define the main function, the entry point of the program
    # Read the number of cells in the grid and the number of rows/columns to be painted
    hcell, wcell = map(int, input().split())
    hpaint, wpaint = map(int, input().split())

    # Calculate the number of black cells
    nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)

    # Calculate the number of white cells
    nwhite = (hcell * wcell) - nblack

    # Print the number of white cells
    print(nwhite)

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
