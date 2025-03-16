import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;
class Main:
    def __init__(self, list):
        self.list = list
        self.actions = []
    def filter(self, predicate):
        self.actions.append(lambda stream: stream.list = [item for item in stream.list if predicate(item)])
        return self
    def map(self, mapper):
        return Main([mapper(item) for item in self.list])
    def collectToList(self):
        for action in self.actions:
            action(self)
        return self.list

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

