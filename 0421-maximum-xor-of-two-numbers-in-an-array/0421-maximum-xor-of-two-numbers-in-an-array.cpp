struct Node {
    Node* links[2];
    
    Node() {
        links[0] = links[1] = nullptr;
    }
    
    bool containsKey(int bit) {
        return (links[bit] != nullptr);
    }
    
    Node* get(int bit) {
        return links[bit];
    }
    
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int num) {
        Node* node = root;
        int maxNumber = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNumber |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNumber;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            trie.insert(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, trie.getMax(nums[i]));
        }
        return maxi;
    }
};
