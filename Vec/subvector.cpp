struct subvector {
    int *mas;
    unsigned int top;
    unsigned int capacity;
};

//Prototypes
bool init(subvector *qv);//
bool push_back(subvector *qv, int d);//
int pop_back(subvector *qv);//
bool resize(subvector *qv, unsigned int new_capacity);//
void shrink_to_fit(subvector *qv);//
void clear(subvector *qv);//
void destructor(subvector *qv);
//

bool init(subvector *qv){
    qv->capacity = 2000;
    qv->top = 0;
    qv->mas = new int[qv->capacity];
    return 1;
}

bool push_back(subvector *qv, int d){
    if((qv->top) == qv->capacity){
        unsigned int b = qv->capacity + 100;
        resize(qv, b);
    }
    qv->mas[qv->top] = d;
    qv->top++;
    return 1;
}

bool resize(subvector *qv, unsigned int new_capacity){
    if(new_capacity <= qv->capacity){
        return 0;
    }
    unsigned int *a = &(qv->capacity);
    int oldc = *a;
    *a = new_capacity;
    int *b = new int[*a];
    int i = 0;
    while(i < oldc){
        b[i]=qv->mas[i];
        i++;
    }
    delete[] qv->mas;
    qv->mas = b;
    return 1;
}

int pop_back(subvector *qv){
    if(qv->top > 0){
        qv->top--;
        return qv->mas[qv->top];
    }
    else{
        return 0;
    }
}

void shrink_to_fit(subvector *qv){
    int * b = new int[qv->top];
    for(int i = 0; i < qv->top; i++){
        b[i] = qv->mas[i];
    }
    delete[] qv->mas;
    qv->mas = b;
    qv->capacity = qv->top;
}

void clear(subvector *qv){
    qv->top = 0;
}

void destructor(subvector *qv){
    delete[] qv->mas;
    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;
}
