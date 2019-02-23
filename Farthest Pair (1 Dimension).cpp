//
//  main.cpp
//  Farthest Pair (1 Dimension)
//
//  Created by 刘佳杰 on 2/19/19.
//  Copyright © 2019 刘佳杰. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Farthest_Pair{
public:
    Farthest_Pair(const vector<double> &);
    void display_result();
private:
    double max = __DBL_MIN__, min = __DBL_MAX__;    // initialize max and min
    int max_id,min_id;  // declare max_id and min_id
};

Farthest_Pair::Farthest_Pair(const vector<double> &vec){
    for(int i=0;i<vec.size();i++){  // Time complexity of the algorithm is O(N)
        if(vec[i] < min){
            min = vec[i];
            min_id = i;
        }
        if(vec[i] > max){
            max = vec[i];
            max_id = i;
        }
    }
}

void Farthest_Pair::display_result(){
    cout << "Farthest Pair is: " << min << " and " << max << endl;
    cout << "There location is: " << min_id << " and " << max_id << endl;
}

int main(int argc, const char * argv[]) {
    fstream infile;
    infile.open("8192int.txt");
    if(!infile){
        cout << "Failed\n\n";
        return 0;   // if filed failed to be opened, exit program
    }
    else{
        cout << "Succeed\n\n";
    }
    vector<double> my_vec;
    while(infile.get()!=EOF){
        double temp;    // use temporary variable
        infile >> temp;
        my_vec.push_back(temp); // insert elements from file to my_vec
    }
    Farthest_Pair my_obj(my_vec);   // Max and Min with their corresponding ID are found during constructor
    my_obj.display_result();    // Print result
    return 0;
}
