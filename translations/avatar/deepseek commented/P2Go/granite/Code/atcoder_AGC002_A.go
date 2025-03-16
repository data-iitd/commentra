
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    a, b := readTwoInts(reader)
    if a > 0 {
        fmt.Println("Positive")
    } else if a <= 0 && b >= 0 {
        fmt.Println("Zero")
    } else {
        if (a + b) % 2 == 0 {
            fmt.Println("Negative")
        } else {
            fmt.Println("Positive")
        }
    }
}

func readTwoInts(reader *bufio.Reader) (int, int) {
    res := make([]int, 2)
    x := 0
    bs, _ := reader.ReadBytes('\n')
    for i := 0; i < 2; i++ {
        for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
            x++
        }
        x = readInt(bs, x, &res[i])
    }
    return res[0], res[1]
}

func readInt(bytes []byte, from int, val *int) int {
    i := from
    sign := 1
    if bytes[i] == '-' {
        sign = -1
        i++
    }
    tmp := 0
    for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
        tmp = tmp*10 + int(bytes[i]-'0')
        i++
    }
    *val = tmp * sign
    return i
}

// 1. The code starts by importing the necessary packages, including `bufio` for reading input and `fmt` for printing output.
// 2. It defines a `main` function and creates a `reader` object to read input from the standard input.
// 3. It then calls the `readTwoInts` function to read two integers `a` and `b`.
// 4. The code checks if `a` is greater than 0, and if so, it prints 'Positive'.
// 5. If `a` is less than or equal to 0 and `b` is greater than or equal to 0, it prints 'Zero'.
// 6. If neither of the above conditions is met, it checks if the sum of `a` and `b` is even or odd.
// 7. If it's even, it prints 'Negative'; if odd, it prints 'Positive'.
// 8. The `readTwoInts` function reads two integers from the input and returns them as a tuple.
// 9. The `readInt` function reads an integer from the input and returns it.
// 10. The code ends with the comment "