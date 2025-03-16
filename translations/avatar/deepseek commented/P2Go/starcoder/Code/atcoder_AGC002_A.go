package main
import (
"fmt"
"os"
"strconv"
)
func main() {
a, b := 0, 0
fmt.Sscanf(os.Stdin.ReadString( ), "%d %d", &a, &b)
if a > 0 {
fmt.Println("Positive")
} else if a <= 0 && b >= 0 {
fmt.Println("Zero")
} else {
if (a + b) % 2 == 0 {
fmt.Println("Negative")
} else {
fmt.Println("Positive")
}
}
}
