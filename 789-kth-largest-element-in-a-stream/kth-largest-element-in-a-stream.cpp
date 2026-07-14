class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>>pq;
    int KEle;

public:
  
    
    KthLargest(int k, vector<int>& nums) {
        KEle = k;
     
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(pq.size() < KEle) {
                pq.push(nums[i]);
            }else if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        
    }
    
    int add(int val) {
        if(pq.size() < KEle){
            pq.push(val);
        }else if(pq.top() < val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */