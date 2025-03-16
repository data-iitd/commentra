
# Class representing a hash map with open addressing and linked list chaining
class Main:
    def __init__(self, hashSize):
        self.hashSize = hashSize
        self.buckets = [LinkedList() for _ in range(hashSize)]
        self.size = 0

    # Computes the hash code for the given key
    def computeHash(self, key):
        if key == None:
            return 0
        hash = key.hashCode() % self.hashSize
        return hash if hash >= 0 else hash + self.hashSize

    # Inserts the given key-value pair into the hash map
    def insert(self, key, value):
        hash = self.computeHash(key)
        if self.buckets[hash].insert(key, value):
            self.size += 1

    # Deletes the given key-value pair from the hash map
    def delete(self, key):
        hash = self.computeHash(key)
        if self.buckets[hash].delete(key):
            self.size -= 1

    # Searches for the value associated with the given key in the hash map
    def search(self, key):
        hash = self.computeHash(key)
        node = self.buckets[hash].findKey(key)
        return node.value if node!= None else None

    # Displays the contents of the hash map
    def display(self):
        for i in range(self.hashSize):
            print("Bucket {}: {}".format(i, self.buckets[i].display()))

    # Returns the current size of the hash map
    def size(self):
        return self.size

# Inner class representing a node in the hash map
class LinkedList:
    def __init__(self):
        self.head = None

    # Inserts the given key-value pair into the linked list
    def insert(self, key, value):
        existingNode = self.findKey(key)
        if existingNode!= None:
            existingNode.value = value
            return False
        newNode = Node(key, value)
        newNode.next = self.head
        self.head = newNode
        return True

    # Deletes the given key from the linked list
    def delete(self, key):
        if self.head == None:
            return False
        if (key == None and self.head.key == None) or (self.head.key!= None and self.head.key.equals(key)):
            self.head = self.head.next
            return True
        current = self.head
        while current.next!= None:
            if (key == None and current.next.key == None) or (current.next.key!= None and current.next.key.equals(key)):
                current.next = current.next.next
                return True
            current = current.next
        return False

    # Searches for the node containing the given key in the linked list
    def findKey(self, key):
        current = self.head
        while current!= None:
            if (key == None and current.key == None) or (current.key!= None and current.key.equals(key)):
                return current
            current = current.next
        return None

    # Displays the contents of the linked list as a string
    def display(self):
        sb = []
        current = self.head
        while current!= None:
            sb.append("{}={}".format(current.key, current.value))
            current = current.next
            if current!= None:
                sb.append(" -> ")
        return "".join(sb) if len(sb) > 0 else "null"

# Inner class representing a node in the hash map
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

# Main method for testing the hash map implementation
if __name__ == "__main__":
    import sys
    import re

    # Reads the size of the hash map from the input
    hashSize = int(sys.stdin.readline())
    hashMap = Main(hashSize) # Creates a new hash map with the given size

    # Reads the number of operations from the input
    operations = int(sys.stdin.readline())
    sys.stdin.readline() # Consumes the newline character

    # Performs the given operations on the hash map
    for i in range(operations):
        input = sys.stdin.readline().split(" ")
        if input[0] == "PUT":
            hashMap.insert(input[1], input[2])
        elif input[0] == "GET":
            value = hashMap.search(input[1])
            print(value if value!= None else "NOT FOUND")
        elif input[0] == "REMOVE":
            hashMap.delete(input[1])
        elif input[0] == "CONTAINS":
            print("YES" if hashMap.search(input[1])!= None else "NO")
        elif input[0] == "SIZE":
            print(hashMap.size())
        elif input[0] == "PRINT":
            hashMap.display()
        else:
            print("Invalid operation")

