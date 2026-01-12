class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        int n = heights.size();
        vector<int> nsl(n);
        vector<int> nsr(n);
        vector<int> stack;
        stack.reserve(n);
        
        nsl[0] = -1;
        stack.push_back(0);
        for(int i = 1; i<n; i++){
            while(!stack.empty() && heights[stack[stack.size()-1]] >= heights[i]) stack.pop_back();
            if(stack.empty()) nsl[i] = -1;
            else nsl[i] = stack[stack.size()-1];
            stack.push_back(i);
        }
        stack = {};
        nsr[n-1] = n;
        stack.push_back(n-1);
        for(int i = n-2; i>=0; i--){
            while(!stack.empty() && heights[stack[stack.size()-1]] >= heights[i]) stack.pop_back();
            if(stack.empty()) nsr[i] = n;
            else nsr[i] = stack[stack.size()-1];           
            stack.push_back(i);    
        }

        for(int i = 0; i<n; i++){
            ret = max(ret, heights[i] * (nsr[i] - nsl[i] - 1));
        }

        return ret;
        
    }
};