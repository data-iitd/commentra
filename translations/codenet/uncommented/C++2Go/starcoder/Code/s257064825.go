package main
import (
	"fmt"
	"math"
	"strings"
)
func main() {
	var str string
	fmt.Scanf("%s", &str)
	sum := 0
	for _, x := range str {
		sum += int(x - '0')
	}
	if sum%9 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

