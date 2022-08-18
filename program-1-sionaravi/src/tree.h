//Siona Ravi
//CSCE 350 - Program 1

#ifndef TREE_H
#define TREE_H

template<typename T>
struct BST_Node {
T val;
BST_Node* left;
BST_Node* right;

BST_Node(T v) : val(v),left(NULL),right(NULL)
{}

void insert(T v) {
    if(v>val){
        if (right==NULL) right = new BST_Node<T>(v);
        else right->insert(v);
    }
    else{
        if (left==NULL) left = new BST_Node<T>(v);
        else left->insert(v);
    }
}

};

template<typename T>
void delete_tree(BST_Node<T>* root){
    if (root==NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

//your work starts here
template<typename T>
int num_nodes(BST_Node<T>* root){
    int start = 1;

    if (root->right) start += num_nodes(root->right);
    if (root->left) start += num_nodes(root->left);
    return start;
}


template<typename T>
bool has_duplicate_val(BST_Node<T>* root){
    std::vector<T> nums;
    countNums(root, nums);

    for(int i = 0; i<nums.size()-1; i++){
        for(int j = j+1; j<nums.size(); j++){
            if(nums.at(i)==nums.at(j))
            return true;
        }
    }
    return false;
}

template<typename T>
bool trees_identical(BST_Node<T>* a, BST_Node<T>* b){

    if(a==NULL && b==NULL) return true;
    else if (a && b && (a->val == b->val)){
        return trees_identical(a->right, b->right) && trees_identical(a->right, b->right);
    }
    else return false;
}
    if(a==NULL && b==NULL) return true;
    else if (a && b && (a->val == b->val)){
        return trees_identical(a->right, b->right) && trees_identical(a->right, b->right);
    }
    else return false;
}

#endif //TREE_H

