#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define nil None

class Node:
    def __init__(self, key):
        self.key = key
        self.next = nil
        self.prev = nil

    def __str__(self):
        return str(self.key)

    def __repr__(self):
        return str(self.key)

class List:
    def __init__(self):
        self.head = Node(None)
        self.tail = Node(None)
        self.head.next = self.tail
        self.tail.prev = self.head

    def __str__(self):
        cur = self.head.next
        isf = 1
        s = ""
        while cur != self.tail:
            if isf == 0:
                s += " "
            s += str(cur)
            cur = cur.next
            isf = 0
        return s

    def search(self, key):
        cur = self.head.next
        while cur != self.tail:
            if cur.key == key:
                return cur
            cur = cur.next
        return nil

    def insert(self, key):
        x = Node(key)
        x.prev = self.head
        x.next = self.head.next
        x.next.prev = x
        self.head.next = x

    def deleteFirst(self):
        t = self.head.next
        if t == self.tail:
            return
        t.prev.next = t.next
        t.next.prev = t.prev
        del t

    def deleteLast(self):
        t = self.tail.prev
        if t == self.head:
            return
        t.prev.next = t.next
        t.next.prev = t.prev
        del t

    def deleteKey(self, key):
        t = self.search(key)
        if t != nil:
            t.prev.next = t.next
            t.next.prev = t.prev
            del t

    def printList(self):
        print(self)

    def size(self):
        cur = self.head.next
        size = 0
        while cur != self.tail:
            size += 1
            cur = cur.next
        return size

    def __len__(self):
        return self.size()

    def __iter__(self):
        cur = self.head.next
        while cur != self.tail:
            yield cur
            cur = cur.next

    def __getitem__(self, key):
        if key < 0:
            key = len(self) + key
        cur = self.head.next
        for i in range(key):
            cur = cur.next
        return cur

    def __setitem__(self, key, value):
        if key < 0:
            key = len(self) + key
        cur = self.head.next
        for i in range(key):
            cur = cur.next
        cur.key = value

    def __delitem__(self, key):
        if key < 0:
            key = len(self) + key
        cur = self.head.next
        for i in range(key):
            cur = cur.next
        cur.prev.next = cur.next
        cur.next.prev = cur.prev
        del cur

    def __contains__(self, key):
        return self.search(key) != nil

    def __eq__(self, other):
        if len(self) != len(other):
            return False
        for i in range(len(self)):
            if self[i] != other[i]:
                return False
        return True

    def __ne__(self, other):
        return not self.__eq__(other)

    def __lt__(self, other):
        if len(self) != len(other):
            return len(self) < len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                return self[i] < other[i]
        return False

    def __le__(self, other):
        if len(self) != len(other):
            return len(self) <= len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                return self[i] <= other[i]
        return True

    def __gt__(self, other):
        if len(self) != len(other):
            return len(self) > len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                return self[i] > other[i]
        return False

    def __ge__(self, other):
        if len(self) != len(other):
            return len(self) >= len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                return self[i] >= other[i]
        return True

    def __add__(self, other):
        new = List()
        for i in self:
            new.insert(i.key)
        for i in other:
            new.insert(i.key)
        return new

    def __radd__(self, other):
        new = List()
        for i in other:
            new.insert(i.key)
        for i in self:
            new.insert(i.key)
        return new

    def __mul__(self, other):
        new = List()
        for i in range(other):
            for j in self:
                new.insert(j.key)
        return new

    def __rmul__(self, other):
        new = List()
        for i in range(other):
            for j in self:
                new.insert(j.key)
        return new

    def __iadd__(self, other):
        for i in other:
            self.insert(i.key)
        return self

    def __imul__(self, other):
        new = List()
        for i in range(other):
            for j in self:
                new.insert(j.key)
        self = new
        return self

    def __reversed__(self):
        cur = self.tail.prev
        while cur != self.head:
            yield cur
            cur = cur.prev

    def __copy__(self):
        new = List()
        for i in self:
            new.insert(i.key)
        return new

    def __deepcopy__(self, memo):
        new = List()
        for i in self:
            new.insert(i.key)
        return new

    def __sizeof__(self):
        return super().__sizeof__() + sum(map(sys.getsizeof, self))

    def __bool__(self):
        return self.head.next != self.tail

    def __nonzero__(self):
        return self.head.next != self.tail

    def __len__(self):
        return len(self)

    def __iter__(self):
        return iter(self)

    def __next__(self):
        if self.head.next == self.tail:
            raise StopIteration
        cur = self.head.next
        self.head.next = cur.next
        cur.next.prev = self.head
        return cur

    def __reversed__(self):
        return reversed(self)

    def __contains__(self, key):
        return self.search(key) != nil

    def __eq__(self, other):
        if len(self) != len(other):
            return False
        for i in range(len(self)):
            if self[i] != other[i]:
                return False
        return True

    def __ne__(self, other):
        return not self.__eq__(other)

    def __lt__(self, other):
        if len(self) != len(other):
            return len(self) < len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                return self[i] < other[i]
        return False

    def __le__(self, other):
        if len(self) != len(other):
            return len(self) <= len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                return self[i] <= other[i]
        return True

    def __gt__(self, other):
        if len(self) != len(other):
            return len(self) > len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                return self[i] > other[i]
        return False

    def __ge__(self, other):
        if len(self) != len(other):
            return len(self) >= len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                return self[i] >= other[i]
        return True

    def __add__(self, other):
        new = List()
        for i in self:
            new.insert(i.key)
        for i in other:
            new.insert(i.key)
        return new

    def __radd__(self, other):
        new = List()
        for i in other:
            new.insert(i.key)
        for i in self:
            new.insert(i.key)
        return new

    def __mul__(self, other):
        new = List()
        for i in range(other):
            for j in self:
                new.insert(j.key)
        return new

    def __rmul__(self, other):
        new = List()
        for i in range(other):
            for j in self:
                new.insert(j.key)
        return new

    def __iadd__(self, other):
        for i in other:
            self.insert(i.key)
        return self

    def __imul__(self, other):
        new = List()
        for i in range(other):
            for j in self:
                new.insert(j.key)
        self = new
        return self

    def __reversed__(self):
        cur = self.tail.prev
        while cur != self.head:
            yield cur
            cur = cur.prev

    def __copy__(self):
        new = List()
        for i in self:
            new.insert(i.key)
        return new

    def __deepcopy__(self, memo):
        new = List()
        for i in self:
            new.insert(i.key)
        return new

    def __sizeof__(self):
        return super().__sizeof__() + sum(map(sys.getsizeof, self))

    def __bool__(self):
        return self.head.next != self.tail

    def __nonzero__(self):
        return self.head.next != self.tail

    def __len__(self):
        return len(self)

    def __iter__(self):
        return iter(self)

    def __next__(self):
        if self.head.next == self.tail:
            raise StopIteration
        cur = self.head.next
        self.head.next = cur.next
        cur.next.prev = self.head
        return cur

    def __reversed__(self):
        return reversed(self)

    def __contains__(self, key):
        return self.search(key) != nil

    def __eq__(self, other):
        if len(self) != len(other):
            return False
        for i in range(len(self)):
            if self[i] != other[i]:
                return False
        return True

    def __ne__(self, other):
        return not self.__eq__(other)

    def __lt__(self, other):
        if len(self) != len(other):
            return len(self) < len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                return self[i] < other[i]
        return False

    def __le__(self, other):
        if len(self) != len(other):
            return len(self) <= len(other)
        for i in range(len(self)):
            if self[i] != other[i]:
                retu