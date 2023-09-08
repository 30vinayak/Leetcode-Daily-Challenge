#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>> ans;
        ans.push_back({1});
        int index = 0;
        while(numRows > 1){
            vector<int> arr;
            arr.push_back(1);
            for(int i = 0; i+1 <= index; i++){
                arr.push_back(ans[index][i]+ans[index][i+1]);
            }
            arr.push_back(1);
            numRows--;
            index++;
            ans.push_back(arr);
        } 
        return ans;
    }
};