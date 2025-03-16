
class Main:
    def __init__(self):
        self.buckets = [[] for _ in range(10)]
        self.size = 0

    def put(self, key, value):
        hash = abs(hash(key)) % len(self.buckets)
        for node in self.buckets[hash]:
            if node[0] == key:
                node[1] = value
                return
        self.buckets[hash].append([key, value])
        self.size += 1
        if self.size / len(self.buckets) > 0.5:
            self.rehash()

    def rehash(self):
        old_buckets = self.buckets
        self.buckets = [[] for _ in range(len(old_buckets) * 2)]
        self.size = 0
        for nodes in old_buckets:
            for node in nodes:
                self.put(node[0], node[1])

    def get(self, key):
        hash = abs(hash(key)) % len(self.buckets)
        for node in self.buckets[hash]:
            if node[0] == key:
                return node[1]
        return None

    def remove(self, key):
        hash = abs(hash(key)) % len(self.buckets)
        for i, node in enumerate(self.buckets[hash]):
            if node[0] == key:
                del self.buckets[hash][i]
                self.size -= 1
                return

    def containsKey(self, key):
        return self.get(key)!= None

    def size(self):
        return self.size

    def __str__(self):
        builder = []
        builder.append("{")
        for nodes in self.buckets:
            for node in nodes:
                builder.append(str(node[0])).append(" : ").append(str(node[1])).append(", ")
        if len(builder) > 1:
            builder.pop()
        builder.append("}")
        return "".join(builder)


# 