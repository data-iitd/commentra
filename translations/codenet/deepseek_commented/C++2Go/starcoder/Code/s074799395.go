<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import "fmt"
func main() {
  var B,OUT string
  fmt.Scanf("%s\n", &B)
  if B == "A" {
    OUT = "T"
  } else if B == "T" {
    OUT = "A"
  } else if B == "C" {
    OUT = "G"
  } else {
    OUT = "C"
  }
  fmt.Println(OUT)
}
