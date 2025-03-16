
class Node: # Defining a class Node to represent each node in the linked list
    def __init__(self, value):
        self.value = value
        self.next = None

class Main:
    def length(self, head): # Method to find the length of the linked list
        curr = head # Initialize a pointer to traverse the linked list
        count = 0 # Initialize a counter to keep track of the number of nodes in the list
        while curr!= None: # Traverse the linked list until the end is reached
            curr = curr.next
            count += 1
        return count # Return the total number of nodes in the list

    def reverse(self, head, count, k): # Method to reverse a sublist of length k starting from the head of the linked list
        if count < k: # Base case: if the length of the list is less than the required sublist length, return the original head
            return head
        prev = None # Initialize a pointer to keep track of the previous node in the reversed sublist
        count1 = 0 # Initialize a counter to keep track of the number of nodes reversed in this iteration
        curr = head # Initialize a pointer to traverse the linked list starting from the head
        next = None # Initialize a pointer to keep track of the next node in the original list
        while curr!= None and count1 < k: # Traverse the linked list and reverse the sublist of length k
            next = curr.next # Save the next node in the original list
            curr.next = prev # Reverse the next pointer of the current node
            prev = curr # Move the pointer prev to the current node
            curr = next # Move the pointer curr to the next node in the original list
            count1 += 1 # Increment the counter for the number of nodes reversed in this iteration
        if next!= None: # If there are more nodes in the original list after the reversed sublist, recursively reverse the remaining part
            head.next = self.reverse(next, count - k, k)
        return prev # Return the head of the reversed sublist

    def reverseKGroup(self, head, k): # Method to reverse a group of k nodes in the linked list starting from the head
        count = self.length(head) # Find the length of the linked list
        return self.reverse(head, count, k) # Call the reverse() method with the head, length, and group size as arguments

if __name__ == "__main__": # Main method to take input from the user and print the reversed linked list
    n = int(input()) # Read the number of nodes in the linked list from the user
    if n <= 0: # Check if the number of nodes is valid
        print("The linked list must contain at least one node.") # Print an error message and exit the program
        exit()
    head = Node(int(input())) # Create the first node of the linked list and assign its value
    temp = head # Initialize a pointer to traverse the linked list
    for i in range(1, n): # Traverse the linked list and create new nodes, connecting them to the previous node
        temp.next = Node(int(input()))
        temp = temp.next
    k = int(input()) # Read the group size from the user
    reverseKGroup = Main() # Create an instance of the Main class to call the reverseKGroup() method
    head = reverseKGroup.reverseKGroup(head, k) # Call the reverseKGroup() method with the head and group size as arguments
    print("Modified linked list:") # Print the header for the output
    temp = head # Initialize a pointer to traverse the reversed linked list and print its elements
    while temp!= None: # Traverse the linked list and print its elements until the end is reached
        print(temp.value, end=" ")
        temp = temp.next
    print() # Print a newline character at the end of the output

