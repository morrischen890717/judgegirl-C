#include <iostream>
#include <string>
using namespace std;
int min(int a, int b){
    int now = a;
    if(b < now) now = b;
    return now;
}
int edit_dis(string str1, string str2, int m, int n){
    int dp[m + 1][n + 1];
    if(m == 0) return n;
    if(n == 0) return m;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}
int main(){
    string str_[101];
    int id = 1;
    int shortest, id1, id2;
    shortest = 10000000;
    while(cin >> str_[id]){
        for(int i = 1; i < id; i++){
            if(edit_dis(str_[id], str_[i], str_[id].length(), str_[i].length()) < shortest || (edit_dis(str_[id], str_[i], str_[id].length(), str_[i].length()) == shortest && (1000 * i + id) < (1000 * id1 + id2))){
                shortest = edit_dis(str_[id], str_[i], str_[id].length(), str_[i].length());
                id1 = i;
                id2 = id;
            }
        }
        id++;
    }
    cout << shortest << ' ' << id1 << ' ' << id2 << '\n';
    //cout << edit_dis(str1, str2, str1.length(), str2.length()) << '\n';
    return 0;
}
