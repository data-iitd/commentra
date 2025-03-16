
import java.util.*;

class DoublyLinkedList
{
    node head; // Initialize head pointer to NULL
    
    class node
    {
        int key;
        node next;
        node prev;
    }
    
    node makenode(int a)
    {
        node x; // Allocate memory for new node
        x = new node();
        x.key = a; // Set the key value of the new node
        return x; // Return the new node
    }
    
    // Initialize the head node with a dummy node
    void init()
    {
        head = makenode(0);
        head.next = head;
        head.prev = head;
    }
    
    void insert(int a)
    {
        node x; // Allocate memory for new node
        x = makenode(a);
        
        // Insert new node at the end of the list
        x.next = head.next;
        head.next.prev = x;
        head.next = x;
        x.prev = head;
    }
    
    void delete(int a)
    {
        node x, prev;
        x = head;
        
        // Search for the node to be deleted
        while(x.next!= head)
        {
            x = x.next;
            if(x.key == a) // Found the node to be deleted
            {
                prev = x.prev; // Save the previous node
                prev.next = x.next; // Update the previous node's next pointer
                x.next.prev = prev; // Update the next node's prev pointer
                break;
            }
        }
    }
    
    void deleteFirst()
    {
        node x;
        x = head.next; // Save the second node in a temporary variable
        
        // Update the head pointer and the previous node's next pointer
        head.next = x.next;
        x.next.prev = head;
        
        // Free the memory occupied by the first node
        x = null;
    }
    
    void deleteLast()
    {
        node x, prev;
        x = head;
        
        // Search for the second last node
        while(x.next!= head)
        {
            x = x.next;
        }
        
        prev = x.prev; // Save the previous node
        
        // Update the previous node's next pointer and the head pointer's prev pointer
        prev.next = null;
        head.prev = prev;
        
        // Free the memory occupied by the last node
        x = null;
    }
}

public class Main
{
    public static void main(String[] args)
    {
        DoublyLinkedList list = new DoublyLinkedList();
        list.init(); // Initialize the head node
        
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the number of operations
        
        for(int i=0; i<n; i++)
        {
            String op = sc.next(); // Read the operation
            
            if(op.equals("insert")) // If the operation is to insert a node
            {
                int a = sc.nextInt(); // Read the key value of the node to be inserted
                list.insert(a); // Call the insert function
            }
            else if(op.equals("delete")) // If the operation is to delete a node
            {
                int a = sc.nextInt(); // Read the key value of the node to be deleted
                list.delete(a); // Call the delete function
            }
            else if(op.equals("deleteFirst")) // If the operation is to delete the first node
            {
                list.deleteFirst(); // Call the deleteFirst function
            }
            else if(op.equals("deleteLast")) // If the operation is to delete the last node
            {
                list.deleteLast(); // Call the deleteLast function
            }
        }
        
        node x = list.head; // Initialize a pointer to traverse the list
        
        while(x.next!= list.head) // Traverse the list and print the keys of the nodes
        {
            System.out.print(x.next.key + " ");
            x = x.next;
        }
        
        System.out.println(); // Print a newline character at the end
    }
}

