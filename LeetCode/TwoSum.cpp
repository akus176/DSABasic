#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> TwoSum(vector<int>& nums, int target) {
    map<int, int> A;

    for(int i = 0; i < nums.size(); i++){
        A.insert({nums[i], i});
    }

    int temp, k = 0;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        temp = target - nums[i];
        auto iterator = A.find(temp); 

        if(iterator == A.end() || iterator->second == i) continue;
        else {
            result.push_back(i);
            result.push_back(iterator->second);
            break;
        }
    }

    return result;
}

int main() {
    vector<int> a = {4, 12, 33, 0, 11, 7, 10};

    vector<int> result = TwoSum(a, 40);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}