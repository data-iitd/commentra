
#include<stdio.h>
int main(){
  int hcell,wcell,hpaint,wpaint,nblack,nwhite;
  # 順にマス行、マス列、塗る行、塗る列、塗られたマス、白いマス
  hcell,wcell = map(int,input().split())
  hpaint,wpaint = map(int,input().split())
  nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint)
  nwhite = (hcell*wcell) - nblack
  print(nwhite)
  return 0;
}

