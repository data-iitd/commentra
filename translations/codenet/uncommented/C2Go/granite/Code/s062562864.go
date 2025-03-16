
package main

import "fmt"

func main() {


var a,b,c,d,i,j int

fmt.Scanf("%d %d %d %d",&a,&b,&c,&d)

i=a*b
j=c*d
if i>j{
    fmt.Printf("%d\n",i)
}
else{
    fmt.Printf("%d\n",j)
}


}

