class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        vector<vector<int>> heights(mat.size(), vector<int>(mat[0].size(), 0));
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if(mat[i][j] == '1') heights[i][j] = (i == 0 ? 0 : heights[i-1][j]) + 1;
            }
        }

        int ret = 0;
        int n = mat[0].size();
        vector<int> nsl(n);
        vector<int> nsr(n);

        for(int k = 0; k<mat.size(); k++){
            vector<int> stack;
            stack.reserve(n);
            nsl.clear();
            nsr.clear();
            
            nsl[0] = -1;
            stack.push_back(0);
            for(int i = 1; i<n; i++){
                while(!stack.empty() && heights[k][stack[stack.size()-1]] >= heights[k][i]) stack.pop_back();
                if(stack.empty()) nsl[i] = -1;
                else nsl[i] = stack[stack.size()-1];
                stack.push_back(i);
            }
            stack = {};
            nsr[n-1] = n;
            stack.push_back(n-1);
            for(int i = n-2; i>=0; i--){
                while(!stack.empty() && heights[k][stack[stack.size()-1]] >= heights[k][i]) stack.pop_back();
                if(stack.empty()) nsr[i] = n;
                else nsr[i] = stack[stack.size()-1];            
                stack.push_back(i);    
            }

            for(int i = 0; i<n; i++){
                ret = max(ret, heights[k][i] * (nsr[i] - nsl[i] - 1));
            }
        }

        return ret;
    }
};