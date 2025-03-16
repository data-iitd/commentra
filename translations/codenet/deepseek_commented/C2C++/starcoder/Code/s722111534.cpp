#include<iostream>  // Include the standard input/output library

using namespace std;  // Use the standard namespace

int main(){  // Define the main function, the entry point of the program
  int hcell, wcell, hpaint, wpaint, nblack, nwhite;  // Declare integer variables

  // Read the number of cells in the grid and the number of rows/columns to be painted
  cin >> hcell >> wcell;
  cin >> hpaint >> wpaint;

  // Calculate the number of black cells
  nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint);

  // Calculate the number of white cells
  nwhite = (hcell * wcell) - nblack;

  // Print the number of white cells
  cout << nwhite << endl;

  return 0;  // Return 0 to indicate successful execution
}

