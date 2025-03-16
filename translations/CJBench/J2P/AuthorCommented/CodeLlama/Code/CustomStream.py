
import sys

# Input the number of items
n = int(input())
list = []

# Input each item
for i in range(n):
    x, y = map(int, input().split())
    list.append((x, y))

# Create Main
stream = Main(list)

# Filter and map based on conditions
result = stream \
    .filter(lambda item: item[1] > 10) \
    .map(lambda item: item[0]) \
    .collectToList()

# Print the result
print(result)

class Main:
    def __init__(self, list):
        self.list = list

    def filter(self, predicate):
        self.list = [item for item in self.list if predicate(item)]
        return self

    def map(self, mapper):
        return Main([mapper(item) for item in self.list])

    def collectToList(self):
        return self.list

# END-OF-CODE
