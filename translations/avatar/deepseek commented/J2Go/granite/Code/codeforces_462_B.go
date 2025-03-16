
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type c462b struct {
    left int
}

func (c *c462b) compareTo(o interface{}) int {
    return c.left - o.(*c462b).left
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the length of the string and the parameter k:")
    input, _ := reader.ReadString('\n')
    tokens := strings.Split(input, " ")
    n, _ := strconv.Atoi(tokens[0])
    k, _ := strconv.Atoi(tokens[1])
    fmt.Println("Enter the string:")
    input, _ = reader.ReadString('\n')
    s := input[:len(input)-1]
    cards := make([]*c462b, 26)
    for i := 0; i < 26; i++ {
        cards[i] = &c462b{}
    }
    for i := 0; i < n; i++ {
        cards[s[i]-'A'].left++
    }
    ans := 0
    for i := 0; i < k; i++ {
        sort.Slice(cards, func(i, j int) bool {
            return cards[i].left < cards[j].left
        })
        change := int(math.Min(float64(cards[25].left), float64(k-i)))
        ans += change * change
        cards[25].left -= change
        i += change - 1
    }
    fmt.Println(ans)
}

