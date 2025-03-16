#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char s[100000];
  scanf("%s",s);
  int len=strlen(s);
  for(int i=0;i<len/2;i++){
    if(s[i]==s[len-1-i]) continue;
    else{
      printf("No\n");
      return 0;
    }
  }
  if(isPalindrome(s)&&isPalindrome(s+len/2)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}
