#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_M 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int li[MAX_M][MAX_N]; // connections of switches for each bulb
    int bulb_count[MAX_M]; // to store the number of switches connected to each bulb
    for (int i = 0; i < m; i++) {
        scanf("%d", &bulb_count[i]);
        for (int j = 0; j < bulb_count[i]; j++) {
            scanf("%d", &li[i][j]);
        }
    }
    
    int p[MAX_M]; // pattern of on/off states for each bulb
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    
    // Create a set (q) containing all the switches from all the bulbs
    int q[MAX_N] = {0}; // to track switches
    int q_size = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < bulb_count[i]; j++) {
            int switch_num = li[i][j];
            if (!q[switch_num]) {
                q[switch_num] = 1;
                q_size++;
            }
        }
    }
    
    // Create a set (r) containing all the switches from 1 to n
    int r[MAX_N] = {0}; // to track all switches from 1 to n
    for (int i = 1; i <= n; i++) {
        r[i] = 1;
    }
    
    // Calculate the set (v) which contains the switches that are not connected to any bulb
    int v_size = 0;
    for (int i = 1; i <= n; i++) {
        if (!q[i]) {
            v_size++;
        }
    }
    
    // Initialize the answer variable to count the number of valid configurations
    long long ans = 0;
    
    // Iterate over all possible combinations of switches from q
    for (int i = 0; i < (1 << q_size); i++) {
        int valid = 1;
        for (int u = 0; u < m; u++) {
            int count = 0;
            for (int j = 0; j < bulb_count[u]; j++) {
                int switch_num = li[u][j];
                if (i & (1 << (switch_num - 1))) {
                    count++;
                }
            }
            if (count % 2 != p[u]) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            ans += (1LL << v_size); // 2^len(v)
        }
    }
    
    // Print the total number of valid configurations
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
