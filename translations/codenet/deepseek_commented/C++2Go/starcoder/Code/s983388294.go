<<<<<<< HEAD

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	curr := 0
	for i := 0; i < n; i++ {
		if a[i] == curr+1 {
			curr++
		}
	}
	if curr > 0 {
		fmt.Printf("%d\n", n-curr)
	} else {
		fmt.Printf("-1\n")
	}
=======
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
    a := make([]int, n)
    fmt.Println("Enter the elements of the array")
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(reader.ReadString('\n'))
    }
    curr := 0
    for i := 0; i < n; i++ {
        if a[i] == curr+1 {
            curr++
        }
    }
    if curr > 0 {
        fmt.Println(n - curr)
    } else {
        fmt.Println("-1")
    }
>>>>>>> 98c87cb78a (data updated)
}

