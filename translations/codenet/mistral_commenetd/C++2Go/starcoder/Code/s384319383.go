
<<<<<<< HEAD

import (
	"fmt"
	"math"
=======
package main

import (
	"bufio"
	"fmt"
>>>>>>> 98c87cb78a (data updated)
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n int
<<<<<<< HEAD
	fmt.Scanf("%d", &n)
	cnt := make([]int, 26)
	s := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%c", &s[i])
=======
	fmt.Scanf("%d\n", &n)
	cnt := make([]int, 26)
	s := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%c\n", &s[i])
>>>>>>> 98c87cb78a (data updated)
		cnt[s[i]-'a']++
	}
	ans := 1
	for i := 0; i < 26; i++ {
		ans *= cnt[i]
	}
	ans--
	fmt.Println(ans)
}

