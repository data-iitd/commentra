#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX(X, Y) (((X) > (Y))? (X) : (Y))
#define MIN(X, Y) (((X) < (Y))? (X) : (Y))
func compare_int(a, b unsafe.Pointer) int {
  return *(*int)(b) - *(*int)(a) // 大きい順
}
// 公約数
func gcd(a, b int) int {
  if(b == 0){
    return a
  }else{
    return gcd(b, a % b)
  }
}
// 最小公倍数 = a * b / 最大公約数
// 公倍数
func lcm(a, b int) int {
  return a * b / gcd(a, b)
}


// min
func main() {
  var n int
  var k int64
  var q int
  var a [100001]int
  var point [100001]int64 = {0}

  fmt.Scanf("%d%d%d", &n, &k, &q)


  /*
  // 初期化
  for(long int i = 0; i < n; i++){
    point[i] = k;
  }
  */
  /*
  if(q < k){
    for(long int i = 0; i < n; i++){
      printf("Yes\n");
      return 0;
    }
    }*/
  //  一人ずつはしない。問題ずつそれぞれのポイントを考える
  for(long int i = 0; i < q; i++){
    fmt.Scanf("%d", &a[i])
    point[a[i] - 1]++
    /*
    for(long int j = 0; j < n; j++){
      if(a[i] != (j + 1) && point[j] < k){
	point[j]++;
      }
      //      printf("i = %ld  point = %lld\n", i, point[j]);
    }
    */
  }

  // 求め方を変えた
  for(long int i = 0; i < n; i++){
    if(k - (q - point[i]) > 0){
      fmt.Println("Yes")
    }else{
      fmt.Println("No")
    }
  }

  return 0
}


