#include <iostream>
#include <stack>
using namespace std;

template <class T>
class BinarySearchTree
{
    struct node
    {
        T key;
        node *left;
        node *right;
    };
    public:
    BinarySearchTree()
    {
        curr = NULL;
        top = NULL;
    }
    void addValue(T a)
    {
        curr = top;
        node *n = new node;
        n->key = a;
        if(curr)
            {
            while(curr)
                {
                if(a<=curr->key)
                    {
                    if(curr->left)
                        curr = curr->left;
                    else
                        {
                        curr->left = n;
                        break;
                    }
                }
                else
                    {
                    if(curr->right)
                        curr = curr->right;
                    else
                        {
                        curr->right = n;
                        break;
                    }
                }
            }
        }
        else
            top = n;
    }
    void printSorted()
        {
        curr = top;
        stack<node*> s;
        while(!s.empty() || curr)
            {
            if(curr)
                {
            	s.push(curr);
            	curr = curr->left;
            }
            else
                {
            	curr = s.top();
                s.pop();
                cout << curr->key << endl;
                curr = curr->right;
            }
        }
    }
    bool isEmpty()
    {
        return ( top != NULL ? false : true );
    }

    private:
    node *top;
    node *curr;
};



int main()
{
    BinarySearchTree<int> B;
    B.addValue(11);
    B.addValue(13);
    B.addValue(9);
    B.addValue(10);
    B.addValue(8);
    B.addValue(14);
    B.addValue(16);
    B.addValue(2);
    B.addValue(5);
    B.printSorted();
    return 0;
}
