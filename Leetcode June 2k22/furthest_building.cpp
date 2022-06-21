class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
         int n=heights.size();
        
        //Min-Heap to keep track of k largest height differences
        priority_queue<int, vector<int>, greater<int>> pq;
        
        
        for(int i=1;i<n;i++) {
            //Difference of heights btn current and prev buildings
            int diff = heights[i]-heights[i-1];
            
            //If difference is greater than 0, we need ladder or bricks...
            if(diff>0) {
                pq.push(diff);
                if(pq.size()>ladders) {
                    bricks-=pq.top();
                    pq.pop();
                }
                
                if(bricks<0) return i-1;
            }
        }
        return n-1;
    }
};
