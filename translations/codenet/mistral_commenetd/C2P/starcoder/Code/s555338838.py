#include <stdio.h>

#define MAX 101

int main(){
  int key, i, j, len, a[MAX];

  printf("Enter the length of the array: ");
  scanf("%d", &len);

  printf("Enter %d integers: ", len);
  for(i = 0;i < len;i++) {
    scanf("%d", a + i);
  }

  for(j = 1;j < len;j++){
    for(i = 0;i < len;i++) {
      if(i!= 0) printf(" %d", a[i]);
      else printf("%d", a[i]);
    }
    puts("");

    key = a[j];
    for(i = j - 1;i >= 0 && a[i] > key;i--) {
      a[i + 1] = a[i];
    }
    a[i + 1] = key;
  }

  for(i = 0;i < len;i++) {
    if(i!= 0) printf(" %d", a[i]);
    else printf("%d", a[i]);
  }
  puts("");

  return 0;
}
