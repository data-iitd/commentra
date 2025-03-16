import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;

class Main:
    def __init__(self, list):
        self.list = list
        self.actions = []

    def filter(self, predicate):
        self.actions.append(lambda stream: {
            result = []
            for item in stream.list:
                if predicate(item):
                    result.append(item)
            stream.list = result
        })
        return self

    def map(self, mapper):
        mappedList = []
        for item in self.list:
            mappedList.append(mapper(item))
        return Main(mappedList)

    def collectToList(self):
        for action in self.actions:
            action(self)
        return self.list

if __name__ == '__main__':
    scanner = Scanner(System.in)

    # Input the number of items
    n = scanner.nextInt()
    list = []

    # Input each item
    for i in range(n):
        x = scanner.nextInt()
        y = scanner.nextInt()
        list.append(Item(x, y))

    # Create Main
    stream = Main(list)

    # Filter and map based on conditions
    result = stream \
       .filter(lambda item: item.getY() > 10) \
       .map(lambda item: item.getX()) \
       .collectToList()

    # Print the result
    print(result)

    scanner.close()

