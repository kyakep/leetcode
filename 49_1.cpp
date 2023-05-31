/*Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string> > ans; //двумерная матрица i - набор букв, j - конкретное слово
        std::unordered_map<std::string, int> mapp; //мапа стринг-инт стринг - набор букв, инт - итератор
        for(int i = 0, j = 0; i < strs.size(); i++) {
            std::string tempstr = strs[i]; //присваиваем стрингу значение i-того стринга вектора strs[i], чтобы потом отсортировать без последствий
            sort(tempstr.begin(), tempstr.end()); //сортировка чаров этого стринга
            if(mapp.find(tempstr) != mapp.end()) { // он по мапе ищет набор букв
                ans[mapp[tempstr]].push_back(strs[i]); //в скобках ans находится итератор при значении стринга tempstr, туда 
            }
            else { //если удовлетворяет условию
                mapp[tempstr] = j; //итератор добавляемого элемента под набор букв
                ans[mapp[tempstr]].push_back(strs[i]); 
                j++;
            }     
        }
        return ans;
    }
};