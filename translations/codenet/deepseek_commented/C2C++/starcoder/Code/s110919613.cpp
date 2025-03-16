#include <iostream>

using namespace std;

int main()
{
  int i,j,k,L,tmp,d,def,end,aj,max,min;
  
  for(;;){
    int an[20],a1[6],a2[6];
    cin >> an[0] >> L;
    if(!L) break; // If L is 0, break out of the loop
    
    aj=an[0]; end=0;
    for(k=1;k<21;k++){
      for(i=L-1;i>=0;i--,aj/=10){
	a1[i]=aj%10; a2[i]=aj%10; // Initialize a1 and a2 with the digits of aj
      }
      for(i=1;i<L;i++){
	for(j=1;j<L;j++){
	  if(a1[j-1]<a1[j]){ // Sort a1 in ascending order
	    tmp=a1[j-1]; a1[j-1]=a1[j]; a1[j]=tmp;
	  }
	  if(a2[j-1]>a2[j]){ // Sort a2 in descending order
	    tmp=a2[j-1]; a2[j-1]=a2[j]; a2[j]=tmp;
	  }
	}
      }
      d=1; max=0; min=0;
      for(i=L-1;i>=0;i--,d*=10){
	max+=(a1[i]%10)*d; // Calculate max by combining sorted digits
	min+=(a2[i]%10)*d; // Calculate min by combining sorted digits
      }
      def=max-min; // Calculate the difference def
      for(i=0;i<k;i++){
	if(def==an[i]){ // Check if def has been seen before
	  cout << i << " " << def << " " << k-i << endl; // Print the index, def, and steps taken
	  end=1; break; // Set end to 1 to break out of the loop
	}
      }
      if(end==1) break; // If end is 1, break out of the loop
      an[k]=def; aj=def; // Add def to an and update aj
    }
  }
    
  return 0;
}

