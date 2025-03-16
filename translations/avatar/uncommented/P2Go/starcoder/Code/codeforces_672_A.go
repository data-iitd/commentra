package main
import "fmt"
func main() {
	li := []int{}
	ind := 0
	for i := 1; i < 371; i++ {
		temp := []int{}
		p, q := i, i
		count := 0
		for p!= 0 {
			p /= 10
			count++
		}
		if count == 1 {
			li = append(li, i)
		}
		if count == 2 {
			for q!= 0 {
				x := q % 10
				q /= 10
				temp = append(temp, x)
			}
			li = append(li, temp...)
		}
		if count == 3 {
			for q!= 0 {
				x := q % 10
				q /= 10
				temp = append(temp, x)
			}
			li = append(li, temp...)
		}
	}
	li = li[:len(li)-2]
	n := int(input(""))
	fmt.Println(li[n-1])
}
