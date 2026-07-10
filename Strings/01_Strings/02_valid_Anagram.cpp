#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool is_Anagram(string s, string t) {
    if(s.size() != t.size()) {
        return false;
    }

    int count[26] = {0};

    for(int i=0; i<s.size(); i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for(int x : count) {
        if(x != 0) return false;
    }

    return true;
}

int main() {
    string s = "anagram", t = "nagaram";

    cout << is_Anagram(s, t);

    return 0;
}