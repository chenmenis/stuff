#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>

using namespace std;

int largestRectangleArea(vector<int> &height) {

    vector<int> index;
    int ret(0);
    for(int i = 0; i < height.size();i++){
         while(index.size() > 0 && height[index.back()] >= height[i])
                {
                    int h = height[index.back()];
                    index.pop_back();

                    int sidx = index.size() > 0 ? index.back() : -1;
                    cout << h << endl;
                    cout << " sidx " << sidx << endl;
                    cout << " (i-sidx-1) " << (i-sidx-1) << endl ;  
                    if(h * (i-sidx-1) > ret)
                        ret = h * (i-sidx-1);
                } 
        cout << " push index" << i << endl;
        index.push_back(i);
    }
    return ret;
}
int jump2(vector<int>& nums) {
       
    vector<int> steps(nums.size(),0);
    
    for(int i = 1; i < nums.size();i++){
        
        for(int j = 0; j < i ; j ++){
            cout << " reaching for i " << i <<" j+nums[j] "<< j+nums[j] << " j " << j  << " [j] " << nums[j] << endl;
            if(j+nums[j] >= i){
                steps[i] = steps[j] + 1;
                cout << " going i take steps: " << steps[i] << endl;
                break;
            }
        }
    }
    return steps[steps.size()-1];
}

string minWindow(string s, string t) {
    unordered_map<char,int> dict;
    
    for(char x: t)
        dict[x]++;
   
    int minWin(INT_MAX);
    int minWinIdx(0);
    int begin(0); 
    int end(0);
    int counter(t.size());
    
    while(end < s.size())
    {
        
        if(dict.find(s[end])!=dict.end()){
            cout << "s[end]" << s[end] << endl;
            if(dict[s[end]] > 0){
                cout << "decrease " << endl; 
                counter--;
            }
            dict[s[end]]--;
            cout << " counter " << counter << endl;

        }
        end++;
        
        while(!counter){
            if(end-begin < minWin){
                cout << " end - begin " << end - begin << endl;
                cout << " begin " << begin << endl;
                minWin = end-begin ;
                minWinIdx = begin;
            }
            
            
            if(dict.find(s[begin])!=dict.end()){
                dict[s[begin]]++;

                if(dict[s[begin]] > 0){
                    cout << " s[begin] " << s[begin] << endl;
                    counter++;
                }
                
            }
            begin++;
            
        }
    
    }
    cout << minWinIdx << endl;
    return s.substr(minWinIdx,minWin);
        
}

int main() {
    string sf("ADOBECODEBANC");
    string sub("ABC");
   cout << minWindow(sf,sub) << endl;
    
    return 0;
}

