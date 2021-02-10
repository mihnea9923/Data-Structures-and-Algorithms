#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree b;
    b.add(1);
    b.add(3);
    b.add(5);
    b.add(2);
    b.inorder();
    return 0;
}

