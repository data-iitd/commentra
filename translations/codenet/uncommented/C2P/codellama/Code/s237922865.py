#include <stdio.h>


int main() {
 

  int n;
  scanf("%d",&n);

  int cnt4=0,cnt2=0;
  # 4の倍数
  # 4の倍数出ないが、2の倍数/2
  # の合計がn/2より大きい
  for i in range(n):
    wk = int(input())
    if wk%4==0:
      cnt4 += 1
    elif wk%2==0:
      cnt2 += 1
  if cnt4+cnt2/2>=n/2:
    print("Yes")
  else:
    print("No")

	return 0
}
