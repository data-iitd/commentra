package main
import (
"fmt"
"os"
"strconv"
"strings"
)
func main() {
var inp int
var lista []int
var i int
inp, _ = strconv.Atoi(os.Args[1])
lista = strings.Split(os.Args[2], " ")
for i = 0; i < len(lista); i++ {
if i == 0 {
fmt.Printf("%d %d\n", lista[i+1]-lista[i], lista[len(lista)-1]-lista[i])
continue
}
if i == len(lista)-1 {
fmt.Printf("%d %d\n", lista[len(lista)-1]-lista[len(lista)-2], lista[len(lista)-1]-lista[0])
continue
}
if lista[i]-lista[i-1] > lista[i+1]-lista[i] {
fmt.Printf("%d ", lista[i+1]-lista[i])
} else {
fmt.Printf("%d ", lista[i]-lista[i-1])
}
if lista[len(lista)-1]-lista[i] > lista[i]-lista[0] {
fmt.Printf("%d\n", lista[len(lista)-1]-lista[i])
} else {
fmt.Printf("%d\n", lista[i]-lista[0])
}
}
}
