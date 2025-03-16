
public class insertionsort{
	public static void main(String[] args){
		int n,i,j,a;
		int[] A;
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		A=new int[n];
		for(i=0;i<n;i++){
			A[i]=sc.nextInt();
		}
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				if(A[i]<A[j]){
					a=A[i];A[i]=A[j];A[j]=a;
				}
			}
			for(j=0;j<n-1;j++){
				System.out.print(A[j]+" ");
			}
			System.out.println(A[j]);
		}
	}
}
