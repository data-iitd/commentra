#include <iostream>

int main()
{
  // Declare variables to hold the height and width of the rectangle,
  // as well as the height and width of the cut-out section.
  int h, w, hh, ww;

  // Read the height and width of the rectangle, and the height and width of the cut-out section from user input.
  std::cin >> h >> w >> hh >> ww;

  // Calculate the area of the remaining rectangle after the cut-out section
  // by subtracting the cut-out dimensions from the original dimensions.
  // The area is calculated as (remaining height) * (remaining width).
  std::cout << (h - hh) * (w - ww) << '\n';

  // Return 0 to indicate that the program finished successfully.
  return 0;
}

