#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define readInts(a) {int _; cin >> _; a.pb(_);}
#define readIntsArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsV(a) {int _; cin >> _; a.pb(_);}
#define readIntsArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLine(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineV(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArrLineArr(a, n) {int _; for(int i = 0; i < n; i++) {cin >> _; a.pb(_);}}
#define readIntsLineArrLineArrLineArrLineArrLineArrLineArr