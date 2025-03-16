
#include <stdio.h>

#define MAX 200000

#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)

#define PARENT(i) ((i-1)/2)

#define MAX_VALUE 2000000000

typedef struct {
  char s;
  int v;
} card;

card a[MAX];
card b[MAX];

void merge(card *a,int l,int m,int r){
  int i,j,k;
  int n1 = m-l;
  int n2=r-m;

  for(i=0;i<n1;i++)L[i]=a[l +i];
  for(i=0;i<n2;i++)R[i]=a[m +i];

  L[n1].v=R[n2].v=MAX_VALUE;

  i=0;
  j=0;
  for(k=l;k<r;k++){
    if(L[i].v<=R[j].v){
      a[k]=L[i++];
    }
    else {
      a[k]=R[j++];
    }
  }
}

void merge_sort(card *a,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    merge_sort(a,l,m);
    merge_sort(a,m,r);
    merge(a,l,m,r);
  }
}

int partition(card *a,int l,int r){
  int i,j;
  card t,x;
  x=a[r];
  i=l-1;
  for(j=l;j<r;j++){
    if(a[j].v<=x.v){
      i++;
      t=a[i];
      a[i]=a[j];
      a[j]=t;
    }
  }
  t=a[i+1];
  a[i+1]=a[r];
  a[r]=t;
  return i+1;
}

void quick_sort(card *a,int l,int r){
  int q;
  if(l<r){
    q=partition(a,l,r);
    quick_sort(a,l,q-1);
    quick_sort(a,q+1,r);
  }
}

int main(){
  int n,i,v;
  char s[10];
  int stable=1;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s%d",s,&v);
    a[i].s=b[i].s=s[0];
    a[i].v=b[i].v=v;
  }

  merge_sort(a,0,n);
  quick_sort(b,0,n-1);

  for(i=0;i<n;i++){
    if(a[i].s!=b[i].s){
      stable=0;
    }
  }

  if(stable==1){
    printf("Stable\n");
  }
  else {
    printf("Not stable\n");
  }

  for(i=0;i<n;i++){
    printf("%c %d\n",b[i].s,b[i].v);
  }

  return 0;
}

