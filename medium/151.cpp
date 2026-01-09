class Solution {
public:
    string reverseWords(string s) {
        bool in  = false;
        string word = "";
        vector<string> words;
        for(int i = 0; i<s.size(); i++){
            if(s[i] >= 33) {
                if(!in) {
                    in = true;
                    if(word.size() > 0) words.push_back(word);
                    word = "";
                }           
                word += s[i];     
            } else in = false;
        }   
        if(word.size() > 0) words.push_back(word);
        string res = ""; 
        for(int i = words.size()-1; i>=0; i--) {
            cout << words[i] << endl;
            res += words[i];  
            if(i != 0) res += ' ';
        }
        return res;
    }
};