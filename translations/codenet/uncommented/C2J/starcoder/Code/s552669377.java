import java.util.*;

public class Main{
public static void main(String[] args){
Scanner sc=new Scanner(System.in);
int n,i,tmp;
long long int min=1000000,max=-1000000,sum=0;

n=sc.nextInt();

for(i=0;i<n;i++){
tmp=sc.nextInt();
if(min>tmp)min=tmp;
if(max<tmp)max=tmp;
sum+=tmp;
}

System.out.println(min+" "+max+" "+sum);
}
}
