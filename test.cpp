#include <iostream>
#include <string>

int main(){
  std::string test = "ABCDEF";
  test.erase(test.begin(), test.begin());
  std::cout << test << std::endl;
}