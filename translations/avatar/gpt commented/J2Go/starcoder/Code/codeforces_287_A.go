package main

import "fmt"
import "bufio"
import "os"

func main() {
    // Creating a Scanner object to read input from the user
    sc := bufio.NewScanner(os.Stdin)
    
    // Initializing an array to hold 4 strings
    str := make([]string, 4)
    i := -1 // Index variable for the first loop
    
    // Loop to read 4 strings from user input
    for i!= 3 {
        i = i + 1 // Increment index
        sc.Scan() // Read a string and store it in the array
        str[i] = sc.Text()
    }
    
    u := -1 // Index variable for the outer loop
    i := -1 // Reset index variable for the inner loop
    yes := 0 // Flag to indicate if a condition is met
    
    // Outer loop to iterate through the first 3 strings
    for u!= 2 {
        u = u + 1 // Increment outer index
        i = -1 // Reset inner index
        
        // Inner loop to check conditions on characters of the strings
        for i!= 2 {
            i = i + 1 // Increment inner index
            
            // Check if the characters in the strings meet the specified conditions
            if ((str[u][i] == str[u][i + 1] && 
                (str[u + 1][i] == str[u][i] || 
                 str[u + 1][i + 1] == str[u][i])) || 
                (str[u + 1][i] == str[u + 1][i + 1] && 
                (str[u][i] == str[u + 1][i] || 
                 str[u][i + 1] == str[u + 1][i]))) {
                
                yes = 1 // Set flag to indicate a match was found
                fmt.Println("YES") // Output "YES"
                break // Exit the inner loop
            }
        }
        
        // If a match was found, exit the outer loop
        if yes == 1 {
            break
        }
    }
    
    // If no matches were found, output "NO"
    if yes == 0 {
        fmt.Println("NO")
    }
}

