
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

    def remove_node(self, node):
        if node.previous is not None:
            node.previous.next = node.next
        else:
            self.head = node.next
        if node.next is not None:
            node.next.previous = node.previous
        else:
            self.tail = node.previous

    def add_node_with_updated_frequency(self, node):
        if self.tail is not None and self.head is not None:
            temp = self.head
            while temp is not None:
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

    def main(self):
        scanner = Scanner(System.in)
        capacity = scanner.nextInt()
        operations = scanner.nextInt()
        lfu_cache = LFUCache(capacity)
        for i in range(operations):
            operation = scanner.next()
            if operation == "PUT":
                key = scanner.nextInt()
                value = scanner.next()
                lfu_cache.put(key, value)
                print("Added: (" + str(key) + ", " + value + ")")
            else:
                key = scanner.nextInt()
                result = lfu_cache.get(key)
                print("Retrieved: " + (str(result) if result is not None else "null"))
        scanner.close()

if __name__ == "__main__":
    lfu_cache = LFUCache(3)
    lfu_cache.put(1, "one")
    lfu_cache.put(2, "two")
    lfu_cache.put(3, "three")
    print(lfu_cache.get(1))
    print(lfu_cache.get(2))
    lfu_cache.put(4, "four")
    print(lfu_cache.get(1))
    print(lfu_cache.get(3))
    print(lfu_cache.get(4))
    