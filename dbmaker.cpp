#include <bits/stdc++.h>
using namespace std;


vector<string> sitelists;

vector<string> split(string s, char delim) {
    vector<string> res;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        res.push_back(item);
    }
    return res;
}

void read_and_sort(string filename, int limits){
    ifstream fin(filename);
    string s;
    int idx = 0;
    while(getline(fin, s)){
        vector<string> v = split(s, ',');
        idx += 1;
        if(idx > limits) break;
        
        sitelists.push_back(v[1]);

    }
    sort(sitelists.begin(), sitelists.end());
    fin.close();
    cout << "Preprocessing csv files done." << endl;
}

bool isin(string s){
    // check if string s in sitelists, using binary search

    int l = 0, r = sitelists.size() - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(sitelists[mid] == s){
            return true;
        }
        else if(sitelists[mid] < s){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return false;
}

void _tester(int limits){
    read_and_sort("./top-1m.csv", limits);
    for(string t : sitelists){
        cout << t << endl;
    }
    cout << isin("360.com") << endl;
    cout << isin("google.com") << endl;
}


int main(){
    // _tester(3); // should resturn 0 \n 1.
    return 0;
}