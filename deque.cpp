#include <iostream>
#include "deque.h"

Deque::Deque(): size(0), capacity(initialCap), front((capacity-1)/2), rear((capacity-1)/2) {arr = new EType[capacity];}

void Deque::insertFront(const EType &value){
	checkFront();
	if(size == 0){
		if(front > rear){
		arr[((capacity-1)/2)-1] = value;
		front--;
		size++;
		} else {
			arr[(capacity-1)/2] = value;
			size++;
		}
	} else {
		arr[front-1] = value;
		front--;
		size++;
	}
}

void Deque::insertRear(const EType &value){
	checkRear();
	if(size == 0){
		if(front > rear){
			arr[((capacity-1)/2)+1] = value;
			rear++;
			size++;
		} else {
			arr[(capacity-1)/2] = value;
			size++;
		}
	} else {
		arr[rear+1] = value;
		rear++;
		size++;
	}
}

EType Deque::removeFront(){
	EType hold;	
	if(front > rear){
		std::cerr << "No more elements to remove from the front.\n";
	} else {
		hold = arr[front];	
		front++;
		size--;
		return hold;
	}
}

EType Deque::removeRear(){
	EType hold;
	if(front > rear){
		std::cerr << "No more elements to remove from the rear.\n";
	} else {
		hold = arr[rear];
		rear--;
		size--;
		return hold;
	}
}

int Deque::getSize(){
	return size;
}

bool Deque::empty(){
	return size == 0 ? true : false;
}

void Deque::checkFront(){
	if(front == 0)
		expand();
	else 
		return;
}

void Deque::checkRear(){
	if(rear == capacity-1)
		expand();
	else
		return;
}

void Deque::expand(){
	EType *temp = new EType[2*capacity];
	int qtr;
	if(front == 0){
		qtr = (2*capacity)/4;
		for(int i = front; i <= rear; i++){
			temp[qtr] = arr[i];
			qtr++;
		}
		delete [] arr;
		arr = temp;
		front = (2*capacity)/4;
		rear = qtr-1;
		capacity*=2;
		std::cerr << "Expanded from " << capacity/2 << " to " << capacity << std::endl;
	}
	else if(rear == capacity-1){
		qtr = (2*capacity) - capacity/4;
		for(int i = rear; i >= front; i--){
			temp[qtr] = arr[i];
			qtr--;
		}
		delete [] arr;
		arr = temp;
		front = qtr+1;
		rear = (2*capacity) - capacity/4;
		capacity*=2;
		std::cerr << "Expanded from " << capacity/2 << " to " << capacity << std::endl;
	}
}


