
#####
# Code
#####

#include <iostream>
#include <cmath>

using namespace std;

// Define a function to calculate the number of combinations of choosing K items from a set of N items
double combi(int N, int K){
    // Initialize the combination value to 1
    double a = 1;
    
    // Calculate the combination value by multiplying the number of choices from the set (N) to the current index (i)
    // and then dividing it by the current index (i+1) to account for the repetition of choices
    for(int i = 0; i < K; i++){
        a *= (N - i);
        a /= (i + 1);
    }
    
    // Return the calculated combination value
    return a;
}

int main(){
    // Read the input values N and P from the user
    int N, P;
    cin >> N >> P;
    
    // Initialize the answer variable to 0
    int ans = 0;
    
    // Read the input values from the user and store them in a list
    int lis[N];
    for(int i = 0; i < N; i++){
        cin >> lis[i];
    }
    
    // Initialize an empty list to store the remainder of each input value when divided by 2
    int ls[N];
    for(int i = 0; i < N; i++){
        ls[i] = lis[i] % 2;
    }
    
    // Calculate the number of 1's and 0's in the list
    int one = 0;
    int zero = 0;
    for(int i = 0; i < N; i++){
        if(ls[i] == 1){
            one++;
        }
        else{
            zero++;
        }
    }
    
    // Initialize two variables to store the pattern values
    double pattern_a = 0;
    double pattern_b = 0;
    
    // Calculate the value of pattern_b by summing up the combinations of choosing 0's from the list
    for(int j = 0; j <= zero; j++){
        pattern_b += combi(zero, j);
    }
    
    // Calculate the value of pattern_a by summing up the combinations of choosing numbers from the list based on the value of P
    int time = 0;
    while(time <= one){
        // Check if the current index (time) is a multiple of P
        if(time % P == 0){
            // If yes, add the combination value to pattern_a
            pattern_a += combi(one, time);
        }
        
        // Increment the index for the next combination
        time++;
    }
    
    // Print the final answer as an integer
    cout << (int)(pattern_a * pattern_b) << endl;
    
    return 0;
}
