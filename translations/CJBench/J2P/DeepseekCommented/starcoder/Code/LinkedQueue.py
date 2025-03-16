
import java.util.NoSuchElementException;
import java.util.Scanner;
class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None
class Main(object):
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0
    def isEmpty(self):
        return self.size == 0
    def enqueue(self, data):
        if data == None:
            raise IllegalArgumentException("Cannot enqueue null data")
        newNode = Node(data)
        if self.isEmpty():
            self.front = newNode
        else:
            self.rear.next = newNode
        self.rear = newNode
        self.size += 1
    def dequeue(self):
        if self.isEmpty():
            raise NoSuchElementException("Queue is empty")
        retValue = self.front.data
        self.front = self.front.next
        self.size -= 1
        if self.isEmpty():
            self.rear = None
        return retValue
    def peekFront(self):
        if self.isEmpty():
            raise NoSuchElementException("Queue is empty")
        return self.front.data
    def peekRear(self):
        if self.isEmpty():
            raise NoSuchElementException("Queue is empty")
        return self.rear.data
    def size(self):
        return self.size
    def clear(self):
        self.front = None
        self.rear = None
        self.size = 0
    def __str__(self):
        if self.isEmpty():
            return "[]"
        sb = StringBuilder("[")
        current = self.front
        while current!= None:
            sb.append(current.data)
            if current.next!= None:
                sb.append(", ")
            current = current.next
        sb.append("]")
        return sb.toString()
def main():
    scanner = Scanner(System.in)
    queue = Main()
    while scanner.hasNextLine():
        command = scanner.nextLine().trim()
        if command.equalsIgnoreCase("exit"):
            break
        try:
            parts = command.split(" ")
            if parts[0].equals("enqueue"):
                if parts.length < 2:
                    System.out.println("Error: Missing value for enqueue")
                    break
                value = Integer.parseInt(parts[1])
                queue.enqueue(value)
                System.out.println("Enqueued: " + value)
            elif parts[0].equals("dequeue"):
                System.out.println("Dequeued: " + queue.dequeue())
            elif parts[0].equals("peekFront"):
                System.out.println("Front element: " + queue.peekFront())
            elif parts[0].equals("peekRear"):
                System.out.println("Rear element: " + queue.peekRear())
            elif parts[0].equals("size"):
                System.out.println("Size: " + queue.size())
            elif parts[0].equals("isEmpty"):
                System.out.println("Is empty: " + queue.isEmpty())
            elif parts[0].equals("print"):
                System.out.println(queue)
            else:
                System.out.println("Unknown command: " + parts[0])
        except Exception e:
            System.out.println("Error: " + e.getMessage())
    scanner.close()
main()
