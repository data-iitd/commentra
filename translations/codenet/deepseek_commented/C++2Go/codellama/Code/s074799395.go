package main
import "fmt"
func main(){
  var B byte
  fmt.Scan(&B)
  var OUT byte
  if B == 'A' {
    OUT = 'T'
  } else if B == 'T' {
    OUT = 'A'
  } else if B == 'C' {
    OUT = 'G'
  } else {
    OUT = 'C'
  }
  fmt.Println(OUT)
}
