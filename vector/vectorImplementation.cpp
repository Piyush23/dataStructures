#include "iostream"
using namespace std;
template <class T>
class VectorClass{
    private:
        T* arr;
        int capacity;
        int size;

    public:
        VectorClass(){
            arr = new T[2];
            capacity=1;
            size=0;
        }

        int get_size(){
            return size;
        }

        int get_capacity(){
            return capacity;
        }

        bool empty(){
            if(size == 0)
                return true;
            else
                return false;
        }

        T* get_vec(){
            return arr;
        }

        void push_back(T data){
            //check if vector should be expanded
            if(2 * size >= capacity){
                T* temp = new T[2*capacity];

            //copy vector data from old to new
            for(int i=0; i<size;i++){
                temp[i] = arr[i];
            }

            //delete old vector
            delete [] arr;
            capacity *=2;
            arr=temp;
            }
            
            //insert current data
            arr[size] = data;
            size++;
        }

        void pop_back(){
            if(size>0){
                size--;
            }
        }

        void erase(){
            size=0;
        }

        void reverse(){
            T* temp = new T[capacity];
            
            //reverse the elements
            for(int i=0; i<size;i++){
                temp[i] = arr[(size-1)-i];
            }

            delete [] arr;
            arr = temp;
        }

        void display(){
            for(int i=0; i<size;i++){
                cout<<arr[i]<<endl; 
            }
        }
};

//Program to test the vector implementation

int main(){
    //int
    VectorClass<int> v_int;
    v_int.push_back(3);
    v_int.push_back(5);
    v_int.display();
    v_int.pop_back();
    v_int.display();

    //string
    VectorClass<string> v_string;
    v_string.push_back("one");
    v_string.push_back("two");
    v_string.display();
    v_string.pop_back();
    v_string.display();

    return 0;
}