package main
import "fmt"
import "os"
import "strconv"
import "strings"

func main() {
	var y int
	var arr []int
	y, _ = strconv.Atoi(os.Args[1])
	arr = make([]int, 0)
	for _, v := range strings.Fields(os.Args[2]) {
		i, _ := strconv.Atoi(v)
		arr = append(arr, i)
	}
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr); j++ {
			if i == j {
				continue
			}
			for k := 0; k < len(arr); k++ {
				if arr[k]!= arr[j] && arr[k]!= arr[i] && arr[k] == arr[i] + arr[j] {
					fmt.Printf("%d %d %d\n", k+1, j+1, i+1)
					os.Exit(0)
				}
			}
		}
	}
	fmt.Printf("%d\n", -1)
}

