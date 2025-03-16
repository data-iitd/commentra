#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int cnt4 = 0, cnt2 = 0;
  //4の倍数
  //4の倍数出ないが、2の倍数/2
  //の合計がn/2より大きい
  for(int i = 0; i < n; i++) {
    int wk;
    cin >> wk;
    if(wk % 4 == 0)
      cnt4++;
    else if(wk % 2 == 0)
      cnt2++;
  }

  if(cnt4 + cnt2 / 2 >= n / 2)
    cout << "Yes" << endl;
  else 
    cout << "No" << endl;

  return 0;
}
