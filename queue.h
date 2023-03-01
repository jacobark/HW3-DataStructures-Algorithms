//ECGR 3180 - Homework 3B
//Jacob Barker
//jbarke33@uncc.edu
#ifndef queue_h
#define queue_h
#include <iostream>

class Node {	//Node Class defined from class notes
	public:
		double     time ;
		Node            *next ;
		Node ( double time, Node *next = nullptr) {
			this->time = time;
			this->next = next;
		}
} ;


class Queue { //Queue Class
	public:
		Node    *head, *tail;
		Queue() { head = tail = nullptr ; }
		Node    *first() { return head ; }
                void enqueue(double time);      //enqueue function
                void dequeue();         //dequeue function
		double Avg_wait();	//average waitime of line queue method
} ;

#endif
