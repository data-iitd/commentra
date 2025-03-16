
import sys

class Main:
    def __init__(self, list):
        self.list = list

    def filter(self, predicate):
        self.list = list(filter(predicate, self.list))
        return self

    def map(self, mapper):
        return Main(list(map(mapper, self.list)))

    def collectToList(self):
        return self.list

def main():
    n = int(input())
    list = []
    for i in range(n):
        x, y = map(int, input().split())
        list.append((x, y))
    stream = Main(list)
    result = stream \
       .filter(lambda item: item[1] > 10) \
       .map(lambda item: item[0]) \
       .collectToList()
    print(result)

if __name__ == "__main__":
    sys.exit(main())

