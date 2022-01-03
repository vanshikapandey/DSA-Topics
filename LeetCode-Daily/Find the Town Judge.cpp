//Problem Link:https://leetcode.com/problems/find-the-town-judge/

//QUES

/*In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.*/

/*******************CODE************/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(trust.size()==0 && n==1){
            return 1;
        }
        vector<pair<int,int>> vp(n+1,make_pair(0,0));
        
        for(auto e:trust){
            
            vp[e[1]].second++;
            vp[e[0]].first++;
            
        }
        
        for(int i=0;i<vp.size();i++){
            
            if(vp[i].first==0 && vp[i].second==n-1)
                return i;
        }
        
        return -1;
        
    }
};