/**
 * File: vertex.hpp
 * Created Time: 2023-03-02
 * Author: krahets (krahets@163.com)
 */

#pragma once

#include <vector>

using namespace std;

/* 顶点类 */
struct Vertex {
    int val;
    Vertex(int x) : val(x) {
    }
};

/* 输入值列表 vals ，返回顶点列表 vets */     
/*这段 C++ 代码定义了一个函数 valsToVets，它的作用是：
将一个整型值的列表 vals，转换成对应的 Vertex 对象指针列表 vets*/
vector<Vertex *> valsToVets(vector<int> vals) {
    vector<Vertex *> vets;
    for (int val : vals) {
        vets.push_back(new Vertex(val));
    }
    return vets;
}

/* 输入顶点列表 vets ，返回值列表 vals */
vector<int> vetsToVals(vector<Vertex *> vets) {
    vector<int> vals;
    for (Vertex *vet : vets) {
        vals.push_back(vet->val);
    }
    return vals;
}
