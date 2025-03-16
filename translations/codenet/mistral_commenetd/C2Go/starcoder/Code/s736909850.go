
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sheep, err := strconv.Atoi(os.Args[1])
	if err!= nil {
		fmt.Println(err)
		return
	}
	wolf, err := strconv.Atoi(os.Args[2])
	if err!= nil {
		fmt.Println(err)
		return
	}
	if wolf >= sheep {
		fmt.Println("unsafe")
	} else {
		fmt.Println("safe")
	}
}

