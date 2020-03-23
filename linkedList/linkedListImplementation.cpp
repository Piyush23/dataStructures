#include "iostream"
using namespace std;

template <class T>
class Node { 
    public:
        T data;
        Node* next;
};

template <class T>
class LinkedListClass{
    private:
        int size;
        Node<T>* root;

    public:
        LinkedListClass(){
            size = 0;
            root = NULL;
        }

        int getSize(){
            return size;
        }

        Node<T>* getRoot(){
            return root;
        }

        //new element becomes the root
        void insert(T data){
            if(root == NULL){
                root = new Node<T>();
                root->next = NULL;
                root->data = data;
            }
            else{
                Node<T>* temp = new Node<T>();
                temp->next = root;
                temp->data = data;
                root = temp;
                temp = NULL;
                delete temp;
            }
            size++;
        }

        void remove(T data){
            if(root == NULL)
                return;
            Node<T>* temp = root;
            if(root->data == data){
                root = root->next;
                temp = NULL;
                delete temp;
                size--;
                return;
            }
            Node<T>* prev = root;
            temp = temp->next;
            while(temp!= NULL){
                if(temp->data == data){
                    prev->next = temp->next;
                    temp = NULL;
                    delete temp;
                    size--;
                    return;
                }
                prev=temp;
                temp=temp->next;
            }
            prev = NULL;
            temp = NULL;
            delete prev;
            delete temp;
        }

        bool find(T data){
            if(root == NULL)
                return false;
            Node<T>* temp = root;
            if(root->data == data){
                return true;
            }
            while(temp!= NULL){
                if(temp->data == data){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }

        void display(){
            Node<T>* temp = root;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
            delete temp;
        }
};

//testing linked list implementation
int main(){
    //int
    LinkedListClass<int> ll_int;
    ll_int.insert(2);
    ll_int.insert(5);
    ll_int.display();
    ll_int.remove(2);
    ll_int.display();
    ll_int.remove(2);
    ll_int.display();
    cout<<ll_int.find(2)<<endl;
    cout<<ll_int.find(5)<<endl;

    //string
    LinkedListClass<string> ll_string;
    ll_string.insert("one");
    ll_string.insert("two");
    ll_string.display();
    ll_string.remove("two");
    ll_string.display();
    ll_string.remove("two");
    ll_string.display();
    cout<<ll_string.find("one")<<endl;
    cout<<ll_string.find("two")<<endl;
    return 0;
}