//
//  main.cpp
//  Max Subsequence Sum O(N)
//
//  Created by 刘佳杰 on 2/24/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int max_subseq_sum(const vector<int> &);
    vector<int> my_vec = {-1,3,-1,4,-4,1,-3,-2,4,-5};    // Max = 3+(-1)+4 = 6
    cout << max_subseq_sum(my_vec) << endl;
    return 0;
}
// Time complexity of this algorithm is O(N)
// The Best algorithm for this problem
int max_subseq_sum(const vector<int> &vec){
    int max = 0, max_here = 0;
    for(int i=0;i<vec.size();i++){
        max_here += vec[i];
        if(max_here > max){
            max = max_here;
        }
        if(max_here < 0){
            max_here = 0;
        }
    }
    return max;
}
