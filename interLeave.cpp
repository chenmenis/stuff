#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void dump(vector< vector<bool> > dp){
    for(int i=0; i < dp.size();i++){
        
        for(int j=0;j< dp[0].size();j++){
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
    cout << "..................." << endl;
    
}
bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size(), row, col;
    
        if(len1+len2!=len3) return false;//if the length doesn't match
    
        if(!len1 || !len2) return s3 == s1+s2; // if at least one (s1 or s2) is empty, compare if the other equals to s3
    
       // bool dp[len1+1][len2+1];
    	//vector< vector<int> > buff(len);
        vector<vector<bool> > dp(len1+1, vector<bool>(len2+1,false));

    
        dp[0][0] = true;
        for(int i = 1; i < len1; i ++ ) dp[i][0] = s3[i-1] == s1[i-1] && dp[i-1][0];
        for(int j = 1; j < len2; j ++ ) dp[0][j] = s3[j-1] == s2[j-1] && dp[0][j-1]; 
                dump(dp);
          cout << " initialized " << endl;
    
        for(int i = 1; i<=len1 ; i++) {
            for(int j = 1;j<=len2; j++) {   
                if(s3[i+j-1] == s1[i-1] && dp[i-1][j])
                    dp[i][j] = true;

                if(s3[i+j-1] == s2[j-1] && dp[i][j-1])
                    dp[i][j] = true;
                dump(dp);
            }
                
        }            

        return dp[len1][len2];                         
}

int main() {
    // Complete the code.
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
    isInterleave(s1,s2,s3);
    return 0;
}

