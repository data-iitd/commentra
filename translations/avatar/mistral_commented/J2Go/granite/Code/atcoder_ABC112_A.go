

package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
  "strings"
)

func main() {
  var n int // Declaring an integer variable 'n' to store the number of test cases

  // Reading the first line of input which contains the number of test cases
  fmt.Scanln ( &n )

  // Checking if the number of test cases is equal to 1
  if n == 1 {
    // If yes, printing "Hello World" as output
    fmt.Println ( "Hello World" )
  } else {
    // If not, reading the next two lines of input which contain two integers
    reader := bufio.NewReader ( os.Stdin )
    strs, _ := reader.ReadString ( '\n' ) // Reading the first line of input
    num1, _ := strconv.Atoi ( strings.TrimSpace ( strs ) ) // Converting the first line of input to an integer and storing it in a variable 'num1'
    strs, _ = reader.ReadString ( '\n' ) // Reading the second line of input
    num2, _ := strconv.Atoi ( strings.TrimSpace ( strs ) ) // Converting the second line of input to an integer and storing it in a variable 'num2'

    // Printing the sum of the two integers as output
    fmt.Println ( num1 + num2 )
  }
}

