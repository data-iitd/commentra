
package main

import (
  "bufio"
  "fmt"
  "os"
  "strconv"
)

func main() {
  // Open the standard input and create a scanner to read from it
  scanner := bufio.NewScanner(os.Stdin)
  
  // Declare integer variables to store input values
  var h, w, hh, ww int
  
  // Read values from the standard input and store them in the variables
  scanner.Scan()
  h, _ = strconv.Atoi(scanner.Text())
  scanner.Scan()
  w, _ = strconv.Atoi(scanner.Text())
  scanner.Scan()
  hh, _ = strconv.Atoi(scanner.Text())
  scanner.Scan()
  ww, _ = strconv.Atoi(scanner.Text())
  
  // Perform arithmetic operation to calculate the area of a rectangle
  // Output the result to the standard output
  fmt.Println((h - hh) * (w - ww))
  
  // Indicate that the program ended successfully
}

