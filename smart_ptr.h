//
// Created by krystian on 26.11.18.
//

#ifndef MATRIX_SMART_PTR_H
#define MATRIX_SMART_PTR_H

template<class T> class smart_ptr {
private:
	class referenceCounter{
	private:
		unsigned int counter;
	public:
		void AddRef(){
			counter++;
		}
		void SubstractRef(){
			--counter;
		}
	};

	T* p;
	referenceCounter* c;

public:
	smart_ptr(){
		p = nullptr;
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
};


#endif //MATRIX_SMART_PTR_H
