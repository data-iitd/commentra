#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
  char str1[100], str2[100];
  scanf("%s %s", str1, str2);

  int len1 = strlen(str1);
  int len2 = strlen(str2);

  int loop = len1 > len2 ? len2 : len1;
  bool flag = false;

  for(int i = 0; loop > i; i++){
    char ch1 = str1[i];
    char ch2 = str2[i];

    if(ch1 == ch2){
      if(loop == i + 1 && len1 < len2){
        flag = true;
        break;
      }else{
        continue;
      }
    }else{
      if(ch2 > ch1){
        flag = true;
        break;
      }else{
        break;
      }
    }
  }

  if(flag){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
}

