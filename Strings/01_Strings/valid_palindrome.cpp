#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using namespace std;

bool is_palindrome(string str, int n) {
    int st = 0, end = n-1;

    while(st < end) {

        if(!isalnum(str[st])) {
            st++;
            continue;
        }

        if(!isalnum(str[end])) {
            end--;
            continue;
        }

        if(tolower(str[st]) != tolower(str[end])) {
            return false;
        }

        st++;
        end--;
    }
    return true;
}

int main() {

    string str = {"A man, a plan, a canal: Panama"};
    int n = str.size();

   cout << is_palindrome(str,n);

   return 0;

}