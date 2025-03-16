
package main

import "fmt"

func main() {
   var sheep int
   var wolf int

   fmt.Scanf("%d %d", &sheep, &wolf)

   if wolf >= sheep {
      fmt.Println("unsafe")
   } else {
      fmt.Println("safe")
   }
}

