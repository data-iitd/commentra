package main
import "fmt"
import "math"
func main() {
	x := 360
	fmt.Println(360 / int(math.Gcd(float64(360), float64(x))))
}
