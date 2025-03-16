package main
import "fmt"
import "math"
import "sort"
import "os"
import "strconv"
import "strings"
import "bufio"
import "io"
import "math/rand"
import "time"
import "unicode"
import "unicode/utf8"
import "bytes"
import "container/heap"
import "encoding/binary"
import "encoding/hex"
import "encoding/json"
import "encoding/xml"
import "net/http"
import "net/url"
import "path/filepath"
import "regexp"
import "strings"
import "sync"
import "sync/atomic"
import "syscall"
import "text/template"
import "text/scanner"
import "text/tabwriter"
import "text/template/parse"
import "unicode"
import "unicode/utf8"
import "unsafe"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	cnt := make([][]int, 10)
	for i := 0; i < 10; i++ {
		cnt[i] = make([]int, 10)
	}
	for i := 1; i <= n; i++ {
		b := i % 10
		a := i
		for a >= 10 {
			a /= 10
		}
		cnt[a][b]++
	}
	ans := 0
	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			ans += cnt[i][j] * cnt[j][i]
		}
	}
	fmt.Printf("%d\n", ans)
}

