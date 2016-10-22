#ifndef _BOUNDEDBUFFER_H
#define _BOUNDEDBUFFER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using namespace std;

class BoundedBuffer {
	// DO NOT modify public function names
	public:
		BoundedBuffer(int N);
		void append(int data);
		int remove();
		bool isEmpty();
	private:
		//TODO: add any variables needed including buffer array, locks and conditional variables

};

#endif
