
#include <stdio.h>
#include <string.h>

int main(){
int a,t=0,h=0,lt,lh,tt,hh,l;
scanf("%d",&a);
char taro[100],hana[100];
for(int i=0; i<a; ++i){
scanf("%s %s",taro,hana);
lt= strlen(taro);
lh= strlen(hana);
if(lt>lh){
l=lt;
}
else{
l=lh;
}
tt=0;
hh=0;

if(strcmp(taro,hana)>0){
t=t+3;
}
else if(strcmp(hana,taro)>0){
h=h+3;
}
else if(strcmp(hana,taro)==0){
h=h+1;
t=t+1;
}
}
printf("%d %d\n",t,h);

    return 0;
}

