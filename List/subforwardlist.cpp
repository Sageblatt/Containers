#include <iostream>

using namespace std;

struct subforwardlist{
    int data;
    subforwardlist* next;
};

//Prototypes
bool init(subforwardlist ** sfl2);//
bool push_back(subforwardlist ** sfl2, int d);//
int pop_back(subforwardlist ** sfl2);//
bool push_forward(subforwardlist ** sfl, int d);//
int pop_forward(subforwardlist ** sfl);//
bool push_where(subforwardlist ** sfl2, unsigned int where, int d);//
bool erase_where(subforwardlist ** sfl2, unsigned int where);//
unsigned int size(subforwardlist ** sfl2);//
void clear(subforwardlist ** sfl2);
//End
subforwardlist * motion(subforwardlist * sfl){
    return sfl->next;
}

bool init(subforwardlist ** sfl2){
    *sfl2 = nullptr;
    cout << "INIT SUCCESS" << endl;
    return 0;
}

bool push_back(subforwardlist ** sfl2, int d){
    subforwardlist * sfl = *sfl2;
    if(*sfl2 == nullptr){
        sfl = new subforwardlist;
        sfl->data = d;
        sfl->next = nullptr;
        *sfl2 = sfl;
        return 1;
    }
    subforwardlist * a = sfl;
    while(a->next != nullptr){
        a = motion(a);
    }
    subforwardlist * b = new subforwardlist;
    a->next = b;
    b->data = d;
    b->next = nullptr;
    return 1;
}

int pop_back(subforwardlist ** sfl2){
    subforwardlist * sfl = *sfl2;
    if(*sfl2 == nullptr){
        cout << endl << "ERROR: EMPTY LIST CANNOT POP_BACK" << endl;
        return 1;
    }
    if(sfl->next == nullptr){
        int r = sfl->data;
        delete *sfl2;
        *sfl2 = nullptr;
        return r;
    }
    subforwardlist * a = sfl;
    subforwardlist * last;
    while(a->next->next != nullptr){
        a = motion(a);
    }
    last = a->next;
    int etr = last->data;
    a->next = nullptr;
    delete last;
    return etr;
}

bool push_forward(subforwardlist ** sfl, int d){
    subforwardlist * oldone = *sfl;
    if(oldone == nullptr){
        oldone = new subforwardlist;
        oldone->data = d;
        oldone->next = nullptr;
        *sfl = oldone;
        return 1;
    }
    subforwardlist * newone = new subforwardlist;
    newone->data = d;
    newone->next = *sfl;
    *sfl = newone;
    return 1;
}

int pop_forward(subforwardlist ** sfl){
    subforwardlist * oldone = *sfl;
    if(*sfl == nullptr){
        cout << endl << "ERROR: EMPTY LIST CANNOT POP_FORWARD" << endl;
        return 0;
    }
    if(oldone->next == nullptr){
        int r = oldone->data;
        delete oldone;
        *sfl = nullptr;
        return r;
    }
    subforwardlist * newstart = oldone->next;
    int output = oldone->data;
    *sfl = newstart;
    delete oldone;
    return output;
}

bool push_where(subforwardlist ** sfl2, unsigned int where, int d){
    subforwardlist * start = *sfl2;
    if(start == nullptr && where != 0){
        cout << endl << "WARNING: EMPTY LIST, VALUE HAS BEEN PUT IN THE FIRST PLACE" << endl;
        push_back(sfl2, d);
        return 0;
    }
    if(start == nullptr && where == 0){
        push_back(sfl2, d);
        return 0;
    }
    if(where == 0){
        push_forward(sfl2, d);
        return 1;
    }
    for(int i = 0; i != where-1; i++){
        if(start->next != nullptr){
            start = motion(start);
        }
        else{
            cout << endl << "WARNING: REACHED THE END OF THE LIST, VALUE HAS BEEN PUT IN THE " << i+1 << " PLACE" << endl;
            push_back(&start, d);
            return 0;
        }
    }
    subforwardlist * nextone = start->next;
    subforwardlist * b = new subforwardlist;
    b->data = d;
    b->next = nextone;
    start->next = b;
    return 1;
}

bool erase_where(subforwardlist ** sfl2, unsigned int where){
    subforwardlist * impostor = *sfl2;
    subforwardlist * novice = *sfl2;
    subforwardlist * sfl = *sfl2;
    if(sfl == nullptr){
        cout << "ERROR: EMPTY LIST" << endl;
        return 0;
    }
    if(sfl->next == nullptr && where != 0){
        cout << "ERROR: " << where << " PLACE DOESN'T EXIST IN THIS LIST" << endl;
        return 0;
    }
    if(sfl->next == nullptr && where == 0){
        sfl->next = sfl;
        return 1;
    }
    if(where == 0){
        pop_forward(sfl2);
        return 1;
    }
    for(int i = 0; i != where; i++){
        if(impostor->next != nullptr){
            impostor = motion(impostor);
        }
        else{
            cout << "ERROR: " << where << " PLACE DOESN'T EXIST IN THIS LIST" << endl;
            return 0;
        }
        if(i < where - 1){
            novice = motion(novice);
        }
    }
    novice->next = impostor->next;
    delete impostor;
    return 1;
}

unsigned int size(subforwardlist ** sfl2){
    subforwardlist * sfl = *sfl2;
    int i = 1;
    subforwardlist * a = sfl;
    if(a == nullptr){
        return 0;
    }
    while(a->next != nullptr){
        a = motion(a);
        i++;
    }
    return i;
}

void clear(subforwardlist ** sfl2){
    subforwardlist * sfl = *sfl2;
    unsigned int d = size(&sfl);
    for(int i = 0; i < d; i++){
        pop_back(&sfl);
    }
    //delete *sfl2;
    *sfl2 = nullptr;
}
