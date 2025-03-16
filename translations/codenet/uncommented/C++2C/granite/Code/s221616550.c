
#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s){
  int len = strlen(s);
  for(int i=0;i<len/2;i++){
    if(s[i]==s[len-1-i]) continue;
    else return false;
  }
  return true;
}

int main(){
  char s[100];
  scanf("%s",s);
  if(isPalindrome(s)&&isPalindrome(strndup(s,strlen(s)/2))){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}
