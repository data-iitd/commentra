<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    // Step 1: Reading the Input
    s := strings.TrimSpace(string(os.Stdin.Read(1024)))

    // Step 2: Calculating the Size of the String
    n := len(s)

    // Step 3: Initializing an Array to Count Character Frequencies
    v := make([]int, 26)

    // Step 4: Counting Character Frequencies
    for i := 0; i < n; i++ {
        v[int(s[i]-'a')]++
    }

    // Step 5: Determining the Result
    ans := "Yes"
    for i := 0; i < 26; i++ {
        if v[i]%2!= 0 {
            ans = "No"
            break
        }
    }

    // Step 6: Outputting the Result
    fmt.Println(ans)
}

