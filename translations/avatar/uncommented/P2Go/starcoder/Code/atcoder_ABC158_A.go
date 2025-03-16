package main
import (
"fmt"
"os"
)
func main() {
s := os.Stdin
result := "Yes" if "A" in s && "B" in s else "No"
fmt.Println(result)
}
