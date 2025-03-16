class Node:
    def __init__(self, key, value, frequency):
        self.key = key
        self.value = value
        self.frequency = frequency
        self.previous = None
        self.next = None

class LFUCache:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than zero.")
        self.capacity = capacity
        self.cache = {}
        self.head = None
        self.tail = None

    def get(self, key):
        if key not in self.cache:
            return None
        node = self.cache[key]
        self._remove_node(node)
        node.frequency += 1
        self._add_node_with_updated_frequency(node)
        return node.value

    def put(self, key, value):
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            node.frequency += 1
            self._remove_node(node)
            self._add_node_with_updated_frequency(node)
        else:
            if len(self.cache) >= self.capacity:
                del self.cache[self.head.key]
                self._remove_node(self.head)
            node = Node(key, value, 1)
            self.cache[key] = node
            self._add_node_with_updated_frequency(node)

    def _add_node_with_updated_frequency(self, node):
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
                    if temp is None:
                        self.tail.next = node
                        node.previous = self.tail
                        node.next = None
                        self.tail = node
                        break
        else:
            self.tail = node
            self.head = self.tail

    def _remove_node(self, node):
        if node.previous:
            node.previous.next = node.next
        else:
            self.head = node.next
        if node.next:
            node.next.previous = node.previous
        else:
            self.tail = node.previous

# Example usage:
# lfu = LFUCache(2)
# lfu.put(1, "one")
# lfu.put(2, "two")
# print(lfu.get(1))  # Output: "one"
# lfu.put(3, "three")  # This will evict key 2
# print(lfu.get(2))  # Output: None
# print(lfu.get(3))  # Output: "three"
# print(lfu.get(1))  # Output: "one"
