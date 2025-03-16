
package main

import "fmt"
import "bufio"
import "os"

func main(){
    var r float64
    var s,l float64
    var p float64 = 3.141592653589
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanf(reader, "%f", &r)
    
    s = r*r*p
    l = 2*p*r
    
    fmt.Printf("%f %f\n",s,l)
    
    // 