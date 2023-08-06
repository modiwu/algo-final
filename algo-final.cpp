#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

int UPPER_BOUND; 


void generate_primeTable( vector<bool> &primeTable){ // Precompute: primeTable[i] == true: i is prime
    primeTable[0] = primeTable[1] = false;
    for(int i = 2; i < UPPER_BOUND; ++i){
        for(int j = i * i; j <= UPPER_BOUND; j += i){
            primeTable[j] = false;
        }
    }
}
string minstring( string s1, string s2){
    cout << s1 << " " << s2 << endl;
    if(s1.length() != s2.length()){
        return s1.length() > s2.length() ? s2 : s1;
    }
    else{
        return s1 > s2 ? s2 : s1;
    }
}
string shortestAnswerString(int n, vector<bool> &primeTable) {
    map <int, string> dp;
    string s1("0");
    string s2("1");
    string ans((UPPER_BOUND - n), '1');
    // initialization
    for( int i = 1 ; i <= n ; i++ ){
        string s(i, '1');    
        dp[n + i] = s;
    }
    dp[2 * n + 1] = "0";
    // implement
    for(int i = 2 * n + 2; i <= UPPER_BOUND; ++i){
        if( i % 2 == 0 ){ dp[i] = s2 + dp[i - 1]; }
        else {
            dp[i] = minstring( s1 + dp[(n - 1) / 2], s2 + dp[n - 1]);
        }
    }
    for(int i = n + 1; i < UPPER_BOUND; ++i){
       //if(primeTable[i]){
            cout << i << ":" << dp[i] << endl;
        //}
    }
    return "";
}


int main(){
    int n;  //input integer
    cin >> n;
    UPPER_BOUND = 10 * n ;
    vector<bool> primeTable(UPPER_BOUND + 1, true);
    generate_primeTable(primeTable);
    cout << shortestAnswerString(n, primeTable) << endl;
    return 0;
}
