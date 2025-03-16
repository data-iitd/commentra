
#include <iostream>
#include <string>
using namespace std;
int d; // number of test cases
string map[105]; // 2D array to store the grid
int n; // size of the grid
int dx[4] = {0,1,0,-1}; // directions to move in 4 directions
int dy[4] = {-1,0,1,0}; // directions to move in 4 directions
int sum, flg = 0; // variables used in visit function
int x = 2, y = n; // initial position of the function
char temp; // temporary variable to store the character in the grid

void visit() {
  // function to find the path of 'O' in the grid
  int ab[4] = {2,2,2,2}; // array to store the number of 'O's in 4 directions

  while(1) {
    sum = 0; // initialize sum to 0
    flg = 0; // initialize flag to 0

    while(1) {
      if(map[y+dy[flg]*2][x+dx[flg]*2] != '#' && map[y+dy[flg]][x+dx[flg]] != ' ') {
        // check if the next cell is not a wall or empty
        flg++; // increment flag

        // mark the cell as visited
        map[y+dy[flg]][x+dx[flg]] = ' ';

        // move to the next cell
        y = y + dy[flg];
        x = x + dx[flg];

        sum++; // increment sum

        break;
      }
    }

    if(flg == 4) { // if all 4 directions are visited
      flg = 0; // reset flag

      if(sum == 0) break; // if no 'O' is found, break the loop

      ab[0] = ab[1]; // copy the value of ab[1] to ab[0]
      ab[1] = ab[2]; // copy the value of ab[2] to ab[1]
      ab[2] = sum; // store the number of 'O's in the current direction

      if(ab[0] == 1 && ab[2] == 1 && ab[1] == 1) { // check if all 3 directions have 'O's
        break; // if yes, break the loop
      }
    }
  }
}

int main() {
  cin >> d; // read the number of test cases

  for(int l=0;l<d;l++) { // iterate through each test case
    cin >> n; // read the size of the grid

    if(n == 1) { // if the size of the grid is 1
      cout << "#" <<endl; // print '#'
      if(l != d-1) cout << endl; // print newline if it's not the last test case
      continue; // move to the next test case
    }

    for(int i=0;i<=n+1;i++){ // initialize the map with '#' and '.
      map[i].resize(n+2);
      for(int j=0;j<=n+1;j++){
        map[i][j] = '#';
        if(i == 0 || j == 0 || i == n+1 || j == n+1) map[i][j] = '.';
      }
    }

    visit(); // call the visit function

    for(int i=1;i<=n;i++){ // print the grid
      for(int j=1;j<map[i].size()-1;j++) {
        cout << map[i][j];
      }
      cout << endl;
    }

    if(l != d-1) cout << endl; // print newline if it's not the last test case
  }

  return 0;
}