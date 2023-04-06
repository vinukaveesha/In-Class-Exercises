#include <iostream>
#include<chrono>
#include<ctime>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack(){
        top = nullptr;
    }

    void Push(int x){
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }


    void Pop(){
        if (top==nullptr){
            cout<< "Stack is underflow!"<<endl;
            }
        int pop_value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        }

    bool isEmpty(){
        return (top == nullptr);
    }
    void Display(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
        }
        else{
            Node* currentNode = top;
            while(currentNode != nullptr){
                cout<<currentNode->data<<" ";
                currentNode = currentNode->next;
            }
        }
        cout<<endl;
   }
   int StackTop(){
       if(isEmpty()){
        cout<<"Stack is empty."<<endl;
        return -1;
       }
       else{
        return top->data;
       }
   }

};
int main()
{
    Stack my_stack;
    auto start_time = chrono::high_resolution_clock::now();
    for (int i=0;i<5;i++){
    my_stack.Push(5);
	my_stack.Push(8);
	my_stack.Push(10);
	my_stack.Push(19);
	my_stack.Push(23);
	my_stack.Push(4);
	my_stack.Push(78);
	my_stack.Display();
	my_stack.Push(11);
	my_stack.Push(39);
	my_stack.Push(65);
	my_stack.Push(31);
	my_stack.Push(89);
	my_stack.Push(55);
    my_stack.Pop();
    my_stack.Pop();
    my_stack.Pop();
    my_stack.Display();
    my_stack.Pop();
    my_stack.Pop();
    my_stack.Pop();
    my_stack.Push(45);
	my_stack.Push(131);
	my_stack.Display();
	my_stack.Push(65);
	my_stack.Push(101);
	my_stack.Push(89);
	my_stack.Push(85);
	my_stack.Push(94);
	my_stack.Push(25);
	my_stack.Pop();
    my_stack.Pop();
    my_stack.Pop();
    my_stack.Display();
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end_time-start_time);
    cout<<"\nElapsed time: "<<elapsed_time.count()<<" ms"<<endl;
    return 0;
}
