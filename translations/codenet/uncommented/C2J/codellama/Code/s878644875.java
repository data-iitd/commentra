#include <stdio.h>

public class Main {
  public static void main(String[] args) {
    char[] s = new char[4];
    char[] t = new char[4];
    scanf("%s", s);
    scanf("%s", t);
    int hit = 0;
    for (int i = 0; i < 3; i++){
      if (s[i] == t[i]) hit++;
    }
    printf("%d\n", hit);
  }
}

