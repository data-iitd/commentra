package main
import (
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)
func value() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}
func values() (int, int) {
	var a, b int
	fmt.Scan(&a, &b)
	return a, b
}
func inlst() []int {
	var a []int
	for _, i := range strings.Split(fmt.Scanln(), " ") {
		a = append(a, int(i))
	}
	return a
}
func inlsts() []int {
	var a []int
	for _, i := range strings.Split(fmt.Scanln(), " ") {
		a = append(a, int(i))
	}
	return a
}
func inp() int {
	var a int
	fmt.Scan(&a)
	return a
}
func inps() int {
	var a int
	fmt.Scan(&a)
	return a
}
func instr() string {
	var a string
	fmt.Scan(&a)
	return a
}
func stlst() []string {
	var a []string
	for _, i := range strings.Split(fmt.Scanln(), " ") {
		a = append(a, i)
	}
	return a
}
func help(a, b int, l []int) bool {
	tot := [][12]int{}
	for i := 0; i < b; i++ {
		tot = append(tot, l[i*a:i*a+a])
	}
	for _, i := range tot {
		if sum(i) == b {
			return true
		}
	}
	return false
}
func sum(a [12]int) int {
	var tot int
	for _, i := range a {
		tot += i
	}
	return tot
}
func solve() {
	tot := [][2]int{}
	x := instr()
	s := [12]int{}
	for i, v := range x {
		if v == 'O' {
			s[i] = 0
		} else {
			s[i] = 1
		}
	}
	for i := 1; i < 13; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, [2]int{12 / i, i})
			}
		}
	}
	fmt.Println(len(tot))
	for _, a := range tot {
		fmt.Printf("%dx%d ", a[0], a[1])
	}
	fmt.Println()
}
func main() {
	for i := 0; i < inp(); i++ {
		solve()
	}
}



Translate the above Go code to C++ and end with comment "