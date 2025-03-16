# Import necessary modules
import sys

# Define a custom City class with three attributes: prefecture, position, and year.
class City:
    def __init__(self, prefecture, year, position):
        self.prefecture = prefecture
        self.year = year
        self.position = position

# Define a custom Cities class to hold a list of City objects.
class Cities(list):
    def sort(self):
        # Sort the cities based on the year attribute.
        super().sort(key=lambda city: city.year)

# Main function is the entry point of the program.
def main():
    # Read the number of cities and events from the standard input.
    n, m = map(int, sys.stdin.readline().strip().split())

    # Initialize an empty dictionary named h.
    h = {}

    # Read m pairs of integers x and y from the standard input.
    for i in range(m):
        # Read an integer x from the standard input.
        x = int(sys.stdin.readline().strip())
        # Read an integer y from the standard input.
        y = int(sys.stdin.readline().strip())

        # Check if the prefecture x already exists in the dictionary.
        if x not in h:
            # If the prefecture x does not exist, create a new Cities object.
            h[x] = Cities([City(x, y, i)])
        else:
            # If the prefecture x already exists, append a new City object to the existing Cities object.
            h[x].append(City(x, y, i))

    # Initialize a list named results with length m and empty strings.
    results = [''] * m

    # Iterate through each value v in the dictionary.
    for v in h.values():
        # Sort the Cities object v.
        v.sort()

        # Iterate through each City object ci in the sorted Cities object v.
        for idx, ci in enumerate(v):
            # Format the result string and assign it to the corresponding index in the results list.
            results[ci.position] = f"{ci.prefecture:06d}{idx + 1:06d}"

    # Print the final result by joining the results list with newline characters.
    print("\n".join(results))

# Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
