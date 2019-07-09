#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/squares-of-a-sorted-array/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    vector<int> sortedSquares(vector<int> &A) {
        int pos = 0;
        while (pos < A.size() && A[pos] < 0)
            ++pos;
        int neg = pos - 1;
        vector<int> r(A.size());
        int counter = 0;
        while (neg >= 0 && pos < A.size()) {
            if (A[neg] * A[neg] < A[pos] * A[pos]) {
                r[counter] = A[neg] * A[neg];
                --neg;
            } else {
                r[counter] = A[pos] * A[pos];
                ++pos;
            }
            ++counter;
        }
        while (neg >= 0) {
            r[counter] = A[neg] * A[neg];
            --neg;
            ++counter;
        }
        while (pos < A.size()) {
            r[counter] = A[pos] * A[pos];
            ++pos;
            ++counter;
        }
        return r;

    }

    //  O(n + nlogn)
//    vector<int> sortedSquares(vector<int>& A) {
//        for (auto& i : A)
//            i *= i;
//        sort(A.begin(), A.end());
//        return A;
//    }
};

void test1() {
    vector<int> v1{-4, -1, 0, 3, 10};

    cout << "[0,1,9,16,100] ? " << Solution().sortedSquares(v1) << endl;
}

void test2() {

}

void test3() {

}