#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define PI acos(-1.0)
#define MAX 1000000000
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define sqr(x) (x) * (x)
#define sqrt(x) sqrt(abs(x))
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define repd(i, a, b) for (int i = a; i >= b; i--)
#define repit(col) for (auto it = (col).begin(); it != (col).end(); it++)
#define repib(col) for (auto it = (col).begin(); it != (col).end(); it++)
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf ms.\n", (double)clock() / CLOCKS_PER_SEC * 1000.0)
using namespace std;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<bool> > vvb;
typedef vector<vector<double> > vvd;
typedef vector<vector<long long> > vvll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<string, string> pss;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
typedef set<int> si;
typedef set<char> sc;
typedef set<string> ss;
typedef set<double> sd;
typedef set<long long> sl;
typedef unordered_set<int> usi;
typedef unordered_set<char> usc;
typedef unordered_set<string> uss;
typedef unordered_set<double> usd;
typedef unordered_set<long long> usl;
typedef multiset<int> msi;
typedef multiset<char> msc;
typedef multiset<string> mss;
typedef multiset<double> msd;
typedef multiset<long long> msl;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_min_heap = priority_queue<T, vector<T>, greater<T>, indexed_heap_tag>;
template <typename T>
using indexed_max_heap = priority_queue<T, vector<T>, less<T>, indexed_heap_tag>;
template <typename T>
using indexed_min_priority_queue = priority_queue<T, vector<T>, greater<T>, indexed_heap_tag>;
template <typename T>
using indexed_max_priority_queue = priority_queue<T, vector<T>, less<T>, indexed_heap_tag>;
template <typename T>
using indexed_set_of_pairs = tree<pair<T, T>, null_type, less<pair<T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset_of_pairs = tree<pair<T, T>, null_type, less_equal<pair<T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_min_heap_of_pairs = priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_heap_of_pairs = priority_queue<pair<T, T>, vector<pair<T, T>>, less<pair<T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_min_priority_queue_of_pairs = priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_priority_queue_of_pairs = priority_queue<pair<T, T>, vector<pair<T, T>>, less<pair<T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_set_of_triples = tree<tuple<T, T, T>, null_type, less<tuple<T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset_of_triples = tree<tuple<T, T, T>, null_type, less_equal<tuple<T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_min_heap_of_triples = priority_queue<tuple<T, T, T>, vector<tuple<T, T, T>>, greater<tuple<T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_heap_of_triples = priority_queue<tuple<T, T, T>, vector<tuple<T, T, T>>, less<tuple<T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_min_priority_queue_of_triples = priority_queue<tuple<T, T, T>, vector<tuple<T, T, T>>, greater<tuple<T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_priority_queue_of_triples = priority_queue<tuple<T, T, T>, vector<tuple<T, T, T>>, less<tuple<T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_set_of_quadruples = tree<tuple<T, T, T, T>, null_type, less<tuple<T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset_of_quadruples = tree<tuple<T, T, T, T>, null_type, less_equal<tuple<T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_min_heap_of_quadruples = priority_queue<tuple<T, T, T, T>, vector<tuple<T, T, T, T>>, greater<tuple<T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_heap_of_quadruples = priority_queue<tuple<T, T, T, T>, vector<tuple<T, T, T, T>>, less<tuple<T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_min_priority_queue_of_quadruples = priority_queue<tuple<T, T, T, T>, vector<tuple<T, T, T, T>>, greater<tuple<T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_priority_queue_of_quadruples = priority_queue<tuple<T, T, T, T>, vector<tuple<T, T, T, T>>, less<tuple<T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_set_of_quintuples = tree<tuple<T, T, T, T, T>, null_type, less<tuple<T, T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset_of_quintuples = tree<tuple<T, T, T, T, T>, null_type, less_equal<tuple<T, T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_min_heap_of_quintuples = priority_queue<tuple<T, T, T, T, T>, vector<tuple<T, T, T, T, T>>, greater<tuple<T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_heap_of_quintuples = priority_queue<tuple<T, T, T, T, T>, vector<tuple<T, T, T, T, T>>, less<tuple<T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_min_priority_queue_of_quintuples = priority_queue<tuple<T, T, T, T, T>, vector<tuple<T, T, T, T, T>>, greater<tuple<T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_priority_queue_of_quintuples = priority_queue<tuple<T, T, T, T, T>, vector<tuple<T, T, T, T, T>>, less<tuple<T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_set_of_sextuples = tree<tuple<T, T, T, T, T, T>, null_type, less<tuple<T, T, T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset_of_sextuples = tree<tuple<T, T, T, T, T, T>, null_type, less_equal<tuple<T, T, T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_min_heap_of_sextuples = priority_queue<tuple<T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T>>, greater<tuple<T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_heap_of_sextuples = priority_queue<tuple<T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T>>, less<tuple<T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_min_priority_queue_of_sextuples = priority_queue<tuple<T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T>>, greater<tuple<T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_priority_queue_of_sextuples = priority_queue<tuple<T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T>>, less<tuple<T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_set_of_septuples = tree<tuple<T, T, T, T, T, T, T>, null_type, less<tuple<T, T, T, T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset_of_septuples = tree<tuple<T, T, T, T, T, T, T>, null_type, less_equal<tuple<T, T, T, T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_min_heap_of_septuples = priority_queue<tuple<T, T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T, T>>, greater<tuple<T, T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_heap_of_septuples = priority_queue<tuple<T, T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T, T>>, less<tuple<T, T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_min_priority_queue_of_septuples = priority_queue<tuple<T, T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T, T>>, greater<tuple<T, T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_priority_queue_of_septuples = priority_queue<tuple<T, T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T, T>>, less<tuple<T, T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_set_of_octuples = tree<tuple<T, T, T, T, T, T, T, T>, null_type, less<tuple<T, T, T, T, T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset_of_octuples = tree<tuple<T, T, T, T, T, T, T, T>, null_type, less_equal<tuple<T, T, T, T, T, T, T, T>>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_min_heap_of_octuples = priority_queue<tuple<T, T, T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T, T, T>>, greater<tuple<T, T, T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_max_heap_of_octuples = priority_queue<tuple<T, T, T, T, T, T, T, T>, vector<tuple<T, T, T, T, T, T, T, T>>, less<tuple<T, T, T, T, T, T, T, T>>, indexed_heap_tag>;
template <typename T>
using indexed_min