/*
Vitaliy Stepanov
CS300A Fall 2019
Professor Dr. Fatma Cemile Serce

A generic linked list implementation which stores a object 
*/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

// generic template
template <class T>
struct node{
    T data; 
    node<T> *next;
};

template <class T>
class LinkedList{
    private:
        node<T> *head, *last;
        int count;
    public:
        LinkedList(); //constructor
        LinkedList(const LinkedList<T>&); // copy constructor
        ~LinkedList(); // destructor

        void insertFirst(T); //insert to the front of the list
        void insertLast(T); //inserts to the end of the list
        void insertAtIndex(T, int); //insert an item to the given index
        void reverse(); // reverse linkedlist 
        void remove(T);   //removes an item from the list
        void destroy(); // deletes linkedlist
        int size() const;   //returns the number of items in the list
        void front();    //returns the item at the front of the list
        void nextSong();
        int lastItem();     //returns the last item in the list
        int search(T);    //searches for an item and returns the index
        int countItems(T item); // counts number of occurances of a given number
        int sum(); // returns total sum of all linkedlist numbers
        void printList(); // prints middle value of linkedlist
        int printMiddle(); // prints middle value of linkedlist
        bool isEmpty();    //returns true if it is empty, false otherwise

        LinkedList& operator=(const LinkedList&); // overrides operator 
        template <class A>
        friend ostream& operator<<(ostream& os, LinkedList<A>& list); //overload << operator so that cout<<list prints the list
};

// constructor
template <class T>
LinkedList<T>::LinkedList(){
    head = last = NULL;
    count = 0;
}

// copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) {
        node<T> *temp = other.head;
        while (temp != NULL) {
            insert_last(temp->data); // creates a copy of linkedlist
            temp = temp->next;
    }
}

// destructor
template <class T>
LinkedList<T>::~LinkedList(){
    destroy();
}

// inserts to the front of the list
template <class T>
void LinkedList<T>::insertFirst(T item){
    node<T> *newNode = new node<T>;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
    if(last==NULL)
        last = newNode;
    count++;
}

//inserts to the end of the list
template <class T>
void  LinkedList<T>::insertLast(T item){
    node<T> *newNode = new node<T>;
    newNode->data = item;
    newNode->next = NULL;
    if(head == NULL)
        head = last = newNode;
    else{
        last->next = newNode;
        last = newNode;
    }
    count++;
}

//insert an item to the given index
template <class T>
void LinkedList<T>::insertAtIndex(T item, int index){
    if(index>count || index<0) 
        return;
    if(index==0)
        insert_first(item);
    else if(index==count)
        insert_last(item);
    else{    
        node<T> *temp = head;
        while(index--){ // traverse to given index
            temp = temp->next;
        }
        node<T> *newNode = new node<T>; // creates node
        newNode->data = item;
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
    }
}

// creates new linkedlist in reverse order
template <class T>
void LinkedList<T>::reverse() {
    node<T> *temp = head;
    LinkedList<T> *reverse = new LinkedList<T>; // create another linkedlist to reverse it
    while (temp != NULL) {
        reverse->insert_first(temp->data); 
        temp = temp->next;
    }
    this->head = reverse->head;
    this->last = reverse->last;
    this->count = reverse->count;
}

//removes an item from the list
//CASE0: list is empty
//CASE1: remove the first item
//CASE2: remove the only item
//CASE3: remove the last item
//CASE4: remove the item in between
//CASE5: item not found
template <class T>
void LinkedList<T>::remove(T item){ // why does this have paramter?
    // this method only removes a specific item, how do i call to remove current item?
	if(isEmpty()) return;

    // how does this check title, artist AND duration???
	if(head->data == item){ //remove the first item
        node<T> *temp = head;
        head = head->next;
        if(head == NULL){ //remove the only item
            last = NULL;
        }
        delete temp;
        count--;
              
	}else{
		node<T> *prev= head;
		node<T> *current = head->next;
		while(current!=NULL && current->data!=item){ //search for an item
			prev = current;
            current = current->next;
        }
		if (current!=NULL){ //item is found 
			prev->next = current->next;
			if (current==last) //remove the last item
				last = prev;
			delete current;
			count--;
		}
        //returns if it is not found
    }
}  

// destroys linkedlist to free up memory
template <class T>
void LinkedList<T>::destroy() {
    node<T> *temp = head;
    while (head != NULL) {
        head = head->next;
        delete temp; // free up memory
        temp = head;
    }
    last->next = NULL;
    count = 0;
}

// returns the number of items in the list
template <class T>
int LinkedList<T>::size() const{
    return count;
}   

//returns the item at the front of the list
template <class T>
void LinkedList<T>::front(){
    cout << head->data;
}   

// deletes node so next song will be current song head
template <class T>
void LinkedList<T>::nextSong(){
    node<T> *temp = head;
    head = head->next;
    delete temp;
}


//returns the item at the back of the list
template <class T>
int LinkedList<T>::lastItem(){
    return last->data;
}  

//searches for an item and returns the index
template <class T>
int LinkedList<T>::search(T item){
  if(isEmpty()) return -1;
  node<T> *temp = head;
  int index = 0;
  while(temp!=NULL && temp->data!=item){//keep searching while there is more item and item is not found
    temp = temp->next;
    index++;
  }
  if(temp!=NULL) //item found
    return index;

  return -1; //item not found
}

template <class T>
int LinkedList<T>::countItems(T item){
    int count = 0;
    if(isEmpty()) {
        return count;
    }
    node<T> *temp = head;
    while(temp!=NULL){ // keep searching while there is more item and item is not found
        if (temp->data == item) {
            count++;
        }
    temp = temp->next;
    }
    return count;
 }

// returns sum of all linkedlist values
template <class T>
int LinkedList<T>::sum() {
    int sum = 0;
    node<T> *temp = head;
    while(temp != NULL) {
        sum += temp->data; // adds int value from data into sum variable
        temp = temp->next;
    }
    return sum;
}



// returns data of middle linkedlist 
template <class T>
int LinkedList<T>::printMiddle() {
    if(isEmpty()) {
        return -1;
    }
    node<T> *temp = head;
    for (int i = 0; i < size() / 2; i++) { // loops to middle of list
        temp = temp->next;
    }
    return temp->data;
}

//returns true if it is empy, false otherwise
template <class T>
bool LinkedList<T>::isEmpty(){
    return head == NULL;
}   

// assignmet operator
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this != &other) {
        destroy(); // reallocate memory
        node<T> *temp = other.head;
        while (temp != NULL) {
            insert_last(temp->data); // creates a copy of linkedlist
            temp = temp->next;
        }
    }
    return *this;
}

// prints linkedlist data
template <class T>
void LinkedList<T>::printList() {
    node<T> *temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
        cout << endl;
    }
    cout << endl;
}

//overload << operator so that cout<<list prints the list
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
    node<T>* temp = list.head;
    while(temp != NULL){
        os<<temp->data<<" ";
        temp = temp->next;
    }
    os<<endl;
    return os;
}
#endif

  














