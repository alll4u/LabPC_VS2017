vector<int> nums = { 1,2,3 };
int k = 3;
int kkkk(vector<int> nums, int k){
	//cout << addsum(nums, 0, nums.size());
	if (addsum(nums, 0, nums.size()) % k == 0)
		return nums.size();
	//cout << nums.size() << endl;
	int l = nums.size();
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < i; j++) {
			int temp = addsum(nums, j, l - i);
			if (temp%k == 0)
				//cout << (l - i - j) << endl;
				return (l - i);
		}
	}
}
int addsum(vector<int> a, int begin, int end) {
	int result = 0;
	for (int i = begin; i < end; i++) {
		result += a[i];
	}
	return result;
}