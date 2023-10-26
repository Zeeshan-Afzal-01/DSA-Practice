// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Practice{
    public:
    Practice(){
        arr=nullptr;
        size=0;
    }

    void create(){
         arr=new int[1];
         size=1;
    }
    void insert(int value){
        if(arr==nullptr){
            create();
        }
        else{
            int *temp=new int[size+1];
            for(int i=0;i<size;i++)
            {
                temp[i]=arr[i];
            }
            temp[size]=value;
            delete []arr;
            arr=temp;
            size++;
        }
    }
       
     void display(){
        
         for(int i=0;i<size;i++)
         {
             cout<<arr[i]<<endl;
         }
     
        
    }
    private:
    int *arr;
    int size;

};
int main() {
int value;

Practice p1;
p1.create();
do {
    cout<<"Enter you value , or -1 to stop: ";
    cin>>value;
    if(value!=-1){
        p1.insert(value);
    }
}while(value!=-1);
p1.display();



    return 0;
}