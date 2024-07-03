/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.*/

/*Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]*/

#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int> > temp;
        for (int i = 0; i < candidates.size()-1; i++){
            std::vector<int> n;
            int sum=0;
            n.push_back(candidates[i]);
            for (int j=0; j<candidates.size()-1; j++){
                if (candidates[i]+candidates[j] < target){
                    /*if (i==1){
                        std::cout<<"asdasdads:";
                    }*/
                    n.push_back(candidates[j]);
                    for (int k=0; k<n.size(); k++){
                        sum+=n[k];
                        if ((k==n.size()-1)&&sum==target)
                            temp.push_back(n);
                    }
                    std::cout<<sum<<std::endl;
                }
            }
        }   
        return temp;     
    }
};

int main(){
    int target = 8;
    std::vector<int> candidates;
    std::vector<std::vector<int> > answer;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);
    Solution s = Solution();
    answer = s.combinationSum2(candidates, target);
    /*for (int i = 0; i < answer.size();i++) {
        std::cout<<"{";
        for (int j = 0; j < answer.size(); j++) {
            std::cout << answer[i][j]<<",";
        }
        std::cout<<"}";
    }*/
}