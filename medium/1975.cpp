class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int parity = 0;
        int smallest = 1e9;
        long long total = 0;
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[i].size(); j++){
                int val = matrix[i][j];
                int ab = abs(val);
                total += ab;
                if(val < 0) parity ^= 1;
                smallest = min(smallest, ab);
            }
        }

        if(parity) total -= (2 * smallest);
        return total;   
    }
};