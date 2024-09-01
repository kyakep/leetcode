/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
  MinStack() initializes the stack object.
  void push(int val) pushes the element val onto the stack.
  void pop() removes the element on the top of the stack.
  int top() gets the top element of the stack.
  int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.
*/

#include <iostream>

int main() {
  int nums1[] = {1,2,3,4,5};
  int nums2[] = {5,4,3,2,1};

  int r = 4;

  nums1[r] = nums2[r--];

  for (int i = 0; i < 5; i++) {
    std::cout<<nums1[3]<<" ";  
  }
}