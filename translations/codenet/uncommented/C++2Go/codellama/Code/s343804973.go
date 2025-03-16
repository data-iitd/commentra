package main
import "fmt"
var n,m,mod int
var C [310][310]int
var pre [310][310]int
var f [310][310]int
func main(){
	fmt.Scan(&n,&m,&mod)
	C[0][0]=1
	for i:=1;i<=n;i++{
		C[i][0]=C[i][i]=1
		for j:=1;j<i;j++{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod
		}
	}
	for i:=0;i<=m;i++{
		f[1][i]=1
		pre[1][i]=m-i+1
	}
	for i:=2;i<=n+1;i++{
		for j:=0;j<=m;j++{
			for k:=1;k<i;k++{
				f[i][j]=(f[i][j]+f[i-k][j]*pre[k][j+1]%mod*C[i-2][k-1])%mod
			}
		}
		for j:=m;j>=0;j--{
			pre[i][j]=(pre[i][j+1]+f[i][j])%mod
		}
	}
	fmt.Println(f[n+1][0])
}
