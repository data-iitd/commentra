package main
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the elements of the array")
	arr := strings.Split(reader.ReadString('\n'), " ")
	w := make(map[int]int)
	for i := 0; i < n; i++ {
		w[i] = 1
	}
	for i := 0; i < n; i++ {
		w[i], _ = strconv.Atoi(arr[i])
	}
	c := 0
	for i := 0; i < n; i++ {
		if w[i] == 0 {
			c += w[i] * (w[i] - 1)
		} else {
			if -w[i] in w {
				c += w[i] * w[-w[i]]
			}
		}
	}
	fmt.Println(c / 2)
}

