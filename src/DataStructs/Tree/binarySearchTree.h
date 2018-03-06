
#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename T>
class binarySearchTree {
    class Node{
        Node(T val)
        : value {val}
        { };
       ~Node(){
            if(left != nullptr) delete left;
            if(right != nullptr) delete right;
        };
        void Insert(T& val){
            this->Insert(new Node(val));
        };
        void Insert(Node* & nNode){
            if(nNode == nullptr) return;

            if(nNode->value < value){
                if(left == nullptr){
                    left = nNode;
                }
                else{
                    left->Insert(nNode);
                }
            }
            else{
                if(right == nullptr){
                    right = nNode;
                }
                else{
                    right->Insert(nNode);
                }
            }
        };
        void Remove(T& val){
            if(left != nullptr){
                left->Remove(val);
                if(left->value == val){
                    Node* tmp = left;
                    left = tmp->right;
                    if(left == nullptr){
                        left = tmp->left;
                    }
                    else{
                        left->Insert(tmp->left);
                    }
                    delete tmp;
                }
            }
            if(right != nullptr){
                right->Remove(val);
                if(right->value == val){
                    Node* tmp = right;
                    right = tmp->left;
                    if(right == nullptr){
                        right = tmp->right;
                    }
                    else{
                        right->Insert(tmp->right);
                    }
                    delete tmp;
                }
            }
        };
        int NodeCount() const{
            return 1 + left == nullptr ? 0 : left->NodeCount() + right == nullptr ? 0 : right->NodeCount();
        };
        int Count(T& val){
            return value == val ? 1 : 0 + left == nullptr ? 0 : left->Count(val) + right == nullptr ? 0 : right->Count(val);
        };
        T value;
        Node* right {nullptr};
        Node* left {nullptr};
    };
    public:
        binaryTree()
        : root {nullptr}
        { };
        ~binaryTree(){
            delete root;
        };
        void Insert(T key){
            if(root == nullptr){
                root = new Node(key);
                return;
            }
            root->Insert(key);
        };
        void Remove(T key){
            if(root == nullptr) return;
            root->Remove(key);
            if(root->value == key){
                if(root->right == nullptr){
                    root = root->left;
                    delete rot;
                }
                else{
                    Node* tmp = root;
                    root = root->right;
                    if(tmp->left != nullptr){
                        root->Insert(tmp->left);
                    }
                }
            }
        };
        int Count(){
            return root->NodeCount();
        };
        int Count(T key){
            return root->Count(key);
        };
    private:
        Node* root {nullptr};
};

#endif
