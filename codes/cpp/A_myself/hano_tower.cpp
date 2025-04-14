/**
 * 分治经典，汉诺塔
 * 主要实现为分清楚哪个是缓冲杆，哪两个是最终与初始塔
 *  其中a，b,c分别是最左边，最中间，最右边的塔
 * By shang :2024_4_14

 */

#include "../utils/common.hpp"

int sum = 0;

//移动一个圆盘的方法
void move(vector<int> &a, vector<int> & c)
{
    int x = a.back();
    a.pop_back();
    c.push_back(x);
    sum +=1 ;
}

//移动n-1个圆盘从a到c的办法
void  dfs(int n ,vector<int> &a,vector<int> &b,vector<int> &c)
{
    if(n == 1){
        move(a,c);
        return ;
    }
    dfs(n-1, a,c,b);
    move(a,c);
    dfs(n-1,b,a,c);
}


int main ()
{
    vector<int>a = {5,4,3,2,1};
    vector<int>b;
    vector<int>c;
    int size = a.size();
    dfs(size,a,b,c);
    cout << "[";
    for(int num:c){
        cout << num << ",";
    }
    cout << "]" <<endl;
    cout << sum << endl;
    return 0;

}
