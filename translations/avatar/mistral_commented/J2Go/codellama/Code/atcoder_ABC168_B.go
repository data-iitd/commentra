
package main

import (

    "fmt"

    "os"

    "bufio"

)

func main() {

    scanner := bufio.NewScanner(os.Stdin)

    scanner.Scan()

    K, _ := strconv.Atoi(scanner.Text())

    scanner.Scan()

    S := scanner.Text()

    if len(S) <= K {

        fmt.Println(S)

    } else {

        fmt.Println(S[:K] + "...")

    }

}

