#include <stdio.h>
public class Main {
  public static void main(String[] args) {
    int i,N,x;
    x = 0;
    scanf("%d",&N);
    for(i=1; i<=N; i++)
      x += i;
    printf("%d\n",x);
  }
}
