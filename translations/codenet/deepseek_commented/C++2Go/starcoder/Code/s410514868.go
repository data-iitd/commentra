<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Reading the input values for n and k, and the string s
    n, _ := strconv.Atoi(os.Args[1])
    k, _ := strconv.Atoi(os.Args[2])
    s := strings.Split(os.Args[3], "")
    
    // Initializing L with the first character of s, and ans, cnt to zero
    L := s[0]
    cnt := 0
    
    // Loop through the string starting from the second character
    for i := 1; i < n; i++ {
        // If the current character is the same as L, increment cnt
        if L == s[i] {
            cnt++
        } else {
            // Update L to the new character, add cnt to ans, increment ans2, and reset cnt
            L = s[i]
            ans += cnt
            ans2++
            cnt = 0
        }
    }
    
    // Add the final count to ans and increment ans2
    ans += cnt
    ans2++
    
    // Calculate the output as ans + min(2*k, ans2-1) and print it
    fmt.Println(ans + int(min(float64(2*k), float64(ans2-1))))
}

