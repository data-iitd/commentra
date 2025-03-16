
#include<iostream>
#include<string>

#define M 1046527/* your task*/
#define L 14

using namespace std;

char H[M][L]; /* Hash Table */

int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
  return 0;
}

/* convert a string into an integer value */
long long getKey(string str){
  long long sum = 0, p = 1;
  int i;
  for ( i = 0; i < (int)str.length(); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key){ return key % M; }
int h2(int key){ return 1 + (key % (M - 1));}

int find(string str){
  int i,hash,key;
  key = getKey(str);
  i = 0;
  while(1){
    hash = (h1(key) + i * h2(key))%M;
    if(str.compare(H[hash]) == 0)return 1;
    else if(H[hash].length() == 0)return 0;
    i++;
  }
  return 0;
}

int insert(string str){
  int i,hash,key;
  key = getKey(str);
  i = 0;
  while(1){
    hash = (h1(key) + i * h2(key))%M;
    if(str.compare(H[hash]) == 0)return 1;
    else if(H[hash].length() == 0){
      H[hash] = str;
      return 0;
    }
    i++;
  }
  return 0;
  /* your task */

}

int main(){
  int i, n;
  string str, com;
  for ( i = 0; i < M; i++ ) H[i] = "";

  cin >> n;

  for ( i = 0; i < n; i++ ){
    cin >> com >> str;

    if ( com[0] == 'i' ){
      insert(str);
    } else {
      if (find(str)){
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }

  return 0;
}
