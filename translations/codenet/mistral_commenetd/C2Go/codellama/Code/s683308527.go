
package main

import "fmt"
import "strings"

func main() {
  var n int // Declare an integer variable 'n' to store the number of strings to be processed
  var s string // Declare a string variable 's' to store each string read from the input
  var c int // Declare an integer variable 'c' to traverse the string 's'

  fmt.Scanf("%d%*c",&n) // Read an integer 'n' from the standard input and ignore the newline character

  for n > 0 { // Start of the for loop that processes each string
    fmt.Scanf("%s",&s) // Read a string of maximum length 1000 from the standard input into the string variable 's'

    for c = strings.Index(s,"Hoshino"); c != -1; c = strings.Index(s,"Hoshino") { // Start of the inner for loop that replaces the substring "Hoshino" with "aana"
      s = s[:c+6] + "a" + s[c+7:] // Replace the 7th character of the substring "Hoshino" with 'a'
      s = s[:c+8] + "a" + s[c+9:] // Replace the 8th character of the substring "Hoshino" with 'a'
      s = s[:c+9] + "a" + s[c+10:] // Replace the 9th character of the substring "Hoshino" with 'a'
      s = s[:c+10] + "n" + s[c+11:] // Replace the 10th character of the substring "Hoshino" with 'n' to get the substring "aana"
    }

    fmt.Println(s) // Print the modified string to the standard output

    n-- // Decrement the number of strings to be processed
  }
}

