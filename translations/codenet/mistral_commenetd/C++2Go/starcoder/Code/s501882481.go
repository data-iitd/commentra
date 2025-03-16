
<<<<<<< HEAD

import "fmt"

func main() {
	var S string
	fmt.Scanf("%s", &S)

=======
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
	S, _ := reader.ReadString('\n')
	S = strings.TrimSpace(S)
>>>>>>> 98c87cb78a (data updated)
	if S == "Sunny" {
		fmt.Println("Cloudy")
	} else if S == "Cloudy" {
		fmt.Println("Rainy")
	} else {
		fmt.Println("Sunny")
	}
}

