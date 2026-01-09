class Solution {
public:
    int getFactors(int num){
        int total = 0;
        int new_factor = -1;

        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) {
                if(i * i == num) return 0;
                if(new_factor != -1) return 0;
                new_factor = i;;
            }
        }

        if(new_factor == -1) return 0;
        return 1 + num + new_factor + num/new_factor;
    }

    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(int num: nums) total += getFactors(num);
        return total;        
    }
};