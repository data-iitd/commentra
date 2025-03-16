
class Node:
    def __init__(self, key, value, frequency):
        self.key = key
        self.value = value
        self.frequency = frequency
        self.previous = None
        self.next = None

class LFUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = {}
        self.head = None
        self.tail = None

    def get(self, key):
        if key not in self.cache:
            return None
        node = self.cache[key]
        self.remove_node(node)
        node.frequency += 1
        self.add_node_with_updated_frequency(node)
        return node.value

    def put(self, key, value):
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            node.frequency += 1
            self.remove_node(node)
            self.add_node_with_updated_frequency(node)
        else:
            if len(self.cache) >= self.capacity:
                self.cache.pop(self.head.key)
                self.remove_node(self.head)
            node = Node(key, value, 1)
            self.add_node_with_updated_frequency(node)
            self.cache[key] = node

    def add_node_with_updated_frequency(self, node):
        if self.tail and self.head:
            temp = self.head
            while temp:
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
                    if not temp:
                        self.tail.next = node
                        node.previous = self.tail
                        node.next = None
                        self.tail = node
                        break
        else:
            self.tail = node
            self.head = self.tail

    def remove_node(self, node):
        if node.previous:
            node.previous.next = node.next
        else:
            self.head = node.next
        if node.next:
            node.next.previous = node.previous
        else:
            self.tail = node.previous

    def __str__(self):
        return str(self.cache)

if __name__ == "__main__":
    scanner = input
    capacity = int(scanner())
    operations = int(scanner())
    lfu_cache = LFUCache(capacity)
    for _ in range(operations):
        operation = scanner()
        if operation == "PUT":
            key = int(scanner())
            value = scanner()
            lfu_cache.put(key, value)
            print("Added: (" + str(key) + ", " + value + ")")
        else:
            key = int(scanner())
            result = lfu_cache.get(key)
            print("Retrieved: " + (str(result) if result else "null"))
    print("