import (
    "fmt"
    "io/ioutil"
    "os"
    "strings"
)

func main() {
    var s string
    if len(os.Args) > 1 {
        s = os.Args[1]
    } else {
        s = "123456789"
    }
    fmt.Println(s)
    pmin := 1000
    mmin := 0
    s = "0" + s
    for _, c := range s[:len(s)-1] {
        v := int(c) - '0'
        npmin := min(pmin+10-(v+1), mmin+10-v)
        nmmin := min(pmin+v+1, mmin+v)
        pmin = npmin
        mmin = nmmin
    }
    fmt.Println(min(pmin, mmin))
}

