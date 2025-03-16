
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Create a scanner to read input
    scanner := bufio.NewScanner(os.Stdin)
    
    // Read the number of strings
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())
    
    // Read each string and store them in a slice
    var ss []string
    for i := 0; i < n; i++ {
        scanner.Scan()
        ss = append(ss, scanner.Text())
    }
    
    // Read the character array to be modified
    scanner.Scan()
    cc := scanner.Text()
    
    // Read the character to be replaced
    scanner.Scan()
    c := scanner.Text()[0]
    
    // Determine the character to replace with
    a := 'a'
    if c == 'a' {
        a = 'b'
    }
    
    // Array to track positions that can be marked as lucky
    lucky := make([]bool, len(cc))
    
    // Loop through each position in the character array
    for j := 0; j < len(cc); j++ {
        for i := 0; i < n; i++ {
            l := len(ss[i])
            // Check if the substring matches and mark lucky positions
            if len(cc)-j >= l && strings.EqualFold(cc[j:j+l], ss[i]) {
                for h := 0; h < l; h++ {
                    lucky[j+h] = true
                }
            }
        }
    }
    
    // Replace characters in the original array based on lucky positions
    for j := 0; j < len(cc); j++ {
        if lucky[j] {
            // Replace with the determined character based on case
            if strings.ToLower(string(cc[j])) == string(c) {
                if cc[j] >= 'A' && cc[j] <= 'Z' {
                    cc = cc[:j] + string(a) + cc[j+1:]
                } else {
                    cc = cc[:j] + string(a) + cc[j+1:]
                }
            } else {
                if cc[j] >= 'A' && cc[j] <= 'Z' {
                    cc = cc[:j] + string(c) + cc[j+1:]
                } else {
                    cc = cc[:j] + string(c) + cc[j+1:]
                }
            }
        }
    }
    
    // Print the modified character array
    fmt.Println(cc)
}
