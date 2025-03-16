import sys

def main():
    x1 = int(sys.stdin.readline().strip())  # Read the first x-coordinate
    y1 = int(sys.stdin.readline().strip())  # Read the first y-coordinate
    x2 = int(sys.stdin.readline().strip())  # Read the second x-coordinate
    y2 = int(sys.stdin.readline().strip())  # Read the second y-coordinate

    if x1 == x2:  # Check if x1 and x2 are equal
        dif = abs(y1 - y2)  # Calculate the absolute difference between y1 and y2
        print(f"{x1 + dif} {y1} {x1 + dif} {y2}")  # Print the result
    elif y1 == y2:  # Check if y1 and y2 are equal
        dif = abs(x1 - x2)  # Calculate the absolute difference between x1 and x2
        print(f"{x1} {y1 + dif} {x2} {y2 + dif}")  # Print the result
    elif abs(x1 - x2) == abs(y1 - y2):  # Check if the absolute differences are equal
        print(f"{x1} {y2} {x2} {y1}")  # Print the result
    else:  # If none of the above conditions are met
        print(-1)  # Print -1

if __name__ == "__main__":
    main()

# <END-OF-CODE>
