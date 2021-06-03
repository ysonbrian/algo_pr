#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

struct bst {
    node *root = nullptr;

    node* find(int value) {
        return find_impl(root, value);
    }
private:
    node* find_impl(node* current, int value) {
        if(!current) // 현재 노드 값이 없다면
        {
            cout << '\n';
            return NULL;
        }

        if(current->data == value){ // value 값을 찾은 경우
            cout << value << "을 찾았습니다." << "\n";
            return current;
        }

        if(value < current->data) {  // value 값이 현재 노드 왼쪽에 있는 경우
            cout << current->data << "에서 왼쪽으로 이동: ";
            return find_impl(current->left, value);
        }

        // value 값이 현재 노드 오른쪽에 있는 경우
        cout << current->data << "에서 오른쪽으로 이동: ";
        return find_impl(current->right, value);
    }
    // 원소검색은 재귀적으로 동작하므로 실제 구현은 findImpl() 함수에 따로 작성
    // private 으로 지정하여 외부에서 직접 호출 할 수 없도록 지정

    void insert_impl(node* current, int value) {

        if(value < current->data) {
            if(!current->left)
                current->left = new node {value, NULL, NULL};
            else
                insert_impl(current->left, value);
        }
        else{
            if(!current->right)
                current->right = new node {value, NULL, NULL};
            else
                insert_impl(current->right, value);
        }

    }

    void inorder_impl(node* start) {
        if(!start)
            return;
        inorder_impl(start->left); // 왼쪽 서브 트리 방문
        cout << start->data << " "; // 현재 노드 출력
        inorder_impl(start->right); // 오른쪽 서브 트리 방문
    }

    node *delete_impl(node *start, int value) {
        if(!start)
            return NULL;

        if(value < start->data)
            start->left = delete_impl(start->left, value);
        else if (value > start->data)
            start->right = delete_impl(start->right, value);
        else{
            if(!start->left) // 자식 노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우
            {
                auto tmp = start->right;
                delete start;
                return tmp;
            }

            if(!start->right) // 오른쪽 자식 노드만 없는 경우
            {
                auto tmp = start->left;
                delete start;
                return tmp;
            }

            // 자식 노드가 둘 다 있는 경우
            auto succNode = successor(start);
            start->data = succNode->data;

            // 오른쪽 서브 트리에서 후속(successor)을 찾아 삭제
            start->right = delete_impl(start->right, succNode->data);

        }

        return start;
    }

public:
    void insert(int value) {
        if(!root)
            root = new node {value, NULL, NULL};
        else
            insert_impl(root, value);
    }

    void inorder(){
        inorder_impl(root);
    }

    // 후손 노드 찾는 함수
    node* successor(node* start) {
        auto current = start->right;
        while(current && current->left)
            current= current->left;
        return current;
    }

    // 특정 노드를 삭제후, 해해당 노드의 부모 노드 포인터를 조정해주는 함수

    void deleteValue(int value) {
        root = delete_impl(root,value);
    }

};


int main() {
    bst tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    cout << "중위 순회: ";
    tree.inorder(); // BST의 모든 원소를 오름차순으로 출력
    cout << '\n';

    tree.deleteValue(12);
    cout << "12를 삭제한 후 중위 순회: ";
    tree.inorder(); // BST의 모든 원소를 오름차순으로 출력
    cout << "\n";

    if(tree.find(12))
        cout << "원소 12는 트리에 있습니다." << "\n";
    else
        cout << "원소 12는 트리에 없습니다." << "\n";


    return 0;
}
