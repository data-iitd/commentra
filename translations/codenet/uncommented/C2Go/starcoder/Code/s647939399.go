package main
import "fmt"
func main(){
  var m byte
  var a,b,c [256]int
  for i:=0;i>-1;i++{
    fmt.Scanf("%d %c %d",&a,&m,&b)
    if m=='?'{
      break
    }
    if m=='+'{
      c[i]=a+b
    }
    if m=='-'{
      c[i]=a-b
    }
    if m=='*'{
      c[i]=a*b
    }
    if m=='/'{
      c[i]=a/b
    }
  }
  for j:=0;j<i;j++{
    fmt.Printf("%d\n",c[j])
  }
}
