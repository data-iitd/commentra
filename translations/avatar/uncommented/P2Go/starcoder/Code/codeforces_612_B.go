n := 0
a := []int{}
b := []int{}

func main() {
    fmt.Scanf("%d", &n)
    a = make([]int, n)
    b = make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }
    for i := 0; i < n; i++ {
        b[a[i]-1] = i
    }
    res := 0
    for i := 1; i < n; i++ {
        res += abs(b[i] - b[i-1])
    }
    fmt.Printf("%d", res)
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

