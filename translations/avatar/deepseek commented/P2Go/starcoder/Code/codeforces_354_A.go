n, L, R, QL, QR := 0, 0, 0, 0, 0
var sum_el []int
var answer int

func main() {
    fmt.Scanf("%d %d %d %d %d", &n, &L, &R, &QL, &QR)
    W := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &W[i])
    }

    sum_el = make([]int, n + 1)
    sum_el[0] = 0
    for i := 1; i <= n; i++ {
        sum_el[i] = W[i - 1] + sum_el[i - 1]
    }

    answer = QR * (n - 1) + sum_el[n] * R

    for i := 1; i <= n; i++ {
        energy := L * sum_el[i] + R * (sum_el[n] - sum_el[i])
        if i > (n - i) {
            energy += (i - (n - i) - 1) * QL
        } else if (n - i) > i {
            energy += (n - i - 1) * QR
        }
        if energy < answer {
            answer = energy
        }
    }

    fmt.Println(answer)
}

