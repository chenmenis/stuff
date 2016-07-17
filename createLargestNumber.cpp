#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <climits>
#include <cstring>
#include <cmath>
using namespace std;

void maxNumber(vector<int> &nums1,int k,vector<vector<int>> &MXes){
    vector<int> nums(nums1);
 
    while(nums.size()){
        MXes[nums.size()-1].resize(nums.size());  
        MXes[nums.size()-1] = nums;
        if(nums.size() ==1) { nums.erase(nums.begin()+nums.size()-1); break;}
        
        for(int i = 0; i + 1 < nums.size();i++){
            if(nums[i] <= nums[i+1] ) {
                cout << " erase nums[i] " << nums[i] << endl; 
                nums.erase(nums.begin()+i);
                            break;

            }
            else if(i+1 == nums.size()-1){
                nums.erase(nums.begin()+i+1);
                cout << " erase nums[i+1] " << nums[i+1] << endl; 

                            break;

            }
     //   cout << " asfsdf:1  " << nums.size() << " i " << i << endl;
            
        }
      //  cout << " asfsdf  " << nums.size() << endl;
    }
    for(int i = 0 ; i < MXes.size();i++){
        
        for(int j=0; j < MXes[i].size();j++){
            cout << MXes[i][j] << "," ;
        }
        cout << endl;
    }
}
int getNumFromTwoList(vector<int> list1,vector<int> list2){
    int ptr1(0);
    int ptr2(0);
    int res(0);
    int totalDigits(list2.size()+list1.size());
    vector<int> t(totalDigits);
    int cur(0);
    while(1){
        
       if(ptr1 >= list1.size() && ptr2 >= list2.size()) break;
        
       int num1(-1),num2(-1);
       
       if(ptr1 < list1.size()){ 
        num1 = list1[ptr1];
       }
        
       if(ptr2 < list2.size()){
        num2 = list2[ptr2];
       }
       (num1 > num2) ? ptr1++:ptr2++;
       int candidate = max(num2,num1);
       t[cur++] = candidate;
    }
    
    for(int i = 0; i < t.size();i++){
        res +=   t[i]*pow(10,t.size()-i-1);
    }
    cout << endl;
    cout <<  " res: " << res << endl;
    return res;
}

int result_merge(vector<vector<int>> &MXes1,vector<vector<int>> &MXes2,int k){
    int largest(0);
    vector<int> empty;
    
    if(k <= MXes1.size()){
       vector<int> &list1 = MXes1[k-1];
       cout << " list1 size " << list1.size()  <<endl;
       largest = max(largest,getNumFromTwoList(list1,empty));
    }
    
    if(k <= MXes2.size()){
       vector<int> &list2 = MXes2[k-1];
       cout << " list2 size " << list2.size()  <<endl; 
       largest = max(largest,getNumFromTwoList(list2,empty));

    }
    
    for(int i = 0; i < k;i++){
        if(i < MXes1.size() ){

            vector<int> &list1 =MXes1[i];
            cout << " list1 size " << list1.size() << " i " << i << " k - i - 2 " << k -i -2 <<endl;
            
            if(k-i-2 < MXes2.size()) {
                vector<int> &list2 =MXes2[k-i-2];
                cout << " list2 size " << list2.size() << endl;
                largest = max(largest,getNumFromTwoList(list1,list2));
            }   
            
        }
        
    }
    
    return largest;
}

int maxNumber(vector<int> nums1, vector<int> nums2,int k) {
    vector< vector<int>> num1list(nums1.size());
    vector< vector<int>> num2list(nums2.size());
    
   maxNumber(nums1,k,num1list);
    maxNumber(nums2,k,num2list);
    cout << " num1list.size() " <<  num1list.size() << endl;
    cout << " num2list.size() " <<  num2list.size() << endl;
    
    getNumFromTwoList(nums1,nums2);
    cout << result_merge(num1list,num2list,k);
    return 0;
}


int main() {
    vector<int> list1{4,5,0,9};
    vector<int> list2{1,3,4,8,7};
    
    maxNumber(list1,list2,4);
    return 0;
}

