


import (
	"fmt"
	"os"
	"strings"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)
	if s[:3] == s[1:4] || s[1:4] == s[2:5] {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

