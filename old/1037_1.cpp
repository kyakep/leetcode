/*Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return true if these points are a boomerang.

A boomerang is a set of three points that are all distinct and not in a straight line.*/
#include <vector>
std::vector <int> general_list;

class Solution {
public:
    int left = 0, right = 0;
    bool isBoomerang(std::vector<std::vector<int>>& points) {
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points[i].size(); j++) {
                general_list.push_back(points[i][j]);
            }
        }
        for (int i = 0; i < general_list.size(); i++) {
            for (int j = general_list.size() - 1; j > i; j--) {
                if (general_list[i] == general_list[j] && j - i > 1){
                    left = i;
                    right = j;
                    if (check(i, j)){
                        return true;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        return false;
    }

    bool check (int& left, int& right){
        if (general_list[left] == general_list[right] && left <= right) {
            left++;
            right--;
            check(left, right);
        }
        else{
            return false;
        }
        return true;
    }
};