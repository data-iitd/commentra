package main
import "fmt"
func main() {
	var str string
	fmt.Scan(&str)
	sum := 0
	for _, x := range str {
		sum += int(x - 48)
	}
	if sum%9 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

