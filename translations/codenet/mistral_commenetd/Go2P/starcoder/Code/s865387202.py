# Import the 'collections' package for ordered dictionaries.
import collections

# Define a custom city class with three fields: prefecture, position, and year.
class city:
	def __init__(self, prefecture, position, year):
		self.prefecture = prefecture
		self.position = position
		self.year = year

# Define a custom cities class as a list of city objects.
class cities(list):
	# Define a custom method for sorting the cities list.
	def sort(self):
		self.sort(key=lambda x: x.year)

# Define a custom cMap class as an ordered dictionary with an integer key and a cities list as the value.
class cMap(collections.OrderedDict):
	# Define a custom method for reading the input.
	def read(self):
		# Read the number of cities and events from the standard input.
		n, m = map(int, input().split())

		# Iterate through each pair of integers x and y.
		for i in range(m):
			# Read an integer x from the standard input.
			x = int(input())

			# Read an integer y from the standard input.
			y = int(input())

			# Check if the prefecture x already exists in the cMap.
			if x not in self:
				# If the prefecture x does not exist in the cMap, create a new cities list with one element and assign it to the key x in the cMap.
				self[x] = cities([city(x, 0, y)])
			else:
				# If the prefecture x already exists in the cMap, append a new city object to the existing cities list.
				self[x].append(city(x, len(self[x]), y))

# Define a custom method for printing the output.
def print_output(results):
	# Print the final result using the 'join' method and the 'print' function.
	print(''.join(results))

# Main function is the entry point of the program.
def main():
	# Initialize an empty cMap named h.
	h = cMap()

	# Read the input and assign the result to the h variable.
	h.read()

	# Initialize a list named results with length m and zeroed elements.
	results = [''] * m

	# Iterate through each value v in the cMap.
	for _, v in h.items():
		# Sort the cities list v using the sort method.
		v.sort()

		# Iterate through each city object ci in the sorted cities list v.
		for idx, ci in enumerate(v):
			# Format the result string using the 'format' method and assign it to the corresponding index in the results list.
			results[ci.position] = '{:06d}{:06d}'.format(ci.prefecture, idx+1)

	# Print the final result using the print_output function.
	print_output(results)

# Call the main function.
if __name__ == '__main__':
	main()

# End of code

