#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

int main() 
{ 
    // Create a Scanner object to read input from the console
    Scanner input = new Scanner(System.in); 
    
    // Read the number of required items (n) and the number of available items (m)
    int n = input.nextInt(); 
    int m = input.nextInt(); 
    
    // Initialize ArrayLists to store the required items and the available items
    ArrayList<Integer> req = new ArrayList(); 
    ArrayList<Integer> pre = new ArrayList(); 
    
    // Read the required items from the input and store them in the req list
    for (int i = 0; i < n; i++) { 
        req.add(input.nextInt()); 
    } 
    
    // Read the available items from the input and store them in the pre list
    for (int i = 0; i < m; i++) { 
        pre.add(input.nextInt()); 
    } 
    
    // Initialize pointers for the required items (i) and available items (j)
    int i = n - 1, j = m - 1; 
    
    // Variable to count how many required items can be satisfied
    int ans = 0; 
    
    // Compare the required items with the available items from the end of both lists
    while (i >= 0 && j >= 0) { 
        // If the current required item is greater than the current available item
        if (req.get(i) > pre.get(j)) { 
            // Increment the count of satisfied items
            ans++; 
        } else { 
            // Move to the next available item if the current one cannot satisfy the requirement
            j--; 
        } 
        // Move to the next required item
        i--; 
    } 
    
    // Print the total number of satisfied items plus the remaining unsatisfied required items
    printf("%d", ans + i + 1); 
    return 0; 
} 
