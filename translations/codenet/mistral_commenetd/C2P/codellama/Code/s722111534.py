#include<stdio.h>

int main():
  hcell, wcell, hpaint, wpaint, nblack, nwhite = 0

  scanf("%d %d",&hcell,&wcell)

  scanf("%d %d",&hpaint,&wpaint)

  nblack = (wcell*hpaint) + (hcell*wpaint) - (hpaint * wpaint)

  nwhite = (hcell*wcell) - nblack

  printf("%d\n",nwhite)

  return 0

