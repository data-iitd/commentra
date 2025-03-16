package main
import "fmt"
import "math"
import "sort"
import "strings"
import "strconv"
import "os"
import "bufio"
import "sort"
import "container/heap"
import "math/rand"
import "encoding/binary"
import "encoding/hex"
import "encoding/json"
import "encoding/xml"
import "net/http"
import "net/url"
import "io/ioutil"
import "log"
import "regexp"
import "runtime"
import "time"
import "sync"
import "sync/atomic"
import "unsafe"
import "errors"
import "flag"
import "fmt"
import "os"
import "reflect"
import "sort"
import "strconv"
import "strings"
import "sync"
import "time"
import "unicode"
import "unicode/utf8"
import "unsafe"

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	vis := make([]int, n+1)
	ci, cb, cc := 0, 0, 0
	g := make([][]int, n+1)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scanf("%d %d", &u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	for i := 1; i <= n; i++ {
		if len(g[i]) == 0 {
			ci++
		} else {
			if dfs(i, 1) {
				cb++
			} else {
				cc++
			}
		}
	}
	fmt.Printf("%d\n", ci*ci+2*ci*(n-ci)+cc*cc+2*cb*cc+2*cb*cb)
}

func dfs(u int, col int) bool {
	stk := make([]int, 0)
	stk = append(stk, u)
	flag := true
	for len(stk) > 0 {
		u := stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		if vis[u]!= 0 {
			flag &= (vis[u] == col)
			continue
		}
		vis[u] = col
		for _, v := range g[u] {
			stk = append(stk, v)
		}
	}
	return flag
}

