import java.util.*;
public class MatrixMultiplication{
public static void main(String args[]){
Scanner sc=new Scanner(System.in);
int m,n;
int i,j;
int A[][]=new int[100][100];
int B[]=new int[100];
int S[]=new int[100];

m=sc.nextInt();
n=sc.nextInt();

for(i=0;i<m;i++){
for(j=0;j<n-1;j++){
A[i][j]=sc.nextInt();
}
A[i][n-1]=sc.nextInt();
}

for(i=0;i<n;i++){
B[i]=sc.nextInt();
}

for(i=0;i<m;i++){
for(j=0;j<n;j++){
S[i]=S[i]+A[i][j]*B[j];
}
}

for(i=0;i<m;i++){
System.out.println(S[i]);
}
}
}
