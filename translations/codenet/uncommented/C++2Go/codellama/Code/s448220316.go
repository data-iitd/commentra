   package main
     
    import (
    	"bufio"
    	"fmt"
    	"os"
    )
     
    var (
    	n, m, l, r, vi, fa [100005]int
    	v                 [200005]int
    )
     
    func get(x int) int {
    	if x == fa[x] {
    		return x
    	}
    	f := get(fa[x])
    	v[x] += v[fa[x]]
    	return fa[x] = f
    }
     
    func main() {
    	n = read()
    	m = read()
    	for i := 1; i <= n; i++ {
    		fa[i] = i
    	}
    	for i := 1; i <= m; i++ {
    		l = read()
    		r = read()
    		vi = read()
    		li := get(l)
    		ri := get(r)
    		if li != ri {
    			v[ri] = vi - v[r] + v[l]
    			fa[ri] = li
    		} else {
    			if v[r]-v[l] != vi {
    				fmt.Println("No")
    				return
    			}
    		}
    	}
    	fmt.Println("Yes")
    }
     
    func read() int {
    	var k, f int
    	ch := ' '
    	for ch < '0' || ch > '9' {
    		if ch == '-' {
    			f = -1
    		}
    		ch = readByte()
    	}
    	for ch >= '0' && ch <= '9' {
    		k = k*10 + int(ch-'0')
    		ch = readByte()
    	}
    	return k * f
    }
     
    func readByte() byte {
    	ch, err := reader.ReadByte()
    	if err != nil {
    		panic(err)
    	}
    	return ch
    }
     
    var reader *bufio.Reader
     
    func init() {
    	reader = bufio.NewReader(os.Stdin)
    }
    