#include <iostream>
using namespace std;

int main()
{

  int i,j,N,A[100],tmp,count=0;

  cin >> N;

  for(i=0;i<N;i++){

    cin >> A[i];
  }

  for(i=0;i<N-1;i++){

    for(j=N-1;j>i;j--){

      if(A[j]<A[j-1]){

	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;

	count++;
      }
    }
  }

  for(i=0;i<N;i++){

    cout << A[i];

    if(i<N-1)cout << " ";

  }

  cout << endl;

  cout << count << endl;

  return 0;
}

