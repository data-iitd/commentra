
#include <iostream>


int main() {
 

  int n;
  std::cin>>n;

  int cnt4=0,cnt2=0;
  //4の倍数
  //4の倍数出ないが、2の倍数/2
  //の合計がn/2より大きい
  for(int i=0;i<n;i++){
    int wk;
    std::cin>>wk;
    if(wk%4==0)
      cnt4++;
    else if(wk%2==0)
      cnt2++;
  }

  if(cnt4+cnt2/2>=n/2)
    std::cout<<"Yes\n";
  else 
    std::cout<<"No\n";

	return 0;
}

