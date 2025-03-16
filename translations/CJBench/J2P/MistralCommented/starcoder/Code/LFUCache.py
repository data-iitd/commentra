
import collections
import sys

class Node:
    def __init__(self, key, value, frequency):
        self.key = key
        self.value = value
        self.frequency = frequency
        self.previous = None
        self.next = None

class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise Exception("Capacity must be greater than zero.")
        self.capacity = capacity
        self.cache = collections.OrderedDict()

    def get(self, key):
        node = self.cache.get(key)
        if node == None:
            return None
        self.removeNode(node)
        node.frequency += 1
        self.addNodeWithUpdatedFrequency(node)
        return node.value

    def put(self, key, value):
        if self.cache.get(key)!= None:
            node = self.cache.get(key)
            node.value = value
            node.frequency += 1
            self.removeNode(node)
            self.addNodeWithUpdatedFrequency(node)
        else:
            if len(self.cache) >= self.capacity:
                self.cache.popitem(last = False)
            node = Node(key, value, 1)
            self.addNodeWithUpdatedFrequency(node)
            self.cache[key] = node

    def addNodeWithUpdatedFrequency(self, node):
        if self.tail!= None and self.head!= None:
            temp = self.head
            while temp!= None:
                if temp.frequency > node.frequency:
                    if temp == self.head:
                        node.next = temp
                        temp.previous = node
                        self.head = node
                        break
                    else:
                        node.next = temp
                        node.previous = temp.previous
                        temp.previous.next = node
                        temp.previous = node
                        break
                else:
                    temp = temp.next
        else:
            self.tail = node
            self.head = self.tail

    def removeNode(self, node):
        if node.previous!= None:
            node.previous.next = node.next
        else:
            self.head = node.next
        if node.next!= None:
            node.next.previous = node.previous
        else:
            self.tail = node.previous

if __name__ == "__main__":
    capacity = int(sys.stdin.readline().strip())
    operations = int(sys.stdin.readline().strip())
    lfuCache = Main(capacity)
    for i in range(operations):
        operation = sys.stdin.readline().strip()
        if operation == "PUT":
            key = int(sys.stdin.readline().strip())
            value = sys.stdin.readline().strip()
            lfuCache.put(key, value)
            print("Added: (" + str(key) + ", " + value + ")")
        else:
            key = int(sys.stdin.readline().strip())
            result = lfuCache.get(key)
            print("Retrieved: " + (result!= None and result or "null"))

