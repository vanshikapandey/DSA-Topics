//Problem Link:https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/

//QUES

/**************CODE****************/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        int even = 0, odd = 0;
        
        for(int i =0;i<position.size();i++){
            if(position[i]%2){
                odd++;
            }
            else{
                even++;
            }
        }
        
        return min(odd,even);
    }
};




    