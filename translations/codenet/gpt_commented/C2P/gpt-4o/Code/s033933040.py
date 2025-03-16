# Main function where the execution of the program begins
def main():
    # Read two integer inputs from the user representing the dimensions
    a, b = map(int, input().split())
    
    # Calculate the perimeter (mawari) of the rectangle
    mawari = a + a + b + b  # Perimeter formula: 2 * (length + width)
    
    # Calculate the area (menseki) of the rectangle
    menseki = a * b  # Area formula: length * width
    
    # Print the area and perimeter to the console
    print(menseki, mawari)

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
