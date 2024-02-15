#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), sign = 1;
        long long output = 0;

        for(int i = 0; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                output = output * 10 + s[i] - '0';
                if(i+1 < n && (s[i+1] < '0' || s[i+1] > '9')) break;
            }
            else if(s[i] == '-' && i+1 < n && (s[i+1] >= '0' && s[i+1] <= '9')) sign = -1;
            else if(s[i] == '+' && i+1 < n && (s[i+1] >= '0' && s[i+1] <= '9')) sign = 1;
            else if(s[i] == ' ') continue;
            else break;
        }
        if(abs(output) > pow(2, 31)-1){
            output = pow(2, 31) - 1;
            if(sign == -1) output = pow(2, 31);
        } 
        output *= sign;

        return output;
    }
};
int main() {
    string s("20000000000000000000");
    int a = Solution().myAtoi(s);
    cout << a;
}