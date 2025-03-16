package main
import "fmt"
import "os"
import "bufio"
import "strings"

func main() {
    reader := bufio.NewReader(os.Stdin)
    soz := readLine(reader)
    a := make([]int, len(soz)+1)
    for i := 1; i < len(soz); i++ {
        a[i] = a[i-1]
        if soz[i-1] == soz[i] {
            a[i] += 1
        }
    }
    n, err := strconv.Atoi(readLine(reader))
    check(err)
    arr := make([]int, n)
    for i := 0; i < n; i++ {
        m, l, err := fmt.Sscanf(readLine(reader), "%d %d", &arr[i], &arr[i])
        check(err)
    }
    for i := 0; i < n; i++ {
        fmt.Println(a[arr[i]-1]-a[arr[i]-2])
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }
    return strings.TrimRight(string(str), "\r\n")
}

func check(err error) {
    if err!= nil {
        panic(err)
    }
}

