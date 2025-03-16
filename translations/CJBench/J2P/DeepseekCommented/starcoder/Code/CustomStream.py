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

class Item:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def __str__(self):
        return "Item{" + "x=" + str(self.x) + ", y=" + str(self.y) + "}"

if __name__ == "__main__":
    scanner = Scanner(System.in)
    n = scanner.nextInt()
    list = []
    for i in range(n):
        x = scanner.nextInt()
        y = scanner.nextInt()
        list.append(Item(x, y))
    stream = Main(list)
    result = stream.filter(lambda item: item.getY() > 10).map(lambda item: item.getX()).collectToList()
    print(result)
    scanner.close()

