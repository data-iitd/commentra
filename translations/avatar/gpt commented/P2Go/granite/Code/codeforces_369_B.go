
func getNums(num, t int) []int {
    // Generate a list of numbers based on the distribution of t across num parts
    ans := make([]int, num)
    for i := 0; i < num; i++ {
        if i < t%num {
            ans[i] = t / num + 1
        } else {
            ans[i] = t / num
        }
    }
    return ans
}

func main() {
    // Read input values for n, k, l, r, sa, and sk
    var n, k, l, r, sa, sk int
    fmt.Scan(&n, &k, &l, &r, &sa, &sk)

    // Calculate the distribution of sk among k parts and sa - sk among the remaining n - k parts
    ans := getNums(k, sk)
    for _, v := range getNums(n-k, sa-sk) {
        ans = append(ans, v)
    }

    // Print the result as a space-separated string
    fmt.Println(strings.Join(func() []string {
        s := make([]string, len(ans))
        for i, v := range ans {
            s[i] = strconv.Itoa(v)
        }
        return s
    }(), " "))
}

