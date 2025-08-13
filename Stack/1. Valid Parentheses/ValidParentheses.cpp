#include <iostream>
#include <stack>
using namespace std;

class Solution {
private:
    stack<char>st; 
public:
    bool check(char close){
        if(st.size()==0) return true;
        int open = (int)close;

        if(st.top()==open-1 || st.top()==open-2){
            st.pop();
            return false;
        }

        return true;
    }

    bool isValid(string s) {
        if(s.size()==1) return false;
        for(char c: s){
            if(c==')' || c=='}' || c==']'){
                if(check(c)) return false;
            }else{
                st.push(c);
            }
        } 
        if(st.size()!=0)return false;
        return true;
    }
};

int main() {
    Solution sol;
    string s = "{}[()]";
    bool result = sol.isValid(s);

    cout << (result ? "Valid" : "Invalid") << endl;

    return 0;
}