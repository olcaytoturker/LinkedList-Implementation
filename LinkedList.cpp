#include "LinkedList.h"

LinkedList::LinkedList() {

    this->length=0;
    this->head=NULL;
    this->tail=NULL;

}

LinkedList::LinkedList(const LinkedList& list) { //copy const


    this->length = list.length;

    if(list.head) {

        this->head=new Node(*(list.head));

    }
    Node *temp = this->head;
    if(list.tail) {
        while(temp) {
            temp = temp->next;
        }

        this->tail=temp;

    }

}

LinkedList& LinkedList::operator=(const LinkedList& list) {	//assignment op

    this->length = list.length;

    if(list.head) {

        delete this->head;
        this->head=new Node(*(list.head));

    } if(list.tail) {

        delete this->tail;
        this->tail=new Node(*(list.tail));

    }


    return *this;

}

LinkedList::LinkedList(LinkedList&& list){    	//move const

    this->length=move(list.length);

    if(list.head) {

        delete this->head;
        this->head=move((list.head));

    } if(list.tail) {

        delete this->tail;
        this->tail=move((list.tail));

    }

    list.head=nullptr;
    list.tail=nullptr;
    list.length=0;
}

LinkedList& LinkedList:: operator=(LinkedList&& list){	 //move assign

    this->length=move(list.length);
    if(list.head) {

        delete this->head;
        this->head=move((list.head));

    } if(list.tail) {

        delete this->tail;
        this->tail=move((list.tail));

    }

    list.head=nullptr;
    list.tail=nullptr;
    list.length=0;

    return *this;


}

// add a new element to the back of LinkedList
void LinkedList::pushTail(string _name, float _amount) {

    Node *newNode=new Node(_name,_amount);

    if (length==0){

        this->head=newNode;
        this->tail=newNode;

    }  else {

        this->tail->next=newNode;
        this->tail=this->tail->next;

    }

    this->length++;

}

// update an existing element
void LinkedList::updateNode(string _name, float _amount) {

    Node* temp=this->head;

    while(temp!=NULL){


        if(temp->name==_name){

            temp->amount=_amount;
            return;
        }
        temp=temp->next;

    }
}

LinkedList::~LinkedList() {  //destructor

    delete this->head;

}
