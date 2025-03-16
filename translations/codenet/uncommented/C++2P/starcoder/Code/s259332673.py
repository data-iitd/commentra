
#define rep(i,n) for(int i=0;i<n;i++)

h1,h2,m1,m2,k = map(int,raw_input().split())
ans = (h2*60+m2)-(h1*60+m1)
print ans-k

