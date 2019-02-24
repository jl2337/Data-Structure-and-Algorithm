//
//  main.cpp
//  Max Subsequence Sum O(N^2)
//
//  Created by 刘佳杰 on 2/24/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    double max_subseq_sum(const vector<int> &);
    vector<int> my_vec = {1,3,-2,4,-5};    // Max = 1+3+(-2)+4 = 6
    cout << max_subseq_sum(my_vec) << endl;
    return 0;
}
// Using double for loop, Time complexity is O(N^2). Will try to improve algorithm and improve to O(NlogN)
double max_subseq_sum(const vector<int> &vec){
    int max = 0;
    for(int i=0;i<vec.size();i++){
        int sum = 0;
        for(int j=i;j<vec.size();j++){
            sum += vec[j];
            if(sum > max)
                max = sum;
        }
    }
    return max;
}
