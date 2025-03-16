#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

int main(){
  int N;
  scanf("%d", &N);
  long long a[N];
  int ind_a[N];
  for(int i = 0; i < N; i++){
    scanf("%lld", &a[i]);
  }
  for(int i = 0; i < N; i++){
    ind_a[a[i] - 1] = i;
  }

  int used_inds[N];
  long long ans = 0;
  for(int i = 0; i < N; i++){
    int left_border;
    int right_border;
    int cur_ind = ind_a[i];
    int left_it = lower_bound(used_inds, N, cur_ind);
    int right_it = lower_bound(used_inds, N, cur_ind + 1);

    if(left_it == 0){
      left_border = -1;
    } else {
      if(left_it == N || used_inds[left_it] > cur_ind){
        left_it --;
      }
      left_border = used_inds[left_it];
    }
    if(right_it == N){
      right_border = N;
    } else {
      right_border = used_inds[right_it];
    }
    ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

    //printf("%d %d %d\n", i, left_border, right_border);
    //printf("%lld\n", ans);

    used_inds[left_it] = cur_ind;
  }

  printf("%lld\n", ans);
  return 0;
}

int lower_bound(int *arr, int n, int key){
  int left = 0;
  int right = n - 1;
  while(left <= right){
    int mid = (left + right) / 2;
    if(arr[mid] >= key){
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

