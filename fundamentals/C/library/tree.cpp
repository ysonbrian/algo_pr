#include <bits/stdc++.h>

using namespace std;

struct node {
    string position;
    node* first;
    node* second;
};

struct org_tree{
    node* root; // 회사 CEO

    // 새로운 트리를 만드는 정적 함수
    static org_tree create_org_structure(const string&pos) {
        org_tree tree;
        tree.root = new node{pos, NULL, NULL};
        return tree;
    }

    static node* find(node* root, const string& value) {
        //루트 노드에 가서 왼쪽 서브 트리와 오른쪽 서브트리를 확인해보며 직책 이름에 해당하는 노드가 있는지 확인한다.
        if(root == NULL)
            return NULL;

        if(root->position == value)
            return root;

        auto firstFound = org_tree::find(root->first, value);

        if(firstFound != NULL)
            return firstFound;

        return org_tree::find(root->second, value);
    }

    bool addSubordinate(const string& manager, const string& subordinate)
    {
        auto managerNode = org_tree::find(root, manager);

        if(!managerNode){
            cout << manager <<"을 찾을 수 없습니다: "<< '\n';
            return false;
        }

        if(managerNode->first && managerNode->second){
            cout << manager << " 아래에 " << subordinate << "을 추가할 수 없습니다." << '\n';
            return false;
        }

        if(!managerNode->first)
            managerNode->first = new node{subordinate, NULL, NULL};
        else
            managerNode->second = new node{subordinate, NULL, NULL};

        cout << manager << " 아래에 " << subordinate << "을 추가했습니다." << '\n';

        return true;
    }

    static void preOrder(node* start) {
        if(!start)
            return;
        cout << start->position << ", ";
        preOrder(start->first);
        preOrder(start->second);
    }

    static void inOrder(node* start){
        if(!start)
            return;
        inOrder(start->first);
        cout << start->position << ", ";
        inOrder(start->second);
    }

    static void postOrder(node* start){
        if(!start)
            return;
        postOrder(start->first);
        postOrder(start->second);
        cout << start->position << ", ";
    }

    static void levelOrder(node* start)
    {
        if(!start)
            return;

        queue<node*> q;
        q.push(start);

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto current = q.front();
                q.pop();

                cout << current->position << ", ";
                if(current->first)
                    q.push(current->first);
                if(current->second)
                    q.push(current->second);
            }

            cout << "\n";
        }
    }
};


int main() {

    auto tree = org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀부장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무부장");

    org_tree::levelOrder(tree.root);

    return 0;
}
