#include <stdio.h>

public class Main {
  public static void main(String[] args) {
    int i, a, b, s;
    int[] count = new int[4];
    for(i = 0;i < 4;i++) count[i] = 0;
    for(i = 0;i < 3;i++){
      scanf("%d %d", &a, &b);
      count[a-1]++;
      count[b-1]++;
    }
    s = 1;
    for(i = 0;i < 4;i++) s *= count[i];
    if(s == 4) printf("YES\n");
    else printf("NO\n");
  }
}

