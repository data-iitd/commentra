#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  // Declare variables
  int n, // number of strings to be compared
      taro=0, // score for Taro
      hanako=0; // score for Hanako
  vector<string> t, // t is a vector of strings
                 h; // h is a vector of strings

  // Read the number of strings to be compared from the standard input
  cin >> n;

  // Initialize the loops for t and h arrays
  for(int i=0;i<n;i++){
    // Declare strings for each comparison
    string t_str, h_str;

    // Read strings from the standard input and store them in t and h vectors
    cin >> t_str >> h_str;
    t.push_back(t_str);
    h.push_back(h_str);

    // Compare the strings and update the scores accordingly
    if(t_str < h_str){
      hanako += 3; // Hanako gets 3 points if the current string in t is smaller than the corresponding string in h
    }
    else if(t_str > h_str){
      taro += 3; // Taro gets 3 points if the current string in t is larger than the corresponding string in h
    }
    else{ // If the strings are equal
      taro += 1; // Taro gets 1 point if the strings are equal
      hanako += 1; // Hanako gets 1 point if the strings are equal
    }
  }

  // Print the scores for Taro and Hanako
  cout << taro << " " << hanako << endl;

  // Return 0 to indicate successful execution of the program
  return 0;
}
