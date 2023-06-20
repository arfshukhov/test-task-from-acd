#include "iostream"

template <typename T, int Size>
class Stack{
    T * mas;
    size_t iter;
public:
    friend void get_all(Stack<int, 10> &s);
    Stack(){
        mas = new T[Size];
        iter = 0;
        for(size_t i = 0; i<Size; i++)
            mas[i] = NULL;
    }
    ~Stack(){
        delete [] mas;
    }
    bool add(T elem){
        if (iter < Size){
            mas[iter] = elem;
            iter++;
            return true;
        }
        else return false;
    };

    virtual T pop(){
        if (iter >= 0 && iter <= Size){
            T elem = mas[0];
            for( int i = 1; i <= iter; i ++){
                mas[i-1] = mas[i];
            }
            iter--;
            return  elem;
        }
        else return 0;
    };
};

template <typename T, int Size>
class Queue: Stack<T, Size>{
    size_t iter;
    T * mas;
public:
    friend void get_all(Queue<int, 10> &q);
    Queue(){
        iter = 0;
        mas = new T[Size];
    }
    ~Queue(){
        delete [] mas;
    }
    T pop() override{
        if (iter >=0 && iter <= Size){
            T elem = mas[iter];
            delete mas[iter];
            iter--;
            return elem;
        }
        else return 0;
    }


};


void get_all(Stack<int, 10> &s){
    for(int i = 0; i < 10; i++){
        std::cout<<s.mas[i]<< " ";
    }
    std::cout<<"\n";
}
void get_all(Queue<int, 10> &q){
    for(int i = 0; i < 10; i++){
        std::cout<<q.mas[i]<< " ";
    }
    std::cout<<"\n";
}

int main(){
    Stack<int, 10> stack;
    stack.add(1);
    stack.add(2);
    stack.add(3);
    get_all(stack);
    for(auto i = 0; i <3; i++)
        std::cout<<stack.pop()<<"\n";
    get_all(stack);
    for(int i = 0; i <12; i++)
        stack.add(i*i);
    get_all(stack);
}
