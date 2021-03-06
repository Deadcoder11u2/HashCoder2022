#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define mod1 998244353
#define inf 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define size(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define read(arr, n)            \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define write(arr, n)          \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " " ; \
    cout << "\n" ; 
#define loop(i, n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("inputa.txt", "r", stdin);
    // freopen("inputb.txt", "r", stdin);
    // freopen("inputc.txt", "r", stdin);
    // freopen("inputd.txt", "r", stdin);
    // freopen("inpute.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void debug_code()
{
    #ifndef ONLINE_JUDGE
    freopen("debug.txt", "w", stderr);
    #endif
}

class contributor{
    public :
    string name;
    int count;
    vector<pair<string, int>>skills;

    contributor(){
        cin >> name;
        cin >> count;
        skills.resize(count);

        for (int i = 0; i < count; i++){
            cin >> skills[i].first >> skills[i].second;
        }
    }
};

class project{
    public:
    string name;
    int duration, score, bestbefore, count;
    vector<pair<string, int>>roles;

    project(){
        cin >> name;
        cin >> duration >> score >> bestbefore >> count;
        roles.resize(count);

        for (int i = 0; i < count; i++){
            cin >> roles[i].first >> roles[i].second;
        }
    }
};

// comparators

// by score
bool comp_score(const project &p1, const project &p2){
    return p1.score > p2.score;
}

// by duration
bool comp_duration(const project &p1, const project &p2){
    return p1.duration < p2.duration;
}

// by best before day
bool comp_bestbefore(const project &p1, const project &p2){
    return p1.bestbefore > p2.bestbefore;
}

// by ration 
bool comp_ration(const project &p1, const project &p2){
    return (p1.score/p1.duration) >  (p2.score/p2.duration);
}

// by count 
bool comp_count(const project &p1, const project &p2){
    return p1.count < p2.count;
}

signed main(int argc, char **argv){
    fastio();
    init_code();
    debug_code();


    int c, p;
    cin >> c >> p;

    vector<contributor>contra(c);
    vector<project>proj(c);

    sort(all(proj), comp_ration);

    // for (int i = 0; i < c; i++){
    //     cout << i <<  " contributor" << endl;
    //     cout <<  contra[i].name << endl;
    //      for(int j = 0; j < contra[i].count; j++)
    //         cout << contra[i].skills[j].first << " " << contra[i].skills[j].second << endl;
    // }

    // for (int i = 0; i < p; i++){
    //     cout << i <<  " project" << endl;
    //     cout <<  proj[i].name << " "  << proj[i].score << endl;
    //      for(int j = 0; j < proj[i].count; j++)
    //         cout << proj[i].roles[j].first << " " << proj[i].roles[j].second << endl;
    // }

    

   
    return 0;


}

