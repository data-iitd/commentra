package main
import "fmt"
func main() {
	s, l := "123456789", 2019
	m, a, r := []int{1}, 0, 0
	for i, e := range s[:len(s)-1] {
		a += int(e) * int(math.Pow(10, float64(i)))
		r += m[a%l]
		m[a%l]++
	}
	fmt.Println(r)
}
