
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n,c,k,i,j,m,f;
  int *s,*u;
  char *line;
  size_t size;
  s = (int*)malloc(sizeof(int)*1000000);
  u = (int*)malloc(sizeof(int)*1000000);
  line = (char*)malloc(sizeof(char)*1000000);
  scanf("%d",&n);
  for (i=0;i<n;i++) {
    scanf("%d",&s[i]);
  }
  for (c=1;c<n-1;c++) {
    f = 0;
    for (k=0;c<n-1-k*c;k++) {
      u[k*c] = 1;
      if (u[n-1-k*c]) { break; }
      f += s[n-1-k*c]+s[k*c];
      if (m < f) { m = f; }
    }
    for (k=0;k*c<n-1;k++) { u[k*c] = 0; }
  }
  printf("%d\n",m);
  free(s);
  free(u);
  free(line);
  return 0;
}
