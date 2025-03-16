#include<stdio.h>

int main(void) {
   // Declare variables to hold the number of sheep and wolves
   int sheep;
   int wolf;

   // Read the number of sheep and wolves from user input
   scanf("%d %d", &sheep, &wolf);

   // Check if the number of wolves is greater than or equal to the number of sheep
   if (wolf >= sheep) {
      // If there are more wolves than sheep, it's unsafe
      printf("unsafe\n");
   } else {
      // If there are fewer wolves than sheep, it's safe
      printf("safe\n");
   }

   // Return 0 to indicate successful execution of the program
   return 0;
}
