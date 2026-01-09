struct Node{
    Node* left = nullptr;
    Node* right = nullptr;
    int l, r, mid;
    pair<int, int> val = {0, 0};

    Node(int le, int ri){
        l = le; r = ri; mid = (le + ri) / 2;
        //cout << le << " " << ri << endl;
        if(l == r - 1) return;

        left = new Node(le, mid);
        right = new Node(mid, ri);
    }

    pair<int, int> query(int le, int ri){
        if(l >= le && r <= ri) return val;
        if(ri <= l || le >= r) return {0, 0};
        pair<int, int> ansLeft = left->query(le, ri);
        pair<int, int> ansRight = right->query(le, ri);     
        return {ansLeft.first + ansRight.first, ansLeft.second + ansRight.second};   
    }

    void update(int x, pair<int, int> new_val){
        if(l == x && r == x + 1) return void(val = new_val);
        if(x < mid) left->update(x, new_val);
        if(x >= mid) right->update(x, new_val);
        pair<int, int> ansLeft = left->val;
        pair<int, int> ansRight = right->val;     
        val = {ansLeft.first + ansRight.first, ansLeft.second + ansRight.second};   
    }
};

class Solution {
public:
    int calc(string& s, int i){
        int t = 0;
        if(i > 0 && s[i-1] == s[i]) t++;
        if(i < s.size()-1 && s[i+1] == s[i]) t++;
        return t;
    }

    void calcAndUpdate(Node* st, string& s, int i) {
        if(i < 0) return;
        if(i >= s.size()) return;

        int t = calc(s, i);
        if(t == 1) st->update(i, {1, 0});
        else if(t == 2) st->update(i, {0, 1});
        else st->update(i, {0, 0});
    }

    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        Node *st = new Node(0, s.size());
        for(int i = 0; i<s.size(); i++){
            calcAndUpdate(st, s, i);
        }

        vector<int> ret;

        for(vector<int> q: queries){
            if(q[0] == 1){
                int i = q[1];
                if(s[i] == 'A') s[i] = 'B';
                else s[i] = 'A';
                calcAndUpdate(st, s, i);
                calcAndUpdate(st, s, i-1);
                calcAndUpdate(st, s, i+1);
                //cout << st->val.first << " " << st->val.second << endl;
            } else {
                pair<int, int> total = st->query(q[1], q[2]+1);

                if(q[1] > 0 && s[q[1]] == s[q[1] - 1]) {
                    int t = calc(s, q[1]);
                    if(t == 2) {
                        total.second--; total.first++;
                    } else {
                        total.first--;
                    }
                }

                if(q[1] < s.size()-1 && s[q[2]] == s[q[2] + 1]) {
                    int t = calc(s, q[2]);
                    if(t == 2) {
                        total.second--; total.first++;
                    } else {
                        total.first--;
                    }
                }

                //cout << total.first << " " << total.second << endl;
                ret.push_back(total.second + (total.first / 2));
            }
        }

        return ret;
    }
};