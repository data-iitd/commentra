#include <iostream>

using namespace std;

int main() {
  int height, width, i;
  cin >> height >> width;
  char input_str[width+1];
  for(i = 0; i < width + 2; i++) {
    cout << "#";
  }
  cout << endl;
  for(i = 0; i < height; i++) {
    cin >> input_str;
    cout << "#" << input_str << "#" << endl;
  }
  for(i = 0; i < width + 2; i++) {
    cout << "#";
  }
  cout << endl;
  return 0;
}
