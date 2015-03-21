#include <iostream>
#include "deque.h"

using namespace std;

int main(){
	Deque dq;
	cout << "-------Inserting/removing numbers while alternating-------\n";
	cout << "dq starting out with " << dq;
	for(int i = 0; i < 35; i++){
		if(i%2 == 0){
			cout << "Inserting " << i << " to the front of the deque. ";
			dq.insertFront(i);
			cout << dq;
		}
		else{
			cout << "Inserting " << i << " to the rear of the deque. ";
			dq.insertRear(i);
			cout << dq;
		}
	}
	while(!dq.empty()){
		if(dq.getSize()%2 == 0){
			cout << "Removing " << dq.removeFront() << " from the front of the deque. ";
			cout << dq;
		}
		else{
			cout << "Removing " << dq.removeRear() << " from the rear of the deque. ";
			cout << dq;
		}	
	}

	Deque dq2;
	cout << "-------Inserting/removing numbers for only the front-------\n";
	cout << "dq2 starting out with " << dq2;	
	for(int i = 0; i < 35; i++){
		cout << "Inserting " << i << " to the front of the deque. ";
		dq2.insertFront(i);
		cout << dq2;
	}
	while(!dq2.empty()){
		cout << "Removing " << dq2.removeRear() << " from the rear of the deque. ";
		cout << dq2;
	}
	
	Deque dq3;
	cout << "-------Inserting/removing numbers for only the rear-------\n";
	cout << "dq3 starting out with " << dq3;	
	for(int i = 0; i < 35; i++){
		cout << "Inserting " << i << " to the rear of the deque. ";
		dq3.insertRear(i);
		cout << dq3;
	}
	while(!dq3.empty()){
		cout << "Removing " << dq3.removeFront() << " from the front of the deque. ";
		cout << dq3;
	}
	
	cout << "-------Inserting to the rear again using the same deque-------\n";
	cout << "dq3 starting out with " << dq3;
	for(int i = 0; i < 35; i++){
		cout << "Inserting " << i << " to the rear of the deque. ";
		dq3.insertRear(i);
		cout << dq3;
	}
	while(!dq3.empty()){
		cout << "Removing " << dq3.removeRear() << " from the rear of the deque. ";
		cout << dq3;
	}
	return 0;	
}
