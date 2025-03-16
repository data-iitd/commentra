class City:
    def __init__(self, prefecture, year, position):
        self.prefecture = prefecture  # Represents the prefecture number of the city
        self.year = year                # Represents the year the city was established
        self.position = position        # Represents the position of the city in its prefecture

class Cities(list):
    def sort(self):
        super().sort(key=lambda city: city.year)  # Sorts cities by their establishment year

def main():
    n, m = map(int, input().split())  # Reads the number of prefectures and cities from input
    h = {}  # Initializes the map to store cities by their prefecture

    # Loop to read city entries
    for i in range(m):
        x, y = map(int, input().split())  # Reads the prefecture number and year from input
        if x not in h:
            h[x] = Cities([City(x, y, i)])  # Creates a new entry if prefecture doesn't exist
        else:
            h[x].append(City(x, y, i))  # Appends the city to the existing list

    results = [''] * m  # Initializes a list to hold the formatted city strings

    # Loop to sort and format cities
    for cities in h.values():
        cities.sort()  # Sorts the cities within the prefecture
        for idx, city in enumerate(cities):
            results[city.position] = f"{city.prefecture:06d}{idx + 1:06d}"  # Formats the city string

    print("\n".join(results))  # Joins the formatted city strings and prints them

if __name__ == "__main__":
    main()

# <END-OF-CODE>
