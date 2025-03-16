#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a Scanner object to read input from the user
    int n;
    scanf("%d", &n);
    
    // Read the number of integers to be processed
    int n = sc.nextInt();
    
    // Initialize an ArrayList to store the integers
    ArrayList<Integer> a = new ArrayList<>();
    
    // If there is only one integer, print it and exit
    if (n == 1) {
        System.out.println(sc.nextInt());
        System.exit(0);
    }
    
    // Read n integers from input and add them to the ArrayList
    for (int i = 0; i < n; i++) {
        a.add(sc.nextInt());
    }
    
    // Sort the ArrayList in ascending order
    Collections.sort(a);
    
    // If the largest number is 0, print 0 and exit
    if (a.get(a.size() - 1) == 0) {
        System.out.println(0);
        System.exit(0);
    }
    
    // Initialize the answer variable
    int ans = 0;
    
    // Loop until the ArrayList is reduced to one element
    while (true) {
        // If only one element remains, set it as the answer and break the loop
        if (a.size() == 1) {
            ans = a.get(0);
            break;
        }
        // Call the function to process the ArrayList and update it
        a = func(a);
    }
    
    // Print the final answer
    System.out.println(ans);
}

// Function to process the ArrayList and return a modified version
ArrayList<Integer> func(ArrayList<Integer> A) {
    // Create a copy of the input ArrayList
    ArrayList<Integer> a = A;
    
    // Initialize a variable to store the minimum value
    int min = 0;
    
    // Iterate through the ArrayList
    for (int i = 0; i < a.size(); i++) {
        // If the current element is 0, remove it from the list
        if (a.get(i) == 0) {
            a.remove(i);
            i--; // Adjust index after removal
        } else {
            // If min is not zero, update the current element
            if (min != 0) {
                a.set(i, a.get(i) % min);
                // If the updated element is 1, print 1 and exit
                if (a.get(i) == 1) {
                    System.out.println(1);
                    System.exit(0);
                }
            } else {
                // Set min to the current element if min is still zero
                min = a.get(i);
            }
        }
    }
    
    // Sort the modified ArrayList before returning
    Collections.sort(a);
    return a;
}

