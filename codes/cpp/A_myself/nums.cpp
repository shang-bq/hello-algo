#include"../utils/common.hpp"
int main(){
    int size = 5;
    int longe = 3;
    int *nums = new int[size]{1,2,3,4,5};
    int *enlenge = new int[size+longe]{};//这里要加{}初始化enlenge防止出现乱码
    // for(int i =0;i<(size+longe) ;i++ )不能这么写，不然会访问未被定义的部分，导致enlenge的值出现乱码
    for(int i =0;i<(size) ;i++ )
    {
        enlenge[i] = nums[i];
    }
    delete[] nums;
    printArray(enlenge,size+longe);
}