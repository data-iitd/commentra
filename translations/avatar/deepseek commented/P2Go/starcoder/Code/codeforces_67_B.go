package main
import "fmt"
import "os"
import "strconv"
import "strings"

func main() {
	var n, k int
	var M []int
	var m int
	n, k = get_input()
	M = get_input_list()
	m = 0
	for j := 0; j < n; j++ {
		for p := 0; p < n; p++ {
			if M[p] == 0 {
				fmt.Println(p+1)
				break
			}
		}
		for l := p + 1 - k; l < p; l++ {
			M[l] -= 1
		}
		M[p] -= 1
	}
}

func get_input() (int, int) {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	return n, k
}

func get_input_list() []int {
	var M []int
	var i int
	for i = 0; i < 100; i++ {
		var s string
		fmt.Scanf("%s", &s)
		if s == "