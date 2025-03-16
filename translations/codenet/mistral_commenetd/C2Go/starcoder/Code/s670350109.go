
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Read the first string from the user
    fmt.Print("Enter the first string: ")
    reader := bufio.NewReader(os.Stdin)
    str1, _ := reader.ReadString('\n')
    str1 = strings.TrimSpace(str1)
    fmt.Printf("First string: %s\n", str1)

    // Read the second string from the user
    fmt.Print("Enter the second string: ")
    str2, _ := reader.ReadString('\n')
    str2 = strings.TrimSpace(str2)
    fmt.Printf("Second string: %s\n", str2)

    // Check if the lengths of the two strings are equal
    if len(str1)!= len(str2) {
        fmt.Println("NO")
        return
    }

    // Reverse the first string
<<<<<<< HEAD
    str1 = reverse(str1)
=======
    str1 = Reverse(str1)
>>>>>>> 98c87cb78a (data updated)
    fmt.Printf("Reversed first string: %s\n", str1)

    // Compare the reversed first string with the second string
    t := 0
    for i := 0; i < len(str1); i++ {
        if str1[i] == str2[i] {
            t++
        }
    }

    // Check if all characters are equal and print the result accordingly
    if len(str2) == t {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

<<<<<<< HEAD
func reverse(s string) string {
=======
// Reverse returns the reverse of the given string
func Reverse(s string) string {
>>>>>>> 98c87cb78a (data updated)
    r := []rune(s)
    for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }
    return string(r)
}

