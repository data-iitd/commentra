#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
#include<ctype.h>
#include<time.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n;i>=0;--i)
#define vsort(v) sort((v).begin(),(v).end())
#define vrev(v) reverse((v).begin(),(v).end())
#define vunique(v) sort((v).begin(),(v).end()),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define vcount(v,x) count((v).begin(),(v).end(),x)
#define vfind(v,x) find((v).begin(),(v).end(),x)
#define vlower(v) transform((v).begin(),(v).end(),(v).begin(),::tolower)
#define vupper(v) transform((v).begin(),(v).end(),(v).begin(),::toupper)
#define vsort_unique(v) vsort(v);vunique(v)
#define vsort_count(v,x) vsort(v);int _vsort_count=vcount(v,x);
#define vsort_find(v,x) vsort(v);int _vsort_find=vfind(v,x)-v.begin();
#define vsort_lower(v) vsort(v);vlower(v)
#define vsort_upper(v) vsort(v);vupper(v)
#define vsort_reverse(v) vsort(v);vrev(v)
#define vsort_unique_reverse(v) vsort_unique(v);vrev(v)
#define vsort_count_reverse(v,x) vsort_count(v,x);vrev(v)
#define vsort_find_reverse(v,x) vsort_find(v,x);vrev(v)
#define vsort_lower_reverse(v) vsort_lower(v);vrev(v)
#define vsort_upper_reverse(v) vsort_upper(v);vrev(v)
#define vall(v) (v).begin(),(v).end()
#define vany(v) (v).begin()!=(v).end()
#define vnone(v) (v).begin()==(v).end()
#define vcopy(v1,v2) copy((v1).begin(),(v1).end(),(v2).begin())
#define vcopy_backward(v1,v2) copy_backward((v1).begin(),(v1).end(),(v2).end())
#define vfill(v,x) fill((v).begin(),(v).end(),(x))
#define vfill_n(v,n,x) fill_n((v).begin(),(n),(x))
#define vmax(v) *max_element((v).begin(),(v).end())
#define vmin(v) *min_element((v).begin(),(v).end())
#define vabs(v) transform((v).begin(),(v).end(),(v).begin(),abs)
#define vabs_all(v) vabs(v);vabs(v)
#define vabs_any(v) vabs(v);vabs(v);vabs(v)
#define vabs_none(v) vabs(v);vabs(v);vabs(v);vabs(v)
#define vabs_all_reverse(v) vabs(v);vrev(v)
#define vabs_any_reverse(v) vabs(v);vabs(v);vrev(v)
#define vabs_none_reverse(v) vabs(v);vabs(v);vabs(v);vrev(v)
#define vabs_all_unique(v) vabs(v);vunique(v)
#define vabs_any_unique(v) vabs(v);vabs(v);vunique(v)
#define vabs_none_unique(v) vabs(v);vabs(v);vabs(v);vunique(v)
#define vabs_all_unique_reverse(v) vabs(v);vunique(v);vrev(v)
#define vabs_any_unique_reverse(v) vabs(v);vabs(v);vunique(v);vrev(v)
#define vabs_none_unique_reverse(v) vabs(v);vabs(v);vabs(v);vunique(v);vrev(v)
#define vabs_all_count(v,x) vabs(v);int _vabs_all_count=vcount(v,x);
#define vabs_any_count(v,x) vabs(v);vabs(v);int _vabs_any_count=vcount(v,x);
#define vabs_none_count(v,x) vabs(v);vabs(v);vabs(v);int _vabs_none_count=vcount(v,x);
#define vabs_all_count_reverse(v,x) vabs(v);int _vabs_all_count=vcount(v,x);vrev(v)
#define vabs_any_count_reverse(v,x) vabs(v);vabs(v);int _vabs_any_count=vcount(v,x);vrev(v)
#define vabs_none_count_reverse(v,x) vabs(v);vabs(v);vabs(v);int _vabs_none_count=vcount(v,x);vrev(v)
#define vabs_all_count_unique(v,x) vabs(v);int _vabs_all_count=vcount(v,x);vunique(v)
#define vabs_any_count_unique(v,x) vabs(v);vabs(v);int _vabs_any_count=vcount(v,x);vunique(v)
#define vabs_none_count_unique(v,x) vabs(v);vabs(v);vabs(v);int _vabs_none_count=vcount(v,x);vunique(v)
#define vabs_all_count_unique_reverse(v,x) vabs(v);int _vabs_all_count=vcount(v,x);vunique(v);vrev(v)
#define vabs_any_count_unique_reverse(v,x) vabs(v);vabs(v);int _vabs_any_count=vcount(v,x);vunique(v);vrev(v)
#define vabs_none_count_unique_reverse(v,x) vabs(v);vabs(v);vabs(v);int _vabs_none_count=vcount(v,x);vunique(v);vrev(v)
#define vabs_all_find(v,x) vabs(v);int _vabs_all_find=vfind(v,x)-v.begin();
#define vabs_any_find(v,x) vabs(v);vabs(v);int _vabs_any_find=vfind(v,x)-v.begin();
#define vabs_none_find(v,x) vabs(v);vabs(v);vabs(v);int _vabs_none_find=vfind(v,x)-v.begin();
#define vabs_all_find_reverse(v,x) vabs(v);int _vabs_all_find=vfind(v,x)-v.begin();vrev(v)
#define vabs_any_find_reverse(v,x) vabs(v);vabs(v);int _vabs_any_find=vfind(v,x)-v.begin();vrev(v)
#define vabs_none_find_reverse(v,x) vabs(v);vabs(v);vabs(v);int _vabs_none_find=vfind(v,x)-v.begin();vrev(v)
#define vabs_all_find_unique(v,x) vabs(v);int _vabs_all_find=vfind(v,x)-v.begin();vunique(v)
#define vabs_any_find_unique(v,x) vabs(v);vabs(v);int _vabs_any_find=vfind(v,x)-v.begin();vunique(v)
#define vabs_none_find_unique(v,x) vabs(v);vabs(v);vabs(v);int _vabs_none_find=vfind(v,x)-v.begin();vunique(v)
#define vabs_all_find_unique_reverse(v,x) vabs(v);int _vabs_all_find=vfind(v,x)-v.begin();vunique(v);vrev(v)
#define vabs_any_find_unique_reverse(v,x) vabs(v);vabs(v);int _vabs_any_find=vfind(v,x)-v.begin();vunique(v);vrev(v)
#define vabs_none_find_unique_reverse(v,x) vabs(v);vabs(v);vabs(v);int _vabs_none_find=vfind(v,x)-v.begin();vunique(v);vrev(v)
#define vabs_all_lower(v) vabs(v);vlower(v)
#define vabs_any_lower(v) vabs(v);vabs(v);vlower(v)
#define vabs_none_lower(v) vabs(v);vabs(v);vabs(v);vlower(v)
#define vabs_all_lower_reverse(v) vabs(v);vlower(v);vrev(v)
#define vabs_any_lower_reverse(v) vabs(v);vabs(v);vlower(v);vrev(v)
#define vabs_none_lower_reverse(v) vabs(v);vabs(v);vabs(v);vlower(v);vrev(v)
#define vabs_all_lower_unique(v) vabs(v);vlower(v);vunique(v)
#define vabs_any_lower_unique(v) vabs(v);vabs(v);vlower(v);vunique(v)
#define vabs_none_lower_unique(v) vabs(v);vabs(v);vabs(v);vlower(v);vunique(v)
#define vabs_all_lower_unique_reverse(v) vabs(v);vlower(v);vunique(v);vrev(v)
#define vabs_any_lower_unique_reverse(v) vabs(v);vabs(v);vlower(v);vunique(v);vrev(v)
#define vabs_none_lower_unique_reverse(v) vabs(v);vabs(v);vabs(v);vlower(v);vunique(v);vrev(v)
#define vabs_all_upper(v) vabs(v);vupper(v)
#define vabs_any_upper(v) vabs(v);vabs(v);vupper(v)
#define vabs_none_upper(v) vabs(v);vabs(v);vabs(v);vupper(v)
#define vabs_all_upper_reverse(v) vabs(v);vupper(v);vrev(v)
#define vabs_any_upper_reverse(v) vabs(v);vabs(v);vupper(v);vrev(v)
#define vabs_none_upper_reverse(v) vabs(v);vabs(v);vabs(v);vupper(v);vrev(v)
#define vabs_all_upper_unique(v) vabs(v);vupper(v);vunique(v)
#define vabs_any_upper_unique(v) vabs(v);vabs(v);vupper(v);vunique(v)
#define vabs_none_upper_unique(v) vabs(v);vabs(v);vabs(v);vupper(v);vunique(v)
#define vabs_all_upper_unique_reverse(v) vabs(v);vupper(v);vunique(v);vrev(v)
#define vabs_any_upper_unique_reverse(v) vabs(v);vabs(v);vupper(v);vunique(v);vrev(v)
#define vabs_none_upper_unique_reverse(v) vabs(v);vabs(v);vabs(v);vupper(v);vunique(v);vrev(v)
#define vabs_all_sort(v) vabs(v);vsort(v)
#define vabs_any_sort(v) vabs(v);vabs(v);vsort(v)
#define vabs_none_sort(v) vabs(v);vabs(v);vabs(v);vsort(v)
#define vabs_all_sort_reverse(v) vabs(v);vsort(v);vrev(v)
#define vabs_any_sort_reverse(v) vabs(v);vabs(v);vsort(v);vrev(v)
#define vabs_none_sort_reverse(v) vabs(v);vabs(v);vabs(v);vsort(v);vrev(v)
#define vabs_all_sort_unique(v) vabs(v);vsort(v);vunique(v)
#define vabs_any_sort_unique(v) vabs(v);vabs(v);vsort(v);vunique(v)
#define vabs_none_sort_unique(v) vabs(v);vabs(v);vabs(v);vsort(v);vunique(v)
#define vabs_all_sort_unique_reverse(v) vabs(v);vsort(v);vunique(v);vrev(v)
#define vabs_any_sort_unique_reverse(v) vabs(v);vabs(v);vsort(v);vunique(v);vrev(v)
#define vabs_none_sort_unique_reverse(v) vabs(v);vabs(v);vabs(v);vsort(v);vunique(v);vrev(v)
#define vabs_all_sort_count(v,x) vabs(v);vsort(v);int _vabs_all_sort_count=vcount(v,x);
#define vabs_any_sort_count(v,x) vabs(v);vabs(v);vsort(v);int _vabs_any_sort_count=vcount(v,x);
#define vabs_none_sort_count(v,x) vabs(v);vabs(v);vabs(v);vsort(v);int _vabs_none_sort_count=vcount(v,x);
#define vabs_all_sort_count_reverse(v,x) vabs(v);vsort(v);int _vabs_all_sort_count=vcount(v,x);vrev(v)
#define vabs_any_sort_count_reverse(v,x) vabs(v);vabs(v);vsort(v);int _vabs_any_sort_count=vcount(v,x);vrev(v)
#define vabs_none_sort_count_reverse(v,x) vabs(v);vabs(v);vabs(v);vsort(v);int _vabs_none_sort_count=vcount(v,x);vrev(v)
#define vabs_all_sort_count_unique(v,x) vabs(v);vsort(v);int _vabs_all_sort_count=vcount(v,x);vunique(v)
#define vabs_any_sort_count_unique(v,x) vabs(v);vabs(v);vsort(v);int _vabs_any_sort_count=vcount(v,x);vunique(v)
#define vabs_none_sort_count_unique(v,x) vabs(v);vabs(v);vabs(v);vsort(v);int _vabs_none_sort_count=vcount(v,x);vunique(v)
#define vabs_all_sort_count_unique_reverse(v,x) vabs(v);vsort(v);int _vabs_all_sort_count=vcount(v,x);vunique(v);vrev(v)
#define vabs_any_sort_count_unique_reverse(v,x) vabs(v);vabs(v);vsort(v);int _vabs_any_sort_count=vcount(v,x);vunique(v);vrev(v)
#define vabs_none_sort_count_unique_reverse(v,x) vabs(v);vabs(v);vabs(v);vsort(v);int _vabs_none_sort_count=vcount(v,x);vunique(v);vrev(v)
#define vabs_all_sort_find(v,x) vabs(v);vsort(v);int _vabs_all_sort_find=vfind(v,x)-v.begin();
#define vabs_any_sort_find(v,x) vabs(v);vabs(v);vsort(v);int _vabs_any_sort_find=vfind(v,x)-v.begin();
#define vabs_none_sort_find(v,x) vabs(v);vabs(v);vabs(v);vsort(v);int _vabs_none_sort_find=vfind(v,x)-v.begin();
#define vabs_all_sort_find_reverse(v,x) vabs(v);vsort(v);int _vabs_all_sort_find=vfind(v,x)-v.begin();vrev(v)
#define vabs_any_sort_find_reverse(v,x) vabs(v);vabs(v);vsort(v);int _vabs_any_sort_find=vfind(v,x)-v.begin();vrev(v)
#define vabs_none_sort_find_reverse(v,x) vabs(v);vabs(v);vabs(v);vsort(v);int _vabs_none_sort_find=vfind(v,x)-v.begin();vrev(v)
#define vabs_all_sort_find_unique(v,x) vabs(v);vsort(v);int _vabs_all_sort_find=vfind(v,x)-v.begin();vunique(v)
#define vabs_any_sort_find_unique(v,x) vabs(v);vabs(v);vsort(v);int _vabs_any_sort_find=vfind(v,x)-v.begin();vunique(v)
#define vabs_none_sort_find_unique(v,x) vabs(v);vabs(v);vabs(v);vsort(v);int _vabs_none_sort_find=vfind(v,x)-v.begin();vunique(v)
#define vabs_all_sort_find_unique_reverse(v,x) vabs(v);vsort(v);int _vabs_all_sort_find=vfind(v,x)-v.begin()