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


bool comp(project p1, project p2) {
    // return p1.s > p2.s;
    return (double)(p1.b) >= (double)(p2.b) ;
    // return (double)(1.0*p1.s/(p1.d)) > (double)(p2.s*1.0/(p2.d)) ;
	// return p1.d < p2.d ;
	// return p1.r<p2.r;
    // return (double)(1.0*p1.s*p1.s/p1.r*p1.d) > (double)(p2.s*p2.s*1.0/p2.r*p2.d) ;
 }
// bool comp(project p1, project p2) {return (double)((p1.s*p1.r)/(p1.d*p1.b)) > (double)((p2.s*p2.r)/(p2.d*p2.b)) ;}
void debug(person p) {

}

void debug(vector<project> projects) {
    for(project p : projects) {
        cerr << p.name << " " << p.b << endl;
    }
}

vector<person> contri;
vector<project> projects;

bool flag = false;

int get_person(string s, int level, bool update) {
    for(int i =0 ; i < contri.size() ; i++) {
        person p = contri[i];
        if(!p.occupied) {
            for(auto p : p.sk_set) {
                if((s == p.first && p.second >= level) ) {
                    if(p.second >= level) flag = true;
                    if((p.second == level-1 && flag)) return i;
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
        if(contri[i].will_get_free <= cur_day) {
            contri[i].occupied = false;
        }
    }
}

bool comp1(person p1, person p2) {
    return p1.skills > p2.skills;
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
    // sort(contri.begin(), contri.end(), comp1);
    int days_passed = 0;
    // random_shuffle(projects.begin(), projects.end());
    sort(projects.begin(), projects.end(), comp);
    string out = "";
    int cnt = 0;
    int score = 0;
    // debug(projects);
    vector<bool> vis(p, false);
    // for(int i = 0 ; i < p ; i)
    int current_session = 0;
    for(int i = 0 ; i < p ; i++) {
        project pro = projects[i];
        bool possible = true;
        vector<pair<string, int>> contris;
        vector<pair<string, int>> skill_update;
        
        for(auto p: pro.skills) {
            int idx = get_person(p.first, p.second, false);
            possible &= idx >= 0;
            if(idx != -1) {
                contris.push_back({contri[idx].name, idx});
                skill_update.push_back({p.first, p.second});
                contri[idx].occupied = true;
            }
        }
        if(possible) {
            score += projects[i].s;
            cerr << i << endl;
            cnt++;
            out += pro.name + "\n";
            for(auto p : contris) {
                out += p.first + " ";
                contri[p.second].occupied = true;
                contri[p.second].will_get_free = days_passed + pro.d;
            }
            for(int i = 0 ; i < skill_update.size() ; i++) {
                for(auto &p : contri[contris[i].second].sk_set) {
                    if(p.first == skill_update[i].first && p.second == skill_update[i].second){
                        p.second++;
                    }
                }
            }
            out += "\n";
            current_session = max(current_session, pro.d);
        }
        else {
            // cerr << i << endl;
            if(!vis[i]){
                // cerr << i << endl;
                // i--;
                vis[i] = true;
                days_passed += current_session;
                // free_person(days_passed);
            // cerr << "heloo\n";
                for(auto p : contris) {
                    contri[p.second].occupied = false;
                }
            }
        }
        free_person(days_passed);
        flag = false;
    }
    // cout << "hello" << endl;
    cout << cnt << endl;
    cout << out << endl;
    cerr << days_passed << endl;
    cerr << "score:" << score << endl; 
}

// int score() {

// }

int main() {
    freopen("e_exceptional_skills.txt", "r", stdin);
    freopen("b_out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    solve();
}