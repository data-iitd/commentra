MAX = 100005  # Maximum size of the queue
N = 100       # Maximum size of the name string

# Define a class to hold a person's name and their time
class Person:
    def __init__(self, name, t):
        self.name = name
        self.t = t

# Declare a queue to hold Person objects
Q = [None] * (MAX + 1)
head = 0
tail = 0

# Function to add an element to the queue
def Enqueue(x):
    global tail
    # Wrap around the tail if it reaches the maximum size
    if tail == MAX:
        tail = 0
    Q[tail] = x  # Add the element to the queue
    tail += 1    # Move the tail pointer forward

# Function to remove and return an element from the queue
def Dequeue():
    global head
    # Wrap around the head if it reaches the maximum size
    if head == MAX:
        head = 0
    person = Q[head]  # Get the element at the head
    head += 1         # Move the head pointer forward
    return person     # Return the element

# Main function
def main():
    global head, tail
    n, q = map(int, input().split())  # Read the number of people and the query time
    T = 0  # Initialize total time

    # Read each person's name and time, and enqueue them
    for _ in range(n):
        name, t = input().split()  # Read name and time
        person = Person(name, int(t))  # Create a Person object
        Enqueue(person)  # Add the person to the queue

    # Process the queue until all people have been served
    while n != 0:
        person = Dequeue()  # Remove the front person from the queue
        # Check if the person's time exceeds the query time
        if person.t > q:
            person.t -= q  # Reduce their time by the query time
            T += q         # Add query time to total time
            Enqueue(person)  # Re-enqueue the person with the remaining time
        else:
            T += person.t  # Add the person's time to total time
            print(person.name, T)  # Print the person's name and total time
            n -= 1  # Decrease the count of people left to serve

if __name__ == "__main__":
    main()
