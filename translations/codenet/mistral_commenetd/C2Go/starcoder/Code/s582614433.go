<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
	"fmt"
	"sort"
	"bufio"
	"os"
	"strconv"
	"strings"
)
type edge struct{
	p int
	i int
	s string
}
<<<<<<< HEAD
func main() {
=======
func main(){
>>>>>>> 98c87cb78a (data updated)
	var n int
	fmt.Scanf("%d",&n)
	data := make([]edge,n)
	for i:=0;i<n;i++{
		fmt.Scanf("%s %d", &data[i].s, &data[i].p)
		data[i].i = i
	}
	sort.Slice(data, func(i, j int) bool {
		if data[i].s < data[j].s {
			return true
		}
		if data[i].s > data[j].s {
			return false
		}
		return data[i].p < data[j].p
	})
	for i:=0;i<n;i++{
		fmt.Printf("%d\n",data[i].i+1)
	}
}

