<<<<<<< HEAD

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements and the size of the subarray")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	input_arr := strings.Split(input, ",")
	n, _ := strconv.Atoi(input_arr[0])
	k, _ := strconv.Atoi(input_arr[1])
	l := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		fmt.Println("Enter the element at index", i)
		input, _ := reader.ReadString('\n')
		input = strings.Replace(input, "\n", "", -1)
		l[i], _ = strconv.Atoi(input)
	}
	sort.Ints(l)
	ans := 0
	for i := 0; i < k; i++ {
		ans += l[n-1-i]
	}
	fmt.Println(ans)
=======
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of elements and the size of the subarray")
    n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    fmt.Println("Enter the elements of the array")
    l := make([]int, n)
    for i := 0; i < n; i++ {
        l[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
    }
    sort.Ints(l)
    ans := 0
    for i := 0; i < k; i++ {
        ans += l[n-1-i]
    }
    fmt.Println(ans)
>>>>>>> 98c87cb78a (data updated)
}

