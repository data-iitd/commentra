<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a, b, x, w int
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		a, b = get_input(scanner.Text())
		x = a + b
		w = 0
		for x > 0 {
			w++
			x /= 10
		}
		fmt.Println(w)
	}
}

func get_input(input string) (int, int) {
<<<<<<< HEAD
	input_array := strings.Split(input, " ")
	a, _ := strconv.Atoi(input_array[0])
	b, _ := strconv.Atoi(input_array[1])
=======
	input_list := strings.Split(input, " ")
	a, _ := strconv.Atoi(input_list[0])
	b, _ := strconv.Atoi(input_list[1])
>>>>>>> 98c87cb78a (data updated)
	return a, b
}

