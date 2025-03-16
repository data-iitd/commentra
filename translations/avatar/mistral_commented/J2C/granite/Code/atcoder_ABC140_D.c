

#include <stdio.h>
#include <string.h>

int main() {
  int N, K;
  char S[100001];
  scanf("%d %d", &N, &K);
  scanf("%s", S);

  char c1[N];
  char c3[N];
  strcpy(c1, S);
  strcpy(c3, S);

  int flag1 = 0;
  int count1 = 0;
  for (int i = 0; i < N; i++) {
    if (flag1 && c1[i] == 'R') {
      flag1 = 0;
      count1++;
    }
    if (count1 == K) {
      break;
    }
    if (c1[i] == 'L') {
      flag1 = 1;
    }
  }

  int flag3 = 0;
  int count3 = 0;
  for (int i = 0; i < N; i++) {
    if (flag3 && c3[i] == 'L') {
      flag3 = 0;
      count3++;
    }
    if (count3 == K) {
      break;
    }
    if (c3[i] == 'R') {
      flag3 = 1;
    }
  }

  int sum1 = 0;
  int count2 = 1;
  char bef1 = c1[0];
  for (int i = 1; i < N; i++) {
    if (c1[i] == bef1) {
      count2++;
    } else {
      sum1 += count2 - 1;
      count2 = 1;
      bef1 = c1[i];
    }
  }
  sum1 += count2 - 1;

  int sum3 = 0;
  int count4 = 1;
  char bef3 = c3[0];
  for (int i = 1; i < N; i++) {
    if (c3[i] == bef3) {
      count4++;
    } else {
      sum3 += count4 - 1;
      count4 = 1;
      bef3 = c3[i];
    }
  }
  sum3 += count4 - 1;

  printf("%d\n", sum1 > sum3? sum1 : sum3);

  return 0;
}
