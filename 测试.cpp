#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size(), len = p.size();
        int j = 0;

        for(int i = 0; i < n1; i++){
            char c1 = s[i], c2 = p[j];

            if((c2 != '.' && c2 != '*') && c1 != c2 && (j+2 < n2 && p[j+1] == '*')){
                j = j + 2;
                len = len - 2;
                c2 = p[j];
            }
            cout << i << ' ' << j << ' ' << len <<endl;

            if(c2 == '*' && j > 0){
                int k = 0, k1 = 1, k2 = 1, kk = 1, x = 0;
                c2 = p[j-1];
                if(c2 == '.') c2 = c1;
                if(c1 == c2){
                    while(kk){
                        kk = 0;
                        if(i+k1 < n1 && s[i+k1] == c1){
                            k1++;
                            kk = 1;
                        }
                        if(j+k2+x < n2 && p[j+k2+x] == c2){
                            k2++;
                            kk = 1;
                        }else if(j+k2+1+x < n2 && p[j+k2+1+x] == '*'){
                            x += 2;
                            len -= 2;
                            kk = 1;
                        }
                    }
                    if(k < k1-k2){
                        while(k < k1-k2){
                            len++;
                            k++;
                            i++;
                        }
                        j += x + 1;
                        continue;
                    }else if(k1 == k2){
                        j += x;
                    }else{
                        j += x;
                        len--;
                    }
                }else{
                    for(int v = 1; v+j < n2; v += 2){
                        if(p[v+j] != c1 && v+j+1 < n2 && p[v+j+1] == '*'){
                            len -= 2;
                        }else if(p[v+j] == c1){
                            len--;
                            j = v + j;
                            c2 = p[j];
                            break;
                        }
                    }
                }
                
            }else if(c2 == '*' && j == 0) return false;

            if(c2 == '.') c2 = c1;
            cout << c1 << ' ' << c2 << endl;
            cout << i << ' ' << j << endl;
            if(c1 == c2) j++;
            else return false;
        }
        while(j+1 < n2 && (p[j] != '.' && p[j]!= '*') && p[j+1] == '*'){
            j = j + 2;
            len = len - 2;
        }
        if(j < n2 && p[j] == '*') len--;
        cout << "len" << ' ' << n1 << ' ' << len <<endl;
        if(len != n1) return false;

        return true;
    }
};
int main() {
    string s = "ab"; 
    string p = ".*a.";
    bool a = Solution().isMatch(s, p);
    cout << a;
}