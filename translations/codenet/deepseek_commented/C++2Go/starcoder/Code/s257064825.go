<<<<<<< HEAD
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
=======
package main
import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var str string
	fmt.Scanf("%s", &str)
>>>>>>> 98c87cb78a (data updated)
	sum := 0
	for _, x := range str {
		sum += int(x - '0')
	}
	if sum%9 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

