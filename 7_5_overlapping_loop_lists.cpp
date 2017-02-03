#include <iostream>
using namespace std;

template <class T>
class LinkedList
    {
    struct node
        {
        T x;
        node *next;
    };
    public:
    LinkedList()
        {
        head = NULL;
        curr = NULL;
    }
    node* getHead()
        {
        return head;
    }
    node* getCurrent()
        {
        return curr;
    }
    void addNode(struct node* b)
        {
        b->next = head;
        head = b;
        if(curr == NULL)
            curr = head;
    }
    void addValue(T a)
        {
        node *n = new node;
        n->x = a;
        n->next = head;
        head = n;
        if(curr == NULL)
            curr = head;
    }
    void rewind()
        {
        curr = head;
    }
    void next()
        {
        if( curr != NULL )
            curr = curr->next;
    }
    int getValue()
        {
        if( curr != NULL )
            return curr->x;
        return 0;
    }
    int hasValue()
        {
        return ( curr != NULL ? true : false );
    }
    node* loopCheck()
        {
        node *a, *b;
        int i=1,j=0;
        a = head->next;
        b = head->next;
        b = b->next;
        while(b!=NULL && b->next!=NULL && b!=head && b->next!=head && a!=b)
            {
            a = a->next;
            b = b->next;
            if(b->next == NULL)
                break;
            else
                b = b->next;
        }
        if(b==NULL || b->next==NULL)
            return NULL;
        else if(b==head || b->next==head)
            {
            return head;
        }
        else
            {
            a = a->next;
            while(a!=b)
                {
                a = a->next;
                i++;
            }
            a = head;
            b = head;
            while(i>0)
                {
                b = b->next;
                i--;
            }
            while(a!=b)
                {
                a = a->next;
                b = b->next;
                j++;
            }
            return a;
        }
    }
    node* forkAndLoopCheck(struct node* b)
        {
        node *h1, *h2;
        h1 = this->loopCheck();
        head = b;
        h2 = this->loopCheck();
        if(h1 && h2)
            {
            node *temp;
            temp = h1->next;
            while(temp!=h2 && temp!=h1 && h1!=h2)
                temp = h1->next;
            if(h1==h2)
                curr = h1;
            else if(temp==h2)
                curr = temp;
            else
                curr = NULL;
        }
        else
            curr = NULL;
        return curr;
    }

    private:
    node *head;
    node *curr;
};



int main()
    {
    LinkedList<int> L, M;
    L.addValue(12);
    L.addValue(10);
    L.addValue(9);
    M.addValue(8);
    L.addNode(M.getHead());
    L.addNode(L.getCurrent());
    L.addValue(7);
    L.addValue(5);
    L.addValue(2);
    M.addValue(6);
    M.addValue(5);
    M.addValue(3);
    M.addValue(1);

    if(L.forkAndLoopCheck(M.getHead()))
        cout << "Value: " << L.getValue() << "\nPointer: " << L.getCurrent() << endl;
    else
        cout << "0" << endl;
    return 0;
}
