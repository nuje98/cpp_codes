class Solution {
    int pathSum_a(TreeNode* root, int sum){
        if(root == nullptr) return 0;
        int res = 0;
        if(root->val == sum) res++;
        res += pathSum_a(root->left, sum-root->val);
        res += pathSum_a(root->right, sum-root->val);
        return res;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        return pathSum(root->left, sum) + pathSum_a(root, sum) + pathSum(root->right, sum);
    }
};

// O(n2)
class Solution {
	int total = 0;
    void findpathSum(TreeNode* root, int sum, int currentSum){
        if(root == nullptr) return;
        currentSum += root.val;
        if(sum == currentSum) total++;
        findpathSum(root->left, sum, currentSum);
        findpathSum(root->right, sum, currentSum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        findpathSum(root, sum, 0);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
    }
};
// O(n)
class Solution {
	int total = 0;
    void findpathSum(TreeNode* curr_node, int curr_sum, int target_sum, unordered_map<int,int>mp){
        if(curr_node == nullptr) return;
        curr_sum += curr_node->val;
        unordered_map<int,int>::iterator it;
		it = mp.find(curr_sum - target_sum);
        if(it != mp.end())
        {
        	total += mp[curr_sum - target_sum];
		}
		it = mp.find(curr_sum);
		if(it != mp.end()) mp[curr_sum]++;
		else mp.insert({curr_sum, 1});
		findpathSum(curr_node->left, curr_sum, target_sum, mp);
		findpathSum(curr_node->right, curr_sum, target_sum, mp);
		mp[curr_sum]--;
		return;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        unordered_map<int,int>mp;
        //mp.insert({0,1});
        findpathSum(root, 0, sum, mp);
        return total;
    }
};
