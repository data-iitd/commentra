#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
 int n;
 cin >> n;
 vector<int> ara(n);
 unordered_map<int, int> map;

 // Reading elements of the array and updating the frequency in the HashMap
 for (int i = 0; i < n; i++) {
 int v;
 cin >> v;
 ara[i] = v;
 if (map.find(v) == map.end()) {
 map[v] = 1;
 } else {
 map[v]++;
 }
 }

 // Finding the maximum frequency in the HashMap
 int max = 0;
 for (auto& pair : map) {
 max = std::max(max, pair.second);
 }

 // Finding the element(s) with the maximum frequency
 unordered_map<int, int> mm;
 for (int i = 0; i < n; i++) {
 if (mm.find(ara[i]) == mm.end()) {
 mm[ara[i]] = 1;
 if (mm[ara[i]] == max) {
 printf("%d\n", ara[i]);
 break;
 }
 } else {
 mm[ara[i]]++;
 if (mm[ara[i]] == max) {
 printf("%d\n", ara[i]);
 break;
 }
 }
 }

 return 0;
}

