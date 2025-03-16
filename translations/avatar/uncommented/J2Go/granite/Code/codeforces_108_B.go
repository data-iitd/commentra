
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements:")
	n, _ := reader.ReadString('\n')
	n, _ = reader.ReadString('\n')
	a := make([]int, 0)
	for i := 0; i < len(n); i++ {
		if n[i] =='' {
			continue
		}
		num := 0
		for n[i]!='' {
			num = num*10 + int(n[i]-'0')
			i++
		}
		a = append(a, num)
	}
	sort.Ints(a)
	for i := 0; i < len(a)-1; i++ {
		if a[i+1] < a[i]*2 && a[i]!= a[i+1] {
			fmt.Println("YES")
			return
		}
	}
	fmt.Println("NO")
}
