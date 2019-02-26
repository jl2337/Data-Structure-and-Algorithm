//
//  main.cpp
//  Shell Sort
//
//  Created by 刘佳杰 on 2/25/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

template <class T>
// Same algorithm as Insertion Sort, the only difference is gap.
void InsertShellPass(vector<T> &vec,int gap){
    for(int i=gap;i<vec.size();i++){
        if(vec[i]<vec[i-gap]){
            T temp = vec[i];
            vec[i] = vec[i-gap]; int j;
            for(j=i-2*gap;j>=0&&temp<vec[j];j-=gap){
                vec[j+gap] = vec[j];
            }
            vec[j+gap] = temp;
        }
    }
}

template <class T>
void ShellSort(vector<T> &vec,vector<int> gap){
    for(int i=0;i<gap.size();i++){
        InsertShellPass(vec, gap[i]);   // Do insertion Sorting by a specific gap
    }
}

template <class T>
void print(const vector<T> &vec){
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << '\t'; // Function of printing vector
    }
    cout << endl;
}

// To conclude, Shell Sorting is an unstable algorithm.
// Time Complexity is between O(NlogN) and O(N^2). There are many different ways of choose gaps.
int main(int argc, const char * argv[]) {
    fstream file;
    file.open("data1_8192.txt");
    if(!file) throw "Failed\n"; // If faled to open file, throw exception
    vector<int> my_vec, my_gap = {7,3,1};   // Increment sequence is {7, 3, 1}
    while(file.get()!=EOF){
        int temp;
        file >> temp;
        my_vec.push_back(temp); // Write data into my_vec
    }
    time_t start,end;
    start = clock();
    ShellSort(my_vec,my_gap);   // Record the time of Shell Sort, vector size is 8192.
    end = clock();
    print(my_vec);  // Print sorted vector
    cout << "Running Time is: " << static_cast<double>(end-start)*1000/CLOCKS_PER_SEC << "ms\n";
    return 0;
}
