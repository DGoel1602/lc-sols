class TopVotedCandidate {
public:
    map<int, int> leading;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int lead = 0;

        vector<int> votes(persons.size(), 0);
        for(int i = 0; i<times.size(); i++){
            votes[persons[i]]++;
            if(votes[persons[i]] >= votes[lead]) lead = persons[i];
            leading[times[i]] = lead;
        }
    }
    
    int q(int t) {
        auto it = leading.upper_bound(t);
        it--;
        return it->second;        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */