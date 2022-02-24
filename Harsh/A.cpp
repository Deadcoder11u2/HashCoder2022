#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define nline "\n"
#define int ll

//***Debug Function***
#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x << " "; _print(x); cerr<<endl;
#else 
#define debug(x) 
#endif

void _print(vector<int> v1) { cerr<<"[ "; for(auto i: v1) {cerr<<i<<" ";} cerr<<"]";}
void _print(vector<bool> v1) { cerr<<"[ "; for(auto i: v1) {cerr<<i<<" ";} cerr<<"]";}
void _print(vector<vector<int>>v) {cerr<<"\n";for (auto i : v) {cerr<<"[ "; for(auto j : i) {cerr<<j<<" ";} cerr<<"]\n";}}
void _print(vector<pair<int,int>> v) { cerr<<"[ "; for(int i = 0; i<v.size(); i++) {cerr<<"( "<<v[i].first<<" "<<v[i].second<<" )";} cerr<<" ]";}
void _print(int a) {cerr << a;}
void _print(char a) {cerr << a;}
void _print(string a) {cerr << a;}
void _print(bool a) {cerr << a;}
void _print(map<int,int> m) {
	cerr<<nline;
	for(auto &i : m) {
		cerr<<i.first<<" "<<i.second<<nline;
	}
}
void _print(unordered_map<int,int> m) {
	cerr<<nline;
	for(auto &i : m) {
		cerr<<i.first<<" "<<i.second<<nline;
	}
}
void _print(deque<int> d) {
	cerr<<"[ ";
	for(auto &i: d) {
		cerr<<i<<" ";
	}
	cerr<<"]";
}
void _print(set<int> s) {
	cerr<<"[ ";
	for(auto &i: s) {
		cerr<<i<<" ";
	}
	cerr<<"]";
}

//***Binary Exponentiation***
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//***Comparator Funtion***
bool compr(pair<int,int> a, pair<int,int> b) {
    return a.second>b.second;
}

//***Sieve of prime numbers***
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
//-----------------------------------------------------------------------------------

void setIO(string s) {
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

void solve() {
	
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#endif
	fastio()
	//setIO("name");

	solve();

    return 0;
}