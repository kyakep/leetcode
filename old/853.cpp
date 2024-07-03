#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> posSpeed;
        int size;
        for(int i = 0; i <= position.size(); i++) {
            auto it = posSpeed.find(position[i]);
            if(it != posSpeed.end()) {
                if (speed[i] <= it->second){
                    posSpeed[it->first] = speed[i];
                }
            }
            posSpeed.insert({position[i], speed[i]});

            auto iter = posSpeed.find(12);
            if(iter == posSpeed.end()) {
                posSpeed.erase(iter->first);
                size++;
            }
        }
        return posSpeed.size();
    }
};

int main() {
    Solution s;
    vector<int> t1 = {1,1,1};
    vector<int> t2 = {1,1,1};
    cout<<s.carFleet(1, t1, t2);
}