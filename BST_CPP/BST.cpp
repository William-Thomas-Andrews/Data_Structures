#include <iostream>
#include <vector>




class Optimal_BST
{
    private:

        class Node
        {
                
            public:

                int value;
                Node* right;
                Node* left;
                
                Node(int value) : value(value), left(nullptr), right(nullptr) {}

                ~Node()
                {
                    delete left;
                    delete right;
                }
        };

        Node* root;

        int size;

        Node* rec_insert(int value, Node* node)
        {
            if (node == nullptr)
            {
                return new Node(value);
            }
            else
            {
                if (value > node->value)
                {
                    node->right = rec_insert(value, node->right);
                }
                else if (value <= node->value)
                {
                    node->left = rec_insert(value, node->left);
                }
            }
            return node;
        }

        void rec_inorderTraversal(Node*node)
        {
            if (node == nullptr)
            {
                return;
            }

            rec_inorderTraversal(node->left);

            std::cout << node->value << std::endl;

            rec_inorderTraversal(node->right);
        }

        void rec_preorderTraversal(Node*node)
        {
            if (node == nullptr)
            {
                return;
            }

            std::cout << node->value << std::endl;

            rec_preorderTraversal(node->left);

            rec_preorderTraversal(node->right);
        }

        void rec_postorderTraversal(Node*node)
        {
            if (node == nullptr)
            {
                return;
            }

            rec_postorderTraversal(node->left);

            rec_postorderTraversal(node->right);

            std::cout << node->value << std::endl;
        }

        Node* rec_remove_search(Node* node)
        {
            while (node->left != nullptr)
            {
                node = node->left;
            }
            return node;
        }

        Node* rec_remove(int value, Node* node)
        {

            if (node == nullptr)
            {
                return node;
            }
            if (node->value > value)
            {
                node->left = rec_remove(value, node->left);
            }
            else if (node->value < value)
            {
                node->right = rec_remove(value, node->right);
            }
            else
            {
                if (node->left == nullptr)
                {
                    return node->right;
                }
                if (node->right == nullptr)
                {
                    return node->left;
                }

                Node* successor = rec_remove_search(node->right);
                node->value = successor->value;
                node->right = rec_remove(successor->value, node->right);
                size--;
            }
            return node;
        }


    public:

        Optimal_BST() : root(nullptr), size(0) {}

        ~Optimal_BST()
        {
            delete root;
        }
        

        void insert(int value)
        {
            if (size == 0)
            {
                root = new Node(value);
                size = 1;
            }
            else
            {
                if (value > root->value)
                {
                    root->right = rec_insert(value, root->right);
                }
                else
                {
                    root->left = rec_insert(value, root->left);
                }
            }
            size++;
        }

        void inorderTraversal()
        {
            if (root == nullptr)
            {
                return;
            }
            if (size == 1)
            {
                std::cout << root->value << std::endl;
                return;
            }
            else
            {
                rec_inorderTraversal(root);
            }
        }

        void preorderTraversal()
        {
            if (root == nullptr)
            {
                return;
            }
            if (size == 1)
            {
                std::cout << root->value << std::endl;
                return;
            }
            else
            {
                rec_preorderTraversal(root);
            }
        }

        void postorderTraversal()
        {
            if (root == nullptr)
            {
                return;
            }
            if (size == 1)
            {
                std::cout << root->value << std::endl;
                return;
            }
            else
            {
                rec_postorderTraversal(root);
            }
        }

        void remove(int value)
        {
            root = rec_remove(value, root);
        }


};


int main()
{

    Optimal_BST bst = Optimal_BST();

    bst.insert(10);
    bst.insert(20);
    bst.insert(3);
    bst.insert(5);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    // bst.inorderTraversal();
    // bst.preorderTraversal();
    bst.remove(3);
    bst.inorderTraversal();
    // bst.preorderTraversal();
}