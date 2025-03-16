
package main

import (
"bufio"
"fmt"
"math/big"
"os"
"strconv"
"strings"
)

func main() {
reader := bufio.NewReader(os.Stdin)
fmt.Println("Enter a number:")
text, _ := reader.ReadString('\n')
text = strings.TrimSpace(text)

dotIndex := strings.Index(text, ".")
if string(text[dotIndex-1]) == "9" {
fmt.Println("GOTO Vasilisa.")
} else if int(text[dotIndex+1]) > 4 {
number := new(big.Int)
number.SetString(text[:dotIndex], 10)
number.Add(number, big.NewInt(1))
fmt.Println(number.String())
} else {
fmt.Println(text[:dotIndex])
}
}

