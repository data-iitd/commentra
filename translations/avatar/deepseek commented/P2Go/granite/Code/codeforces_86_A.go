

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the lower and upper bounds of the range:")
    text, _ := reader.ReadString('\n')
    text = strings.TrimSpace(text)
    parts := strings.Split(text, " ")
    l, _ := strconv.Atoi(parts[0])
    r, _ := strconv.Atoi(parts[1])
    curr := r
    s := 0
    for curr > 0 {
        s++
        curr /= 10
    }
    first := int(math.Pow(10, float64(s)))
    second := first / 2
    ans := -1
    for _, i := range []int{l, r, first, second} {
        if i >= l && i <= r {
            curr = i
            rev := ""
            for _, k := range fmt.Sprintf("%d", curr) {
                rev += fmt.Sprintf("%d", 9-int(k-'0'))
            }
            product, _ := strconv.Atoi(rev) * curr
            if product > ans {
                ans = product
            }
        }
    }
    fmt.Println(ans)
}
// Read the lower and upper bounds of the range from the user
// Calculate the number of digits in the upper bound
// Calculate the smallest number with s digits and its half
// Iterate over the specified numbers, check if they are within the range,
// reverse the digits, calculate the product, and update ans if necessary
// Print the maximum product found

