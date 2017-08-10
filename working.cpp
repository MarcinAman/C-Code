#include <iostream>

using namespace std;

//check if brackets are correct:

bool isCorrect(string a){
    int count = 0;
    for(int i=0;i<a.length();i++){
        if(a[i]=='{') count++;
        else if(a[i]=='}') count --;

        if(count<0) return false;
    }
    if(count==0) return true;
    return false;
}

//driver function for this program:

void _isCorrect(){
    string a = "{{{}}}}{";
    string b= "{{{}}}";
    string c = "{{{}}}{";
    cout << isCorrect(a) << endl;
    cout << isCorrect(b) << endl;
    cout << isCorrect(c) << endl;
}

//We are given a linked list. Check whether it is not looped;

struct node{
    int val;
    node *next;
};

bool isLooped(node *root){
    if(root==NULL || root->next==NULL) return false;
    node *first = root, *second = root->next;
    while(first!=second && second!=NULL){
        first=first->next;
        if(second->next==NULL) return false;
        second =second->next->next;
    }
    if(first==second) return true;
    return false;
}

void _isLooped(){
    node *first=new node;
    node *root = first,*second;
    first->val = rand()%10+1;
    for(int i=0;i<10;i++){
        second = new node;
        first->next =second;
        second->val = rand()%10+1;
        first=first->next;
        cout << second->val << " ";
        second->next=NULL;
    }
    cout << endl;
    cout << isLooped(root) << endl;
    first->next = root;
    cout << isLooped(root) << endl;
}

//Rotate k last elements of a given array without additional space

void rotateArray(int *arr, int n, int k){
    cout << "Before swaping: "<< endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    //reverse array
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
    //swap k elements back to normal order
    for(int i=0;i<k/2;i++){
        swap(arr[i],arr[k-1-i]);
    }
    //swap other elements
    int j = 1;
    for(int i=k;i<=n/2;i++){
        swap(arr[i],arr[n-j++]);
    }

    cout << endl << "After swaping " << k << " elements:" << endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }    
    cout << endl;
}

void _rotateArray(){
    int n = 10;
    int *arr = new int[n];
    for(int i=0;i<n;i++) arr[i] = rand()%20+1;
    rotateArray(arr,n,4);
    delete(arr);
}

const int MAX_SIZE = 100;

struct queueEl{
    int priority, value;
    bool operator==(const queueEl& a)const
    {
        return (priority==a.priority && value==a.value);
    }
};

class priorityQueue{
    public: queueEl *arr;
    int sizeUsed;
    public: queueEl min,max;

    priorityQueue(){
        arr=new queueEl[MAX_SIZE];
        for(int i=0;i<MAX_SIZE;i++){
            arr[i].priority = -1; //special value to select taken positions
        min.priority=MAX_SIZE;
        min.value=-1,max.value=-1;
        max.priority=0;
        sizeUsed = 0;
        }

    }
    ~priorityQueue(){
        delete(arr);
    }
    bool isEmpty();
    void insert(int,int);
    int getMaxVal();
    int getMinVal();
    void deleteElement(queueEl);
    void deleteFunction(queueEl,int);
    void printArray();
    queueEl getNewMin();
    queueEl getNewMax();

};
void priorityQueue::printArray(){
    for(int i=0;i<MAX_SIZE;i++){
        if(arr[i].priority!=-1){
            cout << arr[i].value << " ";
        }
    }
    cout << endl;
}

bool priorityQueue::isEmpty(){
    return sizeUsed==0;
}

void priorityQueue::insert(int priority, int val){
    queueEl ins;
    ins.priority = priority;
    ins.value=val;
    if(ins.priority>max.priority) max=ins;
    else if(ins.priority<min.priority) min = ins;
    int ind =0;
    while(arr[ind].priority!=-1){
        if(arr[ind].priority>ins.priority){
            ind = 2*ind+1;
        }
        else{
            ind = 2*ind+2;
        }
    }
    arr[ind]=ins;
    sizeUsed++;
}


int priorityQueue::getMaxVal(){
    return max.value;
}

int priorityQueue::getMinVal(){
    return min.value;
}

void priorityQueue::deleteFunction(queueEl removed,int ind){
    if(arr[2*ind+2].priority==-1&& arr[2*ind+1].priority==-1) return;
    if(arr[2*ind+2].priority!=-1 && arr[2*ind+1].priority!=-1){
        swap(arr[ind],arr[2*ind+2]);
        deleteFunction(arr[2*ind+2],2*ind+2);
    }
    else if(arr[2*ind+2].priority!=-1){
        swap(arr[ind],arr[2*ind+2]);
        deleteFunction(arr[2*ind+2],2*ind+2);
    }
    else{
        swap(arr[ind],arr[2*ind+1]);
        deleteFunction(arr[2*ind+1],2*ind+1);
    }
}

queueEl priorityQueue::getNewMin(){
    queueEl min = arr[0];
    for(int i=0;i<MAX_SIZE;i++){
        if(arr[i].priority!=-1 && arr[i].priority<min.priority) min=arr[i];
    }
    return min;
}

queueEl priorityQueue::getNewMax(){
    queueEl max = arr[0];
    for(int i=0;i<MAX_SIZE;i++){
        if(arr[i].priority!=-1 && arr[i].priority>max.priority) max=arr[i];
    }
    return max;
}

void priorityQueue::deleteElement(queueEl removed){
    int ind = 0;
    while(!(removed==arr[ind])) ind++;
     if(removed==min) {
        arr[ind].priority=-1;
        arr[ind].value=-1;
        min = getNewMin();
    }
    if(removed==max){
        arr[ind].priority=-1;
        arr[ind].value=-1;
        max=getNewMax();
    }
    sizeUsed--;
    arr[ind].priority=-1;
    arr[ind].value=-1;
    deleteFunction(arr[ind],ind);
}

int main(){
    priorityQueue A;
    cout << A.isEmpty() << endl;
    A.insert(3,3);
    A.insert(2,2);
    A.insert(1,1);
    A.printArray();
    cout << A.getMinVal() << endl;
    cout << A.getMaxVal() << endl;
    A.deleteElement(A.arr[1]);
    A.deleteElement(A.arr[0]);
    cout << "MIN= " << A.getMinVal() << endl;
    cout << "MAX= " << A.getMaxVal() << endl;
    A.deleteElement(A.arr[2]);
    A.printArray();
    
    //_isLooped();
    //_isCorrect();
    //_rotateArray();
    return 0;

}
