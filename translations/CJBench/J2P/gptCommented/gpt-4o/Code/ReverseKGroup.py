class Node:
    def __init__(self, value):
        self.value = value  # Value of the node
        self.next = None    # Pointer to the next node in the list

class Main:
    # Method to calculate the length of the linked list
    def length(self, head):
        curr = head  # Start from the head of the list
        count = 0    # Initialize count of nodes
        # Traverse the list until the end
        while curr is not None:
            curr = curr.next  # Move to the next node
            count += 1        # Increment the count
        return count  # Return the total count of nodes

    # Method to reverse the linked list in groups of k nodes
    def reverse(self, head, count, k):
        # If the remaining nodes are less than k, return the head as is
        if count < k:
            return head

        prev = None  # Previous node initialized to None
        count1 = 0   # Counter for the current group
        curr = head  # Current node starts at head
        next_node = None  # Next node placeholder

        # Reverse k nodes in the current group
        while curr is not None and count1 < k:
            next_node = curr.next  # Store the next node
            curr.next = prev       # Reverse the link
            prev = curr            # Move prev to current node
            curr = next_node       # Move to the next node
            count1 += 1           # Increment the count for the current group

        # Recursively reverse the next groups and link them
        if next_node is not None:
            head.next = self.reverse(next_node, count - k, k)
        return prev  # Return the new head of the reversed group

    # Method to initiate the reversal of the linked list in k-sized groups
    def reverseKGroup(self, head, k):
        count = self.length(head)  # Get the total length of the list
        return self.reverse(head, count, k)  # Call the reverse method

# Main execution
if __name__ == "__main__":
    n = int(input("Enter the number of nodes: "))  # Read the number of nodes

    # Check if the number of nodes is valid
    if n <= 0:
        print("The linked list must contain at least one node.")
    else:
        # Create the head of the linked list
        head = Node(int(input("Enter node value: ")))
        temp = head  # Temporary pointer for building the list

        # Build the linked list from the input values
        for i in range(1, n):
            temp.next = Node(int(input("Enter node value: ")))  # Create new node and link it
            temp = temp.next  # Move the temporary pointer to the new node

        k = int(input("Enter the value of k for group reversal: "))  # Read the value of k
        reverseKGroup = Main()  # Create an instance of Main
        head = reverseKGroup.reverseKGroup(head, k)  # Reverse the linked list in k groups

        # Print the modified linked list
        print("Modified linked list:")
        temp = head  # Reset temp to the head of the modified list
        while temp is not None:
            print(temp.value, end=" ")  # Print the value of each node
            temp = temp.next  # Move to the next node
        print()  # Print a new line after the list
