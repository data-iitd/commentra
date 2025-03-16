// Importing required packages
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Initializing variables
var reader = &bufReader{
	bufio.NewReader(os.Stdin),
	make([]byte, 0),
	0,
}
var writer = bufio.NewWriter(os.Stdout)
