Scanner sc = new Scanner ( System.in );
int t = sc.nextInt ( );
int s = sc.nextInt ( );
int q = sc.nextInt ( );
int ans = 0;
while ( s < t ) {
    s *= q;
    ans++;
}
System.out.println ( ans );
