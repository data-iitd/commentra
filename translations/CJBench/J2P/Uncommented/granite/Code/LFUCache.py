

class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than zero.")
        self.capacity = capacity
        self.cache = {}
        self.head = None
        self.tail = None

    def get(self, key):
        node = self.cache.get(key)
        if node is None:
            return None
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
                del self.cache[self.head.key]
                self.remove_node(self.head)
            node = Node(key, value, 1)
            self.add_node_with_updated_frequency(node)
            self.cache[key] = node

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
                    if temp is None:
                        self.tail.next = node
                        node.previous = self.tail
                        node.next = None
                        self.tail = node
                        break
        else:
            self.tail = node
            self.head = self.tail

    def remove_node(self, node):
        if node.previous is not None:
            node.previous.next = node.next
        else:
            self.head = node.next
        if node.next is not None:
            node.next.previous = node.previous
        else:
            self.tail = node.previous

if __name__ == "__main__":
    import sys
    capacity, operations = map(int, sys.stdin.readline().split())
    lfu_cache = Main(capacity)
    for _ in range(operations):
        operation, *args = sys.stdin.readline().split()
        if operation == "PUT":
            key, value = map(int, args)
            lfu_cache.put(key, value)
            print(f"Added: ({key}, {value})")
        elif operation == "GET":
            key = int(args[0])
            result = lfu_cache.get(key)
            print(f"Retrieved: {result if result is not None else 'null'}")

