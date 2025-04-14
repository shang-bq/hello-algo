/**
 * 采用归并排序对链表进行排序
 * 递归方式
 * By:shang,2025-4-12
 */

//分为分割与合并
#include "../utils/common.hpp"

ListNode *merge(ListNode *left, ListNode *right){
/*合并两个链表*/
    auto head = new ListNode(0);
    auto h = head;
    while (left !=nullptr && right != nullptr){
        if(left->val <= right ->val)
        {
            h->next = left;
            left = left->next;
        }
        else{
            h->next = right;
            right = right->next;
        }
        h = h->next;
    }
    h->next = (left==nullptr ? right :left);
    return head ->next;  /*这是因为head只是我们借用来把链表组装的
                            真正的开始是从head->next*/
}

ListNode *merge_spilt_sort(ListNode *head){
/*分割链表head*/
    if(!head || !head->next) return head;
    ListNode *slow = head, *fast = head->next;
    /*快慢指针法找到链表的中间值，快指针比慢指针步长快一步，
    当快指针到末尾时，慢指针指向的下一个就是中值*/
    while(fast!= nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    auto r_head = slow->next;
    slow->next = nullptr;
    auto left = merge_spilt_sort(head);
    auto right = merge_spilt_sort(r_head);
    return merge(left,right);
}
int main() {
    /* 初始化链表 */
    // 初始化各个节点
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);
    // 构建节点之间的引用
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout << "初始化的链表为" << endl;
    printLinkedList(n0);
    ListNode *merge_head = merge_spilt_sort(n0);
    cout << "归并后的链表为" << endl;
    printLinkedList(merge_head);
}

