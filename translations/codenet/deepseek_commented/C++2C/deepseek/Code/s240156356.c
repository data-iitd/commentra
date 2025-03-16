#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  char str1[100], str2[100];
  scanf("%s %s", str1, str2);

  // Sort the first string in ascending order
  qsort(str1, strlen(str1), sizeof(char), (int (*)(const void *, const void *))strcmp);

  // Sort the second string in descending order
  qsort(str2, strlen(str2), sizeof(char), (int (*)(const void *, const void *))strcmp);

  // Determine the loop limit based on the length of the shorter string
  int loop = strlen(str1) > strlen(str2) ? strlen(str2) : strlen(str1);
  int flag = 0;

  // Compare characters of the two sorted strings
  for(int i = 0; loop > i; i++){
    char ch1 = str1[i];
    char ch2 = str2[i];

    // If characters match, continue to the next character
    if(ch1 == ch2){
      if(loop == i + 1 && strlen(str1) < strlen(str2)){
        flag = 1;
        break;
      }else{
        continue;
      }
    }else{
      // If characters do not match, check if the character from the second string is greater
      if(ch2 > ch1){
        flag = 1;
        break;
      }else{
        break;
      }
    }
  }

  // Check the flag and print the result
  if(flag){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
}
