#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  vector<int> l;
  // Read the number of elements in the array
  cin >> n;
  // Read the elements of the array
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    l.push_back(temp);
  }
  // Sort the array in ascending order using sort() function from STL
  sort(l.begin(), l.end());
  // Count the number of valid triangles that can be formed
  int cnt = 0;
  for(int i = 0; i < n-2; i++){
    for(int j = i+1; j < n-1; j++){
      for(int k = j+1; k < n; k++){
        if(l[i] + l[j] > l[k]){
          cnt++;
        }
        else{
          break;
        }
      }
    }
  }
  // Print the count of valid triangles
  cout << cnt << endl;
  return 0;
}
