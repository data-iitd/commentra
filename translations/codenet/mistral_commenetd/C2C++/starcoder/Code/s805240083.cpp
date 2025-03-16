#include<bits/stdc++.h>
#define MAX 100005
#define N 100

using namespace std;

struct process{
  char name[N];
  int t;
};

process Q[MAX+1];
int head, tail;

void Enqueue(process x){
  // Function to add a process to the queue
  if(MAX==tail) {
    tail=0;
  }
  Q[tail]=x;
  tail++;
}

process Dequeue(void){
  // Function to remove a process from the queue
  process temp;
  if(head==MAX) {
    head=0;
  }
  temp=Q[head];
  head++;
  return temp;
}

int main(){
  int i,q,n;
  process a;
  int T=0;

  scanf("%d %d", &n, &q);

  for (i=0;i<n;i++){
    scanf("%s%d",a.name,&a.t);
    Enqueue(a);
  }

  while(n!=0){
    a=Dequeue();
    if(a.t>q){
      a.t=a.t-q;
      T+=q;
      Enqueue(a);
    }
    else{
      T=T+a.t;
      printf("%s %d\n",a.name,T);
      n--;
    }
  }

  return 0;
}

