#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int longestSubstring(string &s) {
    int n = s.length();
    int left = 0, right = 0, maxlength = 0;
    unordered_set<char> charSet;
    
    while(right < n) {
        if(charSet.find(s[right]) == charSet.end()) {
            charSet.insert(s[right]);
            maxlength = max(maxlength, right - left  + 1);
            right++;
        }else {
            charSet.erase(s[left]);
            left++;
        }
    }
    return maxlength;
}

int main() {
    string s = "abcaabbc";

    cout << longestSubstring(s) << endl;

}