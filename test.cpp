#include <iostream>
#include <stack>

int main(){
    std::stack<int> st;
    st.push(4);
    st.push(5);
    st.push(6);
    for (int i = 0; i <3; i++){
        st.pop();
        break;
    }
    std::cout << st.top() << std::endl;
}