//
//  main.cpp
//  Insert Sort
//
//  Created by 刘佳杰 on 2/25/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

template<class T>
void insert_sort(vector<T> &vec){
    for(int i=1;i<vec.size();i++){
        // vec[0],vec[1]...vec[i-1] are already sorted
        // Now we need to insert vec[i] into the sorted array
        if(vec[i]<vec[i-1]){
            // Only when vec[i] is less than vec[i-1], we need to insert
            T temp = vec[i];    // Creat a temporary variable to store vec[i]
            vec[i] = vec[i-1];  // vec[i] store value of vec[i-1]
            int j;
            // Find right place to insert vec[i]
            for(j=i-2;j>=0&&temp<vec[j];j--){
                vec[j+1] = vec[j];  // vec[j+1] store value of vec[j]
            }
            vec[j+1] = temp;    // here is the place to insert temp
        }
    }
}
// Analysis of the algorithm
// Best case: The array is sorted, only need to compare n-1 times, Time complexity is O(N)
// Wordt case: The array is sorted in reverse order, Time complexity is O(N^2)
// To conclude, Insertion Sorting is a good choice for arrays which is almost sorted

int main(int argc, const char * argv[]) {
    vector<int> my_vec = {38,69,45,97,76,13,27};
    insert_sort(my_vec);
    for(int i=0;i<my_vec.size();i++){
        cout << my_vec[i] << '\t';
    }
    cout << endl;
    return 0;
}
