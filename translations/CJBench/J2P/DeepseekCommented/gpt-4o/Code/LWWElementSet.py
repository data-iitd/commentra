class Element:
    def __init__(self, key, timestamp, bias):
        self.key = key
        self.timestamp = timestamp
        self.bias = bias


class Bias(Enum):
    ADDS = 1
    REMOVALS = 2


class Main:
    def __init__(self):
        self.addSet = {}
        self.removeSet = {}

    def add(self, e):
        self.addSet[e.key] = e

    def remove(self, e):
        if self.lookup(e):
            self.removeSet[e.key] = e

    def lookup(self, e):
        inAddSet = self.addSet.get(e.key)
        inRemoveSet = self.removeSet.get(e.key)
        return inAddSet is not None and (inRemoveSet is None or inAddSet.timestamp > inRemoveSet.timestamp)

    def compare(self, other):
        return set(other.addSet.keys()).issubset(set(self.addSet.keys())) and set(other.removeSet.keys()).issubset(set(self.removeSet.keys()))

    def merge(self, other):
        for e in other.addSet.values():
            if e.key not in self.addSet or self.compare_timestamps(self.addSet[e.key], e):
                self.addSet[e.key] = e
        for e in other.removeSet.values():
            if e.key not in self.removeSet or self.compare_timestamps(self.removeSet.get(e.key), e):
                self.removeSet[e.key] = e

    def compare_timestamps(self, e, other):
        if e.bias != other.bias:
            raise ValueError("Invalid bias value")
        bias = e.bias
        timestamp_comparison = (e.timestamp > other.timestamp) - (e.timestamp < other.timestamp)
        if timestamp_comparison == 0:
            return bias != Bias.ADDS
        return timestamp_comparison < 0

    def print_sets(self):
        print("Add Set:", list(self.addSet.keys()))
        print("Remove Set:", list(self.removeSet.keys()))

    @staticmethod
    def main(args):
        import sys
        input = sys.stdin.read
        data = input().split()
        lwwSet = Main()
        operations = int(data[0])
        index = 1
        for i in range(operations):
            command = data[index]
            key = data[index + 1]
            timestamp = int(data[index + 2])
            bias = Bias[data[index + 3]]
            element = Element(key, timestamp, bias)
            index += 4
            if command == "ADD":
                lwwSet.add(element)
            elif command == "REMOVE":
                lwwSet.remove(element)
        lookup_count = int(data[index])
        index += 1
        for i in range(lookup_count):
            key = data[index]
            lookup_element = Element(key, 0, Bias.ADDS)
            print("Lookup", key + ":", lwwSet.lookup(lookup_element))
            index += 1
        lwwSet.print_sets()


if __name__ == "__main__":
    Main.main(sys.argv)
