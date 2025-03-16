#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s){
  for(int i=0;i<strlen(s)/2;i++){
    if(s[i]==s[strlen(s)-1-i]) continue;
    else return false;
  }
  return true;
}

int main(){
  char s[100];
  scanf("%s",s);
  if(isPalindrome(s)&&isPalindrome(s+strlen(s)/2)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}

