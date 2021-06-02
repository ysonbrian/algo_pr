#include <bits/stdc++.h>

using namespace std;

struct singly_ll_node{
  int data;
  singly_ll_node* next;
};

class singly_ll{
public:
    using node = singly_ll_node;
    using node_ptr = node*;
private:
    node_ptr head;

public:

    void push_front(int val) {
        auto new_node = new node{val, NULL};
        if(head != NULL)
            new_node->next = head;
        head = new_node;
    }
    void pop_front()
    {
        auto first = head;
        if(head)
        {
            head = head->next;
            delete first;
        }
    }

    struct singly_ll_iterator
    {
    private:
        node_ptr ptr;
    public:
        singly_ll_iterator(node_ptr p) : ptr(p){}
        int& operator*() {return ptr->data;}
        node_ptr get() {return ptr;}

        singly_ll_iterator& operator++() // 선행증가
        {
            ptr = ptr->next;
            return *this;
        }
        singly_ll_iterator operator++(int) //후행 증가
        {
            singly_ll_iterator result = *this;
            ++(*this);
            return result;
        }
        friend bool operator==(const singly_ll_iterator& left,
            const singly_ll_iterator& right)
            {
                return left.ptr == right.ptr;
        }

        friend bool operator!=(const singly_ll_iterator& left,
                               const singly_ll_iterator& right)
        {
            return left.ptr != right.ptr;
        }
      };
    singly_ll_iterator begin() { return singly_ll_iterator(head);}
    singly_ll_iterator end() {return singly_ll_iterator(NULL);}
    singly_ll_iterator begin() const {return singly_ll_iterator(head);}
    singly_ll_iterator end() const {return singly_ll_iterator(NULL);}

    singly_ll() = default;
    singly_ll(const singly_ll& other) : head(NULL)
    {
        if(other.head)
        {
            head= new node{0, NULL};
            auto cur = head;
            auto it = other.begin();
            while(true){
                cur->data = *it;
                auto tmp = it;
                ++tmp;
                if(tmp == other.end())
                    break;

                cur->next = new node{0, NULL};
                cur = cur->next;
                it = tmp;
            }
        }
    }

    singly_ll(const initializer_list<int>& ilist) : head(NULL){
        for(auto it = rbegin(ilist); it != rend(ilist); it++)
            push_front(*it);
    }
};

int main() {
    singly_ll sll = {1,2,3};
    sll.push_front(0);

    cout << "첫 번째 리스트: ";
    for(auto i : sll)
        cout << i << " ";
    cout << "\n";

    auto sll2 = sll;

    sll2.push_front(-1);
    cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가: ";
    for(auto i : sll2)
        cout << i << ' ';
    cout << '\n';

    cout << "깊은 복사 후 첫 번째 리스트: ";

    for(auto i : sll)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
