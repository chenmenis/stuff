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

int main() {
    // Complete the code.
    vector<int> jmp{1,2,5,4,3,2,3,4,2,1,4,5,6,8,2};
    jump2(jmp);
    //isInterleave(s1,s2,s3);
   // cout << wordPatternMatch(s1,s2) << endl;
    return 0;
}
