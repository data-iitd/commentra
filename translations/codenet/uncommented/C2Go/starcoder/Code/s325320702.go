package main
import "fmt"
import "os"
import "strconv"
import "strings"
import "sort"
import "math"
import "unicode"
import "unicode/utf8"
import "bytes"
import "io/ioutil"
import "bufio"
import "math/rand"
import "time"
import "container/heap"
import "sync"
import "sync/atomic"
import "unsafe"
import "reflect"
import "fmt"
import "os"
import "strconv"
import "strings"
import "sort"
import "math"
import "unicode"
import "unicode/utf8"
import "bytes"
import "io/ioutil"
import "bufio"
import "math/rand"
import "time"
import "container/heap"
import "sync"
import "sync/atomic"
import "unsafe"
import "reflect"

func main() {
    var l,r,d int
    var ans int
    fmt.Scanf("%d",&l)
    fmt.Scanf("%d",&r)
    fmt.Scanf("%d",&d)
    for i:=l;i<=r;i++{
        if i%d==0{
            ans++
        }
    }
    fmt.Printf("%d\n",ans)
}

