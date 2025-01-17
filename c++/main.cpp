#include "./11-container-with-most-water/Solution.cpp"
#include <iostream>

using namespace std;

int main() {
    vector<int> container = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    auto s = Solution().maxArea(container);

    cout << s << endl;

    return 0;
}