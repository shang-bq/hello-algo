#include"../utils/common.hpp"
int main(){
    int size = 5;
    int longe = 3;
    int *nums = new int[size]{1,2,3,4,5};
    int *enlenge = new int[size+longe];
    for(int i =0;i<(size+longe) ;i++ )
    {
        enlenge[i] = nums[i];
    }
    delete[] nums;
    printArray(enlenge,size+longe);
}