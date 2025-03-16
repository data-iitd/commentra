#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

int main() { 
    // Create a Scanner object to read input from the console
    int n; 
    scanf("%d", &n); 
    
    // Read the number of integers to process
    // Initialize a TreeMap to store integers and their counts
    int num; 
    int key; 
    int val; 
    int ans = 0; 
    while (n-- > 0) { 
        // Read the next integer
        scanf("%d", &num); 
        
        // Check if there is no lower key in the map
        if (key == NULL) { 
            // If no lower key exists, increment the count for the current number
            val = map.getOrDefault(num, 0); 
            map.put(num, ++val); 
        } else { 
            // If there is a lower key, get that key and its count
            key = map.lowerKey(num); 
            val = map.get(key); 
            
            // If the count of the lower key is 1, remove it from the map
            if (val == 1) { 
                map.remove(key); 
            } else { 
                // Otherwise, decrement the count of the lower key
                map.put(key, --val); 
            }
            
            // Increment the count for the current number
            val = map.getOrDefault(num, 0); 
            map.put(num, ++val); 
        } 
    } 
    
    // Sum up all the counts in the map
    for (key : map.keySet()) { 
        val = map.get(key); 
        ans += val; 
    } 
    
    // Print the final answer
    printf("%d\n", ans); 
    return 0; 
} 

