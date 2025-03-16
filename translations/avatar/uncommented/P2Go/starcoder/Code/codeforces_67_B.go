package main
import "fmt"
import "os"
import "bufio"
import "strings"

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	n, _ := reader.ReadString('\n')
	n = strings.TrimSpace(n)
	n_int, _ := strconv.Atoi(n)
	fmt.Println("Enter the elements of the array")
	M := make([]int, n_int)
	for i := 0; i < n_int; i++ {
		M[i], _ = reader.ReadString('\n')
		M[i] = strings.TrimSpace(M[i])
		M[i], _ = strconv.Atoi(M[i])
	}
	fmt.Println("Enter the value of k")
	k, _ := reader.ReadString('\n')
	k = strings.TrimSpace(k)
	k_int, _ := strconv.Atoi(k)
	m := 0
	for j := 0; j < n_int; j++ {
		for p := 0; p < n_int; p++ {
			if M[p] == 0 {
				fmt.Println(p + 1)
				break
			}
		}
		for l := p + 1 - k_int; l < p; l++ {
			M[l] -= 1
		}
		M[p] -= 1
	}
}

