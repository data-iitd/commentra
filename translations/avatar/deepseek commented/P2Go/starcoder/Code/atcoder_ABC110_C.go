
package main

import (
	"fmt"
	"sort"
)

func run(s, t string) string {
	ss := sort.IntSlice(make([]int, len(s)))
	for i, v := range s {
		ss[i] = int(v)
	}
	ss.Sort()
	tt := sort.IntSlice(make([]int, len(t)))
	for i, v := range t {
		tt[i] = int(v)
	}
	tt.Sort()
	if ss.Equal(tt) {
		return "Yes"
	}
	return "No"
}

func main() {
	var s, t string
	fmt.Scanf("%s\n%s", &s, &t)
	fmt.Println(run(s, t))
}

