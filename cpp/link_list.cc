// g++ -std=c++11 -o tree binary_tree.cc &&./tree.exe
// author: kexinhu
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

struct node{
    int data;
    struct node* next; // 这里的struct关键字不可少
};

// 头插法建立链表, 建立后的链表是反序
node* head_insert(int* arr, int length){
   if(length == 0) return nullptr;
   node* head = new node();
   head->data= arr[0];
   head->next=nullptr;
   for(int i=1;i<length;i++){
       node* p = new node();
       p->data = arr[i];
       p->next= head;
       head=p;
   }
   return head;
}

void visit_node(node* p){
    cout<<p->data<<" ";
}

void delete_node(node* p){
    if(p==nullptr) return;
    free(p);
}

void link_list_visit(node* head, void(*fun)(node*)) {
    if(head==nullptr) return;
    node* p = head;
    while(p){ 
        fun(p); 
        p = p->next;
    }
}

// 对链表进行反转
node* reverse_link_list(node* head){ 
    if(head==nullptr||head->next == nullptr) return head;
    node* prev = nullptr;
    node* p = head;
    node* next = p->next;
    while(p&&next){
        //cout<<"cur data:"<<p->data<<endl;
        // 记录下一个节点的next
        node* nextOfNext = next->next;
        // 重置当前节点的next
        p->next = prev;
        // 重置下一节点的next
        next->next = p;
        // 指针移动
        prev = p;
        p = next; 
        next = nextOfNext;
    } 
    return p;
}

int main(){
   int arr[] = { -1,2,5,6,10,8,9,20}; 
   int len = sizeof(arr)/sizeof(int);
   cout<<"arr size:"<<len<<endl;

   cout<<"create link list:"<<endl;
   node* list = head_insert(arr, len);

   cout<<"visit link list:"<<endl;
   link_list_visit(list, visit_node); 

   cout<<"\nreverse link list:"<<endl;
   node* reversed_link = reverse_link_list(list);
   link_list_visit(reversed_link, visit_node); 

   cout<<"\ndelete link list"<<endl;
   link_list_visit(list, delete_node); 
}
