#include <bits/stdc++.h>
#include "score.cpp"
using namespace std;

struct person {
    string name;
    int skills;
    vector<pair<string, int>> sk_set;
    person() {
        cin >> name;
        cin >> skills;
        for(int i =0 ; i < skills ; i++) {
            string tmp;
            int level;
            cin >> tmp >> level;
            sk_set.push_back({tmp, level});
        }
    }
};

void debug(person p) {

}
 
void solve() {
    int c, p; cin >> c >> p;
    vector<person> contri;
    for(int i = 0 ; i < c ; i++){
        contri.push_back(person());
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
}