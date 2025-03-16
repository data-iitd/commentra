
package main

import (
"bufio"
"fmt"
"os"
"strconv"
)

func main() {
reader := bufio.NewReader(os.Stdin)
fmt.Println("Enter a number:")
text, _ := reader.ReadString('\n')
number, _ := strconv.Atoi(text)
fmt.Println(number)
m := number
for i := number - 1; i > 0; i-- {
if m%i == 0 {
fmt.Println(i)
m = i
}
}
}


Translate the above Go code to C++ and end with comment "