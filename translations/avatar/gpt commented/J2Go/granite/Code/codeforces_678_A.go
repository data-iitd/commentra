
package main

import "fmt"
import "bufio"
import "os"

func main() {
    // Create a new scanner to read input from the user
    scanner := bufio.NewScanner(os.Stdin)
    
    // Read two integers from the user: n and k
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    k, _ := strconv.Atoi(scanner.Text())
    
    // Increment n by 1
    n++
    
    // Initialize a variable z to store the adjustment needed to make n divisible by k
    z := 0
    
    // Check if n is not divisible by k
    if n % k!= 0 {
        // Calculate the adjustment needed to make n divisible by k
        z = k - n % k
    }
    
    // Output the final result, which is n plus the adjustment z
    fmt.Println(n + z)
}

