
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Function to find the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
    if a < b {
        a, b = b, a // Swap 'a' and 'b' if 'a' is smaller than 'b'
    }

    // Use Euclidean algorithm to find the GCD of 'a' and 'b'
    for r := a % b; r > 0; a, b = b, r {
    }

    // Return the GCD of 'a' and 'b'
    return b
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    n := int(nTemp)

    ansTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    ans := int(ansTemp)

    // Read and process the remaining integers
    for i := 1; i < n; i++ {
        aTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        a := int(aTemp)

        // Update the answer by finding the GCD of the current answer and the new integer 'a'
        ans = gcd(ans, a)
    }

    // Print the final answer to the standard output
    fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

