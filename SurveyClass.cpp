#include "SurveyClass.h"

SurveyClass::SurveyClass() {	//const

    this->members=new LinkedList();
}


SurveyClass::SurveyClass(const SurveyClass& other) { //copy const

    this->members = new LinkedList(*(other.members));
}

SurveyClass& SurveyClass::operator=(const SurveyClass& list) {	//oopy assign

    delete this->members;

    this->members = new LinkedList(*(list.members));

    return *this;
}

SurveyClass::SurveyClass(SurveyClass&& other) {		//move const

    this->members=move(other.members);

    other.members=NULL;

}


SurveyClass& SurveyClass:: operator=(SurveyClass&& list) { //move assign

    delete this->members;

    this->members=move(list.members);

    return *this;

}


SurveyClass::~SurveyClass() {

    delete this->members;

}

void SurveyClass::handleNewRecord(string _name, float _amount) {

    Node* temp=this->members->head;

    while(temp){

        if(temp->name==_name){

            this->members->updateNode(_name, _amount);
            return;

        } else
        temp = temp->next;
    }
    this->members->pushTail(_name,_amount);

}

float SurveyClass::calculateMinimumExpense() {
    float min = members->head->amount;

    Node* temp = members->head;

    while(temp){

        if(temp->amount < min) {

            min=temp->amount;

        }

        temp=temp->next;

    }

    min=(int)(min * 100);
    min=(min/100.0);

    return min;

}

float SurveyClass::calculateMaximumExpense() {
    float max = members->head->amount ;

    Node* temp=this->members->head;

    while(temp){

        if(temp->amount > max) {

            max=temp->amount;

        }

        temp=temp->next;

    }

    max=(int)(max * 100);
    max=max/100.0;

    return max;

}

float SurveyClass::calculateAverageExpense() {
    float sum=0;
    float avg=0;

    Node* temp=this->members->head;

    while(temp != NULL) {

        sum+=temp->amount;
        temp=temp->next;
    }

    avg=sum/this->members->length;

    avg=(int)(avg * 100);
    avg=avg/100.0;

    return avg;

}
