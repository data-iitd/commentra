#include<iostream>
#include<cstring>

using namespace std;

struct pp{
  char name[100];
  int t;
};

pp Q[100005];
int head, tail, n;

void enqueue(pp x){
  Q[tail] = x;
  tail = (tail + 1) % 100005;
}

pp dequeue(){
  pp x = Q[head];
  head = (head + 1) % 100005;
  return x;
}

int min(int a, int b){
  return a < b ? a : b;
}

int main(){
  int elaps = 0, c;
  int i, q;
  pp u;

  cin >> n >> q;

  for(i = 1 ; i <= n ; i++){
    cin >> Q[i].name;
    cin >> Q[i].t;
  }
  head = 1;
  tail = n + 1;

  while(head != tail){
    u = dequeue();
    c = min(q,u.t);
    u.t -= c;
    elaps += c;
    if(u.t > 0) enqueue(u);
    else{
      cout << u.name << " " << elaps << endl;
    }
  }

  return 0;
}

