
class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val


class Main:
    def __init__(self):
        self.buckets = [LinkedList() for _ in range(10)]
        self.size = 0

    def put(self, key, val):
        hash = abs(key.__hash__() % len(self.buckets))
        nodes = self.buckets[hash]

        for node in nodes:
            if node.key == key:
                node.val = val
                return

        nodes.add(Node(key, val))
        self.size += 1
        if self.size / len(self.buckets) > 0.5:
            self.reHash()

    def reHash(self):
        oldBuckets = self.buckets
        self.buckets = [LinkedList() for _ in range(len(oldBuckets) * 2)]
        self.size = 0
        for nodes in oldBuckets:
            for node in nodes:
                self.put(node.key, node.val)

    def get(self, key):
        hash = abs(key.__hash__() % len(self.buckets))
        nodes = self.buckets[hash]
        for node in nodes:
            if node.key == key:
                return node.val
        return None

    def remove(self, key):
        hash = abs(key.__hash__() % len(self.buckets))
        nodes = self.buckets[hash]

        target = None
        for node in nodes:
            if node.key == key:
                target = node
                break
        if target is not None:
            nodes.remove(target)
            self.size -= 1

    def containsKey(self, key):
        return self.get(key) is not None

    def size(self):
        return self.size

    def __str__(self):
        builder = []
        builder.append("{")
        for nodes in self.buckets:
            for node in nodes:
                builder.append(str(node.key) + " : " + str(node.val) + ", ")
        # Remove trailing comma and space if there are any elements
        if len(builder) > 1:
            builder.pop()
            builder.pop()
        builder.append("}")
        return "".join(builder)


if __name__ == "__main__":
    map = Main()
    sc = Scanner(System.in)

    operations = Integer.parseInt(sc.nextLine().trim())

    for i in range(operations):
        command = sc.nextLine().split(" ")
        if command[0].upper() == "PUT":
            map.put(command[1], command[2])
        elif command[0].upper() == "GET":
            value = map.get(command[1])
            print(value if value is not None else "NOT FOUND")
        elif command[0].upper() == "REMOVE":
            map.remove(command[1])
        elif command[0].upper() == "CONTAINS":
            print("YES" if map.containsKey(command[1]) else "NO")
        elif command[0].upper() == "SIZE":
            print(map.size())
        elif command[0].upper() == "PRINT":
            print(map)
        else:
            print("INVALID COMMAND")

    sc.close()

