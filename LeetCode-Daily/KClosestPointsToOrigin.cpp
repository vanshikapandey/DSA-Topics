//Problem Link:https://leetcode.com/problems/k-closest-points-to-origin/

//QUES

/*Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

 */

 /***********CODE**********/

 class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,int> ,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        
       for(int i=0;i<points.size();i++){
           
           double d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
           pq.push({sqrt(d),i});
       }
        
        vector<vector<int>> res;
        
        
        for(int i=0;i<k;i++){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return res;
        
    }
};