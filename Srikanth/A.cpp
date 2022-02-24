#include <bits/stdc++.h>
#include "score.cpp"
using namespace std;

struct person {
    string name;
    int skills;
    vector<pair<string, int>> sk_set;
    bool occupied;
    int will_get_free = 0;
    person() {
        cin >> name;
        cin >> skills;
        bool occupied;
        for(int i =0 ; i < skills ; i++) {
            string tmp;
            int level;
            cin >> tmp >> level;
            sk_set.push_back({tmp, level});
        }
        occupied = false;
    }
};

struct project {
    string name;
    int d, s, b, r;
    vector<pair<string, int>> skills;
    // bool occupied;
    project() {
        cin >> name >> d >> s >> b >> r;
        // occupied = false;
        for(int i = 0 ; i < r ; i++) {
            string tmp; int level;
            cin >> tmp >> level;
            skills.push_back({tmp, level});
        }
    }
};


bool comp(project p1, project p2) {return (double)(p1.s/p1.d) > (double)(p2.s/p2.d) ;}

void debug(person p) {

}

void debug(vector<project> projects) {
    for(project p : projects) {
        cerr << p.name << " " << p.b << endl;
    }
}

vector<person> contri;
vector<project> projects;

int get_person(string s, int level, bool update) {
    for(int i =0 ; i < contri.size() ; i++) {
        person p = contri[i];
        // cout << p.occupied << endl;
        if(!p.occupied) {
            for(auto p : p.sk_set) {
                if(s == p.first && p.second >= level) {
                    if(update && p.second == level) {
                        p.second++;  
                    }
                    return i;
                }
            }
        }
    }
    return -1;
}

void free_person(int cur_day) {
    for(int i =0 ; i < contri.size() ; i++) {
        if(contri[i].will_get_free < cur_day) {
            contri[i].occupied = false;
        }
    }
}
 
void solve() {
    int c, p; cin >> c >> p;
    for(int i = 0 ; i < c ; i++) {
        contri.push_back(person());
        contri[i].occupied = false;
    }
    for(int i = 0 ; i < p ; i++) {
        projects.push_back(project());
    }
    int days_passed = 0;
    sort(projects.begin(), projects.end(), comp);
    string out = "";
    int cnt = 0;
    debug(projects);
    for(int i = 0 ; i < p ; i++) {
        project pro = projects[i];
        bool possible = true;
        vector<pair<string, int>> contris;
        
        for(auto p: pro.skills) {
            int idx = get_person(p.first, p.second, false);
            possible &= idx >= 0;
            if(idx != -1) {
                contris.push_back({contri[idx].name, idx});
                contri[idx].occupied = true;
            }
        }
        if(possible) {
            cnt++;
            out += pro.name + "\n";
            for(auto p : contris) {
                out += p.first + " ";
                contri[p.second].occupied = true;
                contri[p.second].will_get_free = days_passed + pro.d;
            }
            out += "\n";
        }
        else {
            for(auto p : contris) {
                contri[p.second].occupied = false;
            }
        }
        days_passed += pro.d;
        free_person(days_passed);
    }
    cout << cnt << endl;
    cout << out << endl;
}

// int score() {

// }

int main() {
    freopen("b_better_start_small.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    solve();
}