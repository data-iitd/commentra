// Main loop to read input values
while(true){
    int n, m;
    n = sc.nextInt();
    m = sc.nextInt();
    if(n == 0) break; // Break the loop if n is 0
    
    // Initialize arrays for each iteration
    for(int i = 0; i < 100001; i++){
        here[i] = dp1[i] = dp2[i] = 0;
    }
    
    // Flag to determine behavior based on input
    boolean dpflg = false;
    
    // Read m values and mark them in 'here'
    for(int i = 0; i < m; i++){
        int a = sc.nextInt();
        if(a == 0) dpflg = true; // Set flag if any value is 0
        here[a] = 1;
    }
    
    // Variables to store maximum lengths of sequences
    int maxi1 = 0;
    int maxi2 = 0;
    
    // Calculate maximum length of sequences in dp1
    for(int i = 1; i <= n; i++){
        if(here[i] == 1) dp1[i] = dp1[i - 1] + 1;
        maxi1 = Math.max(dp1[i], maxi1);
    }
    
    // Calculate maximum length of sequences in dp2
    for(int i = 1; i <= n; i++){
        if(here[i] == 1) dp2[i] = dp2[i - 1] + 1;
        else dp2[i] = dp1[i - 1] + 1;
        maxi2 = Math.max(dp2[i], maxi2);
    }
    
    // Output the result based on the value of dpflg
    if(!dpflg){
        System.out.println(maxi1);
    } else {
        System.out.println(maxi2);
    }
}

