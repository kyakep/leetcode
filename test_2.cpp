#include <string>
#include <iostream>

int main(){
    std::string name = "ASD asd";
    std::tolower(name);
    name.erase(remove(name.begin(), name.end(), ' '));
    std::cout<<name;
}