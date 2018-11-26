//
// Created by krystian on 26.11.18.
//

#ifndef MATRIX_SMART_PTR_H
#define MATRIX_SMART_PTR_H

#include <iostream>
using namespace std;

template<class T> class smart_ptr {
private:
	class referenceCounter{
	private:
		unsigned int counter;
	public:
		void AddRef(){
			counter++;
		}
		int SubstractRef(){
			return --counter;
		}
		int GetCounter(){
			return counter;
		}
	};

	T* p = nullptr;
	referenceCounter* c = nullptr;

public:
	smart_ptr(){
		c = new referenceCounter();
		c->AddRef();
	}

	smart_ptr(T* pVal){								// initialize with a value
		p = pVal;
		c = new referenceCounter();
		c->AddRef();
	}

	smart_ptr(const smart_ptr<T>& sp) {
		this->p = sp.p;
		this->c = sp.c;
		this->c->AddRef();
	}

	~smart_ptr(){
		if(c->SubstractRef() == 0){
			delete p;
			delete c;
			cout << "smart_ptr deleted" << endl;
		}
	}

	T& operator*(){
		return *p;
	}

	T* operator->(){
		return p;
	}

	smart_ptr<T>& operator= (const smart_ptr<T>& sp) {
		if(this != &sp) {							// don't do self assignment
			if(c->SubstractRef() == 0) {
				delete p;
				delete c;
			}
			this->p = sp.p;
			this->c = sp.c;
			this->c->AddRef();
		}
	}

	T& operator[] (const unsigned int i) const{
		return p[i];
	}

	int getReferences_no() const{
		return c->GetCounter();
	}
};


#endif //MATRIX_SMART_PTR_H
