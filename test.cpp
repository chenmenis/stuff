#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
void swap(int *x,int *y){
  *x ^= *y;
  *y ^= *x;
  *x ^= *y;
}
class Solutions
{
    public:
        Solutions();
    int maxCoins(vector<int> nums);
    void wiggleSort2(vector<int>& nums);
    vector<int> coinChanger(vector<int> input,int inputNum);
    string minRemoveDupe(string s);
    int nthSuperUglyNumber(int n, vector<int>& primes);
        virtual ~Solutions();
    protected:
    private:
};


Solutions::Solutions(){
}

Solutions::~Solutions(){
}


void Solutions::wiggleSort2(vector<int>& nums){

auto midptr = nums.begin()+nums.size()/2;
nth_element(nums.begin(),midptr,nums.end()); // this functions partions small,medium,large //
int mid = *midptr;
int n = nums.size();
#define S(i) (1+2*(i)) % (n|1)
#define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.

std::cout << "nth_element " << " mid is " << mid <<std::endl;

for(size_t i = 0; i < nums.size();i++){
std::cout << nums[i] << " ";
}
std::cout << std::endl;


int i = 0, j = 0, k = n - 1;
while (j <= k) {
        std::cout<< "see j " << j << " index A(j) " << S(j) << " A(j) " << A(j)<< endl;
        if (A(j) > mid) {
        std::cout<< "ind (i) " << S(i) << " ind A(j) " << S(j) << endl;
        std::cout<< "A (i) " << A(i) << " A(j) " << A(j) << endl;
            swap(A(i++), A(j++));
        }
        else if (A(j) < mid) {
        std::cout<< "ind (j) " << S(j) << " ind A(k) " << S(k) << endl;
        std::cout<< "A(j) " << A(j) << " A(k) " << A(k) << endl;
            swap(A(j), A(k--));

        }
        else {
        std::cout << " j++ " << j <<" to " << j+1 << endl;
            j++;
        }

for(size_t i = 0; i < nums.size();i++){
std::cout << nums[i] << " ";
}
std::cout<< std::endl;

}


for(size_t i = 0; i < nums.size();i++){
std::cout << nums[i] << " ";
}


}

vector<int> Solutions::coinChanger(vector<int> input,int inputNum){

        int minCoinCnt = -1;
        vector<int> bestlist;
        if(!inputNum) return bestlist;
        for (size_t i = 0 ; i < input.size();i++){
                if(input[i] <= inputNum){
                    int curr_number_input = inputNum - input[i];
                    vector<int> coinCnt = coinChanger(input,curr_number_input);
                    if(coinCnt.size() != 0|| curr_number_input == 0) coinCnt.push_back(input[i]);

                    if(minCoinCnt == -1) {
                        bestlist = coinCnt;
                        minCoinCnt = bestlist.size();
                    } else {
                           if(minCoinCnt > coinCnt.size()){
                                bestlist = coinCnt;
                                minCoinCnt = bestlist.size();
                           }
                    }
                }

        }

        return bestlist;
}


class countSmallerSol {
    public:
    vector<int> ft;
    int rsq(int b){
        int sum = 0;
        for(; b; b-=(b&(-b))){ // take 2s compliment on pos apply "&" to orig pos and "-" to orig pos
            sum+=ft[b];
        }
        return sum;
    }
    int adjust(int pos, int val){ // take 2s compliment on pos apply "&" to orig pos and "+" to orig pos
        for(; pos < ft.size()-1; pos+=(pos&(-pos)))
            ft[pos] += val;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> re;
        int sz = nums.size();
        re.assign(sz,0);
        ft.assign(sz+1,0);
        for(int i = 0; i < sz;i++){
            cout << nums[i] << " ";
        }
        cout << endl;
        for(int i = sz-1; i >= 0; i--){
            re[i] = rsq(nums[i]-1);
            cout << " num[i] " << nums[i] << " re[i]"<< re[i] << endl;
            adjust(nums[i],1);
        }
        return re;
    }
};

string Solutions::minRemoveDupe(string s){
    std::vector<int> second (26,0);

    std::string str ="";
    for (char & c : s)
    {
        int new_index = (int)(c - 'a');
        if(second[new_index]==0){
            second[new_index] = 1;
            str+=c;
        }
    }
    cout << " str " << str << endl;
    return str;

}
int Solutions::nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0), ugly;
        ugly.push_back(1);

        for(int i=1; i<n; i++){
            ugly.push_back(0);
            for(int j=0; j<primes.size(); j++)
            {
                ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
            }

            for(int j=0; j<primes.size(); j++) {
                index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);// index[i] stores where each prime current pointer to ugly[index[i]]
            }

        }

        return ugly[n-1];
}

int prodsum(vector<int>& nums, int x){

    int l(1);
    int m(1);
    int r(1);
    if(x - 1 >= 0 && x - 1 <= nums.size()-1 ) l = nums[x-1];
    if(x >= 0 && x <= nums.size()-1) m = nums[x];
    if(x+1 >= 0 && x+1 <= nums.size()-1) r= nums[x+1];
    return l*m*r;
}

int Solutions::maxCoins(vector<int> nums){
    int maxval(0);

    for(int i = 0;i < nums.size();i++) {
        int val = prodsum(nums,i);
        vector<int> num1 = nums;
        num1.erase(num1.begin()+i);
        maxval = max(maxval,val + maxCoins(num1));
    }
    return maxval;

}


int main(){

Solutions s;
vector<int> nums{100,200,300,400,500,600,700,800,900};
//s.wiggleSort2(nums);

vector<int> coins{2,3,1};
vector<int> change = s.coinChanger(coins,11);
/*for(size_t i = 0; i < change.size();i++){
std::cout << change[i] << " ";
}*/
countSmallerSol s1;

vector<int> numtest{6,3,4,5,1};
s1.countSmaller(numtest);

s.minRemoveDupe("acdasdfas");

std::cout<< "sadf " << std::endl;
s.nthSuperUglyNumber(6,coins);
return 0;
}
