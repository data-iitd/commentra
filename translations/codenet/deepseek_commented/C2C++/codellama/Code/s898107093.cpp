#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
  int n, taro = 0, hanako = 0, i;
  char **t, **h;
  cin >> n;
  t = (char **) malloc(n * sizeof(char *));
  h = (char **) malloc(n * sizeof(char *));

  for (i = 0; i < n; i++) {
    t[i] = (char *) malloc(100 * sizeof(char));
    h[i] = (char *) malloc(100 * sizeof(char));
    cin >> t[i];
    cin >> h[i];
    if (strcmp(t[i], h[i]) < 0) hanako += 3;
    if (strcmp(t[i], h[i]) > 0) taro += 3;
    if (strcmp(t[i], h[i]) == 0) {
      taro += 1;
      hanako += 1;
    }
    free(t[i]);
    free(h[i]);
  }

  cout << taro << " " << hanako << endl;
  return 0;
}

