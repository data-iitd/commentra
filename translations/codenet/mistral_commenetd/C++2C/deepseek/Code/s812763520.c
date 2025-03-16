#include <stdio.h>
#include <string.h>

int main(){
  int n;
  char a[100], b[100], c[100];
  int ans = 0;

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

