#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vll>
#define vull vector<ull>
#define vvull vector<vull>
#define vstr vector<string>
#define vchar vector<char>
#define vbool vector<bool>
#define vpii vector<pair<int,int>>
#define vpiii vector<pair<int,pair<int,int>>>
#define vpiiii vector<pair<int,pair<int,pair<int,int>>>>
#define vpiiiii vector<pair<int,pair<int,pair<int,pair<int,int>>>>>
#define vpiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>
#define vpiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>
#define vpiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>
#define vpiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,int>>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int>>>>>>>>
#define vpiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii vector<pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<int,pair<