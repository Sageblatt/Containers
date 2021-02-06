#include <iostream>
using namespace std;

class subvector
{
public:
    subvector();//
    bool push_back(int d);//
    int pop_back();//
    bool resize(unsigned int new_capacity);//
    void shrink_to_fit();//
    void clear();//
    int sum();
    int capacity_check();
    int top_check();
    ~subvector();

private:
    int *mas;
    unsigned int top;
    unsigned int capacity;
};

subvector::subvector()
{
    this->capacity = 2000;
    this->top = 0;
    this->mas = new int[this->capacity];
}

bool subvector::resize(unsigned int new_capacity){
    if(new_capacity <= this->capacity){
        return 0;
    }
    unsigned int *a = &(this->capacity);
    int oldc = *a;
    *a = new_capacity;
    int *b = new int[*a];
    int i = 0;
    while(i < oldc){
        b[i]=this->mas[i];
        i++;
    }
    delete[] this->mas;
    this->mas = b;
    return 1;
}

bool subvector::push_back(int d)
{
    if((this->top) == this->capacity){
        unsigned int b = this->capacity + 100;//
        this->resize(b);
    }
    this->mas[this->top] = d;
    this->top++;
    return 1;
}

int subvector::pop_back(){
    if(this->top > 0){
        this->top--;
        return this->mas[this->top];
    }
    else{
        return 0;
    }
}

void subvector::shrink_to_fit(){
    int * b = new int[this->top];
    for(int i = 0; i < this->top; i++){
        b[i] = this->mas[i];
    }
    delete[] this->mas;
    this->mas = b;
    this->capacity = this->top;
}

void subvector::clear(){
    this->top = 0;
}

int subvector::sum()
{
    long long int s = 0;
    for(int i = 0; i < this->top; i++)
    {
        s += this->mas[i];
    }
    return s;
}

subvector::~subvector(){
    delete[] this->mas;
    this->mas = nullptr;
    this->top = 0;
    this->capacity = 0;
}

int subvector::capacity_check()
{
    return this->capacity;
}

int subvector::top_check()
{
    return this->top;
}

/*int main()
{
    subvector qwer;
    int i;
    for(i = 0; i <= 10; i++)
    {
        qwer.push_back(i);
    }
    cout << qwer.sum() <<  endl;
    cout << qwer.top_check() << endl;
    cout << qwer.capacity_check();
}*/

