#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

typedef int EType;

class Deque {
	friend std::ostream &operator<<(std::ostream &os, const Deque &dq){
		os << "[";
		for(int i = dq.front; i <= dq.rear; i++){
			if(dq.size == 0)
				break;	
			os << dq.arr[i] << (i == dq.rear ? "" : ", ");
		}
		os << "]\n";
		return os;
	}

	public :
		Deque();
		void insertFront(const EType &value);
		void insertRear(const EType &value);
		EType removeFront();
		EType removeRear();
		int getSize();
		bool empty();
	
	private : 
		void checkFront();
		void checkRear();
		void expand();
		int size, capacity, front, rear;
		EType *arr;
		static const int initialCap = 10;
};

#endif
