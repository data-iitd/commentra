class City:
    def __init__(self, prefecture, year, position):
        self.prefecture = prefecture  # Prefecture number
        self.year = year                # Year associated with the city
        self.position = position        # Position in the input

def main():
    n, m = map(int, input().split())  # n: number of prefectures, m: number of cities
    
    # Initialize a dictionary to hold cities grouped by their prefecture
    h = {}
    
    # Read city data from input
    for i in range(m):
        x, y = map(int, input().split())  # x: prefecture number, y: year
        
        # Check if the prefecture already exists in the dictionary
        if x not in h:
            # If it doesn't exist, create a new entry with the city
            h[x] = [City(x, y, i)]
        else:
            # If it exists, append the new city to the existing list
            h[x].append(City(x, y, i))

    # Prepare a results list to hold formatted output for each city
    results = [''] * m

    # Iterate over each group of cities in the dictionary
    for cities in h.values():
        # Sort the cities by year
        cities.sort(key=lambda city: city.year)
        # Format the output for each city based on its position and year
        for idx, city in enumerate(cities):
            results[city.position] = f"{city.prefecture:06d}{idx + 1:06d}"
    
    # Print the results, joining them with newline characters
    print("\n".join(results))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
