/* 链表节点 */
class linked_list
{
public:
    int val;
    linked_list *next;
    linked_list(int x):val(x), next(nullptr){
    };  
    ~linked_list();
};

//  ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {
//     }
// };