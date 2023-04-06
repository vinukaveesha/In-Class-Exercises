#include <iostream>
#include<ctime>
#include <cstdlib>
#include<chrono>

using namespace std;

const int arr_size=100;


class Stack{
    int stack_arr[arr_size];
    int top;

public:
    Stack(){
    top = -1;
    }


void Push(int x){
    top++;
    if (top > arr_size){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        stack_arr[top] = x;
    }
}
bool isEmpty(){
    if(top<0){
        return true;
    }
    else{
        return false;
    }
}
int Pop(){
    if (isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else{
        return(stack_arr[top--]);
    }

}
void StackTop(){
    if(top<0){
        cout<<"Stack is empty."<<endl;
    }
    else{cout<<stack_arr[top]<<endl;
    }

}

void isFull(int arr[],int arr_size){
    if(top>=arr_size){
        cout<<"Stack is full."<<endl;
    }
    else{
        cout<<"Stack is not full."<<endl;
    }
}

void Display() {
    if (isEmpty()) {
        cout << "Stack is empty" << std::endl;
    }
    else {
        for (int i = 0; i <= top; i++) {
            cout << stack_arr[i] << " ";
            }
            cout <<endl;
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
