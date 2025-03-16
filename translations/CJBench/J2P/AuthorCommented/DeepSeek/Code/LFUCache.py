class Node:
    def __init__(self, key, value, frequency):
        self.key = key
        self.value = value
        self.frequency = frequency
        self.previous = None
        self.next = None


class LFUCache:
    def __init__(self, capacity: int):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than zero.")
        self.capacity = capacity
        self.cache = {}
        self.head = None
        self.tail = None

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self._remove_node(node)
        node.frequency += 1
        self._add_node_with_updated_frequency(node)
        return node.value

    def put(self, key: int, value: int):
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

    def _add_node_with_updated_frequency(self, node: Node):
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

    def _remove_node(self, node: Node):
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
# lfu.put(1, 1)
# lfu.put(2, 2)
# print(lfu.get(1))  # returns 1
# lfu.put(3, 3)      # evicts key 2
# print(lfu.get(2))  # returns -1 (not found)
# print(lfu.get(3))  # returns 3
# lfu.put(4, 4)      # evicts key 1
# print(lfu.get(1))  # returns -1 (not found)
# print(lfu.get(3))  # returns 3
# print(lfu.get(4))  # returns 4
