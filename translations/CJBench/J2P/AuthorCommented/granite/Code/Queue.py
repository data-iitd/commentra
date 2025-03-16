
import queue

class Main:
    def __init__(self, capacity):
        self.queue = queue.Queue(capacity)

    def insert(self, element):
        try:
            self.queue.put(element, block=False)
            return True
        except queue.Full:
            return False

    def remove(self):
        try:
            return self.queue.get_nowait()
        except queue.Empty:
            raise RuntimeError("Main is empty, cannot remove element")

    def peek_front(self):
        try:
            return self.queue.queue[0]
        except IndexError:
            raise RuntimeError("Main is empty, cannot peek front")

    def peek_rear(self):
        try:
            return self.queue.queue[-1]
        except IndexError:
            raise RuntimeError("Main is empty, cannot peek rear")

    def is_empty(self):
        return self.queue.empty()

    def get_size(self):
        return self.queue.qsize()

    def __str__(self):
        return str(list(self.queue.queue))

if __name__ == "__main__":
    import sys

    print("Enter the size of the queue:")
    size = int(input())
    main = Main(size)

    print("Enter commands (insert <value>, remove, peekFront, peekRear, getSize, isEmpty, print, exit):")
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break

        try:
            parts = command.split()
            if parts[0].lower() == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                value = int(parts[1])
                if main.insert(value):
                    print(f"Inserted: {value}")
                else:
                    print("Main is full")
            elif parts[0].lower() == "remove":
                print(f"Removed: {main.remove()}")
            elif parts[0].lower() == "peekfront":
                print(f"Front: {main.peek_front()}")
            elif parts[0].lower() == "peekrear":
                print(f"Rear: {main.peek_rear()}")
            elif parts[0].lower() == "getsize":
                print(f"Size: {main.get_size()}")
            elif parts[0].lower() == "isempty":
                print(f"Is empty: {main.is_empty()}")
            elif parts[0].lower() == "print":
                print(f"Main: {main}")
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")

    print("