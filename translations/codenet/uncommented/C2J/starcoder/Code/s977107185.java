
import java.util.*;

public class Main
{

public static void main(String[] args)
{

Scanner sc=new Scanner(System.in);

int i,j,N,A[]=new int[100],tmp,count=0;

N=sc.nextInt();

for(i=0;i<N;i++)

A[i]=sc.nextInt();

for(i=0;i<N-1;i++)

for(j=N-1;j>i;j--)

if(A[j]<A[j-1])

{

tmp=A[j];

A[j]=A[j-1];

A[j-1]=tmp;

count++;

}

for(i=0;i<N;i++)

System.out.print(A[i]+" ");

System.out.println();

System.out.println(count);

}

}

