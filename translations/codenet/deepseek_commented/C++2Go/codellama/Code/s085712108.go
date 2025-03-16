/*Lucky_Glass*/
package main
import "fmt"
import "math"
import "container/list"

// Define a structure QUEUE to store the values of a, b, c, and the total number of operations.
type QUEUE struct {
	a,b,c,tot int
}

// Define a transformation matrix F with six possible transformations.
var F = [][]int{{1,1,0},{1,0,1},{0,1,1},{2,0,0},{0,2,0},{0,0,2}}

// Define a hash table as an array of lists to store unique states.
var Hash [7007]list.List

// Function to check if a state has been visited before.
func HASH(n int) bool {
	for e := Hash[n%7007].Front(); e != nil; e = e.Next() {
		if n == e.Value.(int) {
			return false
		}
	}
	Hash[n%7007].PushBack(n)
	return true
}

// Main function to execute the program.
func main() {
	var Push QUEUE
	Push.tot = 0
	que := list.New()
	fmt.Scan(&Push.a,&Push.b,&Push.c)
	que.PushBack(Push)
	for que.Len() > 0 {
		Fro := que.Front().Value.(QUEUE)
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Println(Fro.tot)
			return
		}
		for i := 0; i < 6; i++ {
			Push = Fro
			Push.tot++
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]
			n := Push.a*10000 + Push.b*100 + Push.c
			if !HASH(n) {
				continue
			}
			que.PushBack(Push)
		}
		que.Remove(que.Front())
	}
}

