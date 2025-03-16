package main

import "fmt"

func main() {
   // Declare two integer variables to store the number of sheep and wolves
   var sheep, wolf int

   // Read two integers from the standard input and store them in the sheep and wolf variables
   fmt.Scan(&sheep, &wolf)

   // Check if the number of wolves is greater than or equal to the number of sheep
   if wolf >= sheep {
      // If the condition is true, print the message "unsafe" to the standard output
      fmt.Println("unsafe")
   } else {
      // If the condition is false, print the message "safe" to the standard output
      fmt.Println("safe")
   }
}

