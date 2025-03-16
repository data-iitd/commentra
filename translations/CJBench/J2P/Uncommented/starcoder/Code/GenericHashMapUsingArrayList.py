
class Main:
    def __init__(self):
        self.buckets = [[] for _ in range(10)]
        self.size = 0

    def put(self, key, value):
        hash = abs(hash(key)) % len(self.buckets)
        nodes = self.buckets[hash]
        for node in nodes:
            if node.key == key:
                node.val = value
                return
        nodes.append(Node(key, value))
        self.size += 1
        if self.size / len(self.buckets) > 0.5:
            self.reHash()

    def reHash(self):
        oldBuckets = self.buckets
        self.buckets = [[] for _ in range(len(oldBuckets) * 2)]
        self.size = 0
        for nodes in oldBuckets:
            for node in nodes:
                self.put(node.key, node.val)

    def get(self, key):
        hash = abs(hash(key)) % len(self.buckets)
        nodes = self.buckets[hash]
        for node in nodes:
            if node.key == key:
                return node.val
        return None

    def remove(self, key):
        hash = abs(hash(key)) % len(self.buckets)
        nodes = self.buckets[hash]
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
                builder.append(str(node.key) + " : " + str(node.val) + ", ")
        if len(builder) > 1:
            builder.pop()
        builder.append("}")
        return "".join(builder)

    class Node:
        def __init__(self, key, val):
            self.key = key
            self.val = val


