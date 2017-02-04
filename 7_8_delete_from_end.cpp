#include <iostream>
using namespace std;

template <class T>
class LinkedList{
    struct node{
        T x;
        node *next;
    };
    public:
    LinkedList(){
        head = NULL;
        curr = NULL;
    }
    node* getHead(){
        return head;
    }
    node* getCurrent(){
        return curr;
    }
    void addNode(struct node* b){
        b->next = head;
        head = b;
        if(curr == NULL)
            curr = head;
    }
    void addValue(T a){
        node *n = new node;
        n->x = a;
        n->next = head;
        head = n;
        if(curr == NULL)
            curr = head;
    }
    void rewind(){
        curr = head;
    }
    void next(){
        if( curr != NULL )
            curr = curr->next;
    }
    int getValue(){
        if( curr != NULL )
            return curr->x;
        return 0;
    }
    int hasValue(){
        return ( curr != NULL ? true : false );
    }
    void deleteFromEnd(int k){
        rewind();
        node *temp;
        temp = head;
        if(k>0)
            {
            while(k-1)
                {
                next();
                k--;
            }
            while(curr->next->next!=NULL)
                {
                temp = temp->next;
                next();
            }
            if(temp==curr)
                temp->next = NULL;
            else
                temp->next = temp->next->next;
            rewind();
        }
    }

    private:
    node *head;
    node *curr;
};



int main(){
    LinkedList<int> L;
    L.addValue(12);
    L.addValue(11);
    L.addValue(10);
    L.addValue(9);
    L.addValue(8);
    L.addValue(7);
    L.addValue(6);
    L.addValue(5);
    L.addValue(4);
    L.addValue(3);
    L.addValue(2);
    L.addValue(1);
    L.addValue(0);
    L.rewind();
    while(L.hasValue())
        {
        cout << "BEFORE----Value: " << L.getValue();
        if(L.getValue()/10 < 1)
            cout << " ";
        cout << "  Pointer: " << L.getCurrent() << endl;
        L.next();
    }
    cout << "\n----------------------------------------------------\n" << endl;

    L.deleteFromEnd(3);
    while(L.hasValue())
        {
        cout << "AFTER-----Value: " << L.getValue();
        if(L.getValue()/10 < 1)
            cout << " ";
        cout << "  Pointer: " << L.getCurrent() << endl;
        L.next();
    }
    return 0;
}
