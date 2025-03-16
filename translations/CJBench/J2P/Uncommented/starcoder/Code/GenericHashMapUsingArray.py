
class Main:
    def __init__(self):
        self.size = 0
        self.buckets = [[] for _ in range(16)]

    def put(self, key, value):
        bucketIndex = self.hashFunction(key)
        nodes = self.buckets[bucketIndex]
        for node in nodes:
            if node.key == key:
                node.value = value
                return
        nodes.append(Node(key, value))
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
        builder = []
        builder.append("{")
        for nodes in self.buckets:
            for node in nodes:
                builder.append(str(node.key) + " : " + str(node.value) + ", ")
        if len(builder) > 1:
            builder.pop()
        builder.append("}")
        return "".join(builder)

    def hashFunction(self, key):
        return key % len(self.buckets)

    def reHash(self):
        oldBuckets = self.buckets
        self.buckets = [[] for _ in range(len(oldBuckets) * 2)]
        self.size = 0
        for nodes in oldBuckets:
            for node in nodes:
                self.put(node.key, node.value)


class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value


