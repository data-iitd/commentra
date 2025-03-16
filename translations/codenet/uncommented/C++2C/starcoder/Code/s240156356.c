#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  char str1[100], str2[100];
  scanf("%s %s", str1, str2);

  int len1 = strlen(str1);
  int len2 = strlen(str2);

  if(len1 > len2){
    for(int i = 0; i < len2; i++){
      if(str1[i] > str2[i]){
        printf("No\n");
        return 0;
      }else if(str1[i] < str2[i]){
        break;
      }else{
        continue;
      }
    }
  }else{
    for(int i = 0; i < len1; i++){
      if(str1[i] > str2[i]){
        break;
      }else if(str1[i] < str2[i]){
        printf("No\n");
        return 0;
      }else{
        continue;
      }
    }
  }

  if(len1 == len2){
    printf("Yes\n");
  }else{
    printf("Yes\n");
  }
}

