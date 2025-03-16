package main

import "fmt"

func binPrint(x int, bits int){
  for i:=bits-1; i>=0; i--{
    fmt.Printf("%d", x&(1<<i)>0)
  }
  fmt.Println()
}
func main(){
  var a,b uint32
  fmt.Scanf("%d %d", &a, &b)

  binPrint(a&b, 32)
  binPrint(a|b, 32)
  binPrint(a^b, 32)
}

