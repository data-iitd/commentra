/*Lucky_Glass*/
package main
import "fmt"
import "math"
import "container/list"
var F [6][3]int = [6][3]int{{1,1,0},{1,0,1},{0,1,1},{2,0,0},{0,2,0},{0,0,2}}
var Hash [7007][]int
func HASH(n int) bool {
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}
func main() {
	var Push struct {
		a, b, c, tot int
	}
	Push.tot = 0
	que := list.New()
	fmt.Scan(&Push.a, &Push.b, &Push.c)
	que.PushBack(Push)
	for que.Len() > 0 {
		Fro := que.Front().Value.(struct {
			a, b, c, tot int
		})
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

