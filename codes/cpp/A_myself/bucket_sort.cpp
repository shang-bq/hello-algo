/**
 * 桶排序
 * 这种只适合于大量数据的排序，容易出现一个桶中太多数据，导致退化为常规排序
 * By shang 2025-4-12
 */

#include "../utils/common.hpp"

void buckets_sort(vector<float> &nums){
    int k = nums.size()/2;
    vector<vector<float>> buckets(k);  /*注意初始化，防止索引越界*/
    /*当您声明 vector<vector<float>> buckets 时，它只是一个 空的二维向量（大小为0）
     buckets 是空的，所以任何 buckets[i] 的访问都是非法的（即使 i=0 也会越界）
     导致出现不易发现的错误*/
    for(float num :nums){
        int i = num *k;
        buckets[i].push_back(num);
    }
    for(vector<float> &bucket :buckets){
        sort(bucket.begin(),bucket.end());
    }
    int i =0;
    for(vector<float> &bucket :buckets){
        for(float num :bucket){
            nums[i++] = num;
        }
    }
    
}
int main() {
    // 设输入数据为浮点数，范围为 [0, 1)
    vector<float> nums = {0.49f, 0.96f, 0.82f, 0.09f, 0.57f, 0.43f, 0.91f, 0.75f, 0.15f, 0.37f};
    buckets_sort(nums);
    cout << "桶排序完成后 nums = ";
    printVector(nums);

    return 0;
}
