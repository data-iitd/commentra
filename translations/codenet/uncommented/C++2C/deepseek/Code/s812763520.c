#include <stdio.h>
#include <string.h>

int main(){
  int n, ans = 0;
  char a[1000], b[1000], c[1000];
  scanf("%d", &n);
  scanf("%s %s %s", a, b, c);
  
  for(int i = 0; i < n; i++){
    if(a[i] == b[i] && b[i] == c[i]){
    }else if(a[i] == b[i] || b[i] == c[i] || a[i] == c[i]){
      ans++;
    }else{
      ans += 2;
    }
  }
  printf("%d\n", ans);
}
