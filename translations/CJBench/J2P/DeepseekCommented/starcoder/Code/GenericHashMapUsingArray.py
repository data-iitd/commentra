import java.util.LinkedList;
import java.util.Scanner;
class Main:
    def __init__(self):
        self.size = 0
        self.buckets = [LinkedList() for _ in range(16)]
    def put(self, key, value):
        bucketIndex = self.hashFunction(key)
        nodes = self.buckets[bucketIndex]
        for node in nodes:
            if node.key == key:
                node.value = value
                return
        nodes.add(Node(key, value))
        self.size += 1
        if self.size / len(self.buckets) > 0.75:
            self.reHash()
    def get(self, key):
        bucketIndex = self.hashFunction(key)
        nodes = self.buckets[bucketIndex]
        for node in nodes:
            if node.key == key:
                return node.value
        return None
    def remove(self, key):
        bucketIndex = self.hashFunction(key)
        nodes = self.buckets[bucketIndex]
        target = None
        for node in nodes:
            if node.key == key:
                target = node
                break
        if target!= None:
            nodes.remove(target)
            self.size -= 1
    def containsKey(self, key):
        return self.get(key)!= None
    def size(self):
        return self.size
    def __str__(self):
        builder = ""
        builder += "{"
        for nodes in self.buckets:
            for node in nodes:
                builder += str(node.key) + " : " + str(node.value) + ", "
        if len(builder) > 1:
            builder = builder[:-2]
        builder += "}"
        return builder
    def hashFunction(self, key):
        return key.hashCode() % len(self.buckets)
    def reHash(self):
        oldBuckets = self.buckets
        self.buckets = [LinkedList() for _ in range(len(oldBuckets) * 2)]
        self.size = 0
        for nodes in oldBuckets:
            for node in nodes:
                self.put(node.key, node.value)
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
if __name__ == "__main__":
    scanner = Scanner(System.in)
    hashMap = Main()
    operations = scanner.nextInt()
    scanner.nextLine()
    for i in range(operations):
        command = scanner.next()
        if command == "PUT":
            key = scanner.next()
            value = scanner.next()
            hashMap.put(key, value)
        elif command == "GET":
            key = scanner.next()
            value = hashMap.get(key)
            print(value if value!= None else "NOT FOUND")
        elif command == "REMOVE":
            key = scanner.next()
            hashMap.remove(key)
        elif command == "CONTAINS":
            key = scanner.next()
            print("YES" if hashMap.containsKey(key) else "NO")
        elif command == "SIZE":
            print(hashMap.size())
        elif command == "PRINT":
            print(hashMap)
        else:
            print("INVALID COMMAND")
    scanner.close()
