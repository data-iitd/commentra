#include <stdio.h>

int main() {
  int height, width, i;
  scanf("%d %d", &height, &width);
  char input_str[width+1];
  for(i = 0; i < width + 2; i++) {
    print("#", end="");
  }
  print("\n");
  for(i = 0; i < height; i++) {
    scanf("%s", input_str);
    print("#", end="");
    print(input_str, end="");
    print("#\n");
  }
  for(i = 0; i < width + 2; i++) {
    print("#", end="");
  }
  print("\n");
  return 0;
}
