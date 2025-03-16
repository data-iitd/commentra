package main
import "fmt"
import "sort"
import "math"
import "os"
import "strconv"
import "strings"
import "bufio"
import "unicode"
import "unicode/utf8"
import "bytes"
import "io"
import "io/ioutil"
import "math/rand"
import "time"
import "container/heap"
import "sync"
import "sync/atomic"
import "unsafe"

func main() {
	var n int
	fmt.Scanf("%d\n", &n)
	data := make([]struct {
		s string
		p int
		i int
	}, n)
	for i := 0; i < n; i++ {
		fmt.Scanf(" %s%d\n", &data[i].s, &data[i].p)
		data[i].i = i
	}
	sort.Slice(data, func(i, j int) bool {
		if data[i].s!= data[j].s {
			return data[i].s < data[j].s
		}
		return data[i].p < data[j].p
	})
	for i := 0; i < n; i++ {
		fmt.Printf("%d\n", data[i].i+1)
	}
}

