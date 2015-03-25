/************************************************************************
**ye.cai
**2015.3.24
**以o(1)时间复杂度获取栈的最大、最小值
************************************************************************/
#include <stack>
#include <iostream>
using namespace std;

template<class T>
struct sNode
{
	T data;
	sNode *minPtr;
	sNode *maxPtr;
};

template <class T>
class sStack
{
public:
	sStack(){}
	~sStack()
	{
		while(empty() == false)
		{
			sNode<T> *n = m_stk.top();
			delete n;
			m_stk.pop();
		}
	}

	void pop();
	void push(const T &t);
	T top();
	T getMin();
	T getMax();
	bool empty();
private:
	sNode<T> *getMaxNode();
	sNode<T> *getMinNode();
private:
	stack<sNode<T>*> m_stk;
};

template<class T>
sNode<T>* sStack<T>::getMaxNode()
{
	if(empty())
		return NULL;
	return m_stk.top()->maxPtr;
}

template<class T>
sNode<T>* sStack<T>::getMinNode()
{
	if(empty())
		return NULL;
	return m_stk.top()->minPtr;
}

template<class T>
bool sStack<T>::empty()
{
	return m_stk.empty();
}

template<class T>
void sStack<T>::push(const T &t)
{
	sNode<T> *n  = new sNode<T>;
	n->data = t;
	if(empty())
	{
		n->maxPtr = n;
		n->minPtr = n;
	}
	else
	{
		if(getMaxNode()->data > t)
			n->maxPtr = getMaxNode();
		else
			n->maxPtr = n;

		if(getMinNode()->data < t)
			n->minPtr = getMinNode();
		else
			n->minPtr = n;
	}
	m_stk.push(n);
}

template<class T>
void sStack<T>::pop()
{
	if(empty() == false)
	{
		sNode<T> *n = m_stk.top();
		delete n;

		m_stk.pop();
	}
}

template<class T>
T sStack<T>::top()
{
	return m_stk.top()->data;
}

template<class T>
T sStack<T>::getMin()
{
	return getMinNode()->data;
}

template<class T>
T sStack<T>::getMax()
{
	return getMaxNode()->data;
}


/////////////////////////////////////
/////////////unit test///////////////
/////////////////////////////////////
//#define STACKTEST

#ifdef STACKTEST
int main(int argc, char **argv)
{
	int a[7] = {4,1,5,2,3,-1,7};
	sStack<int> st;
	for(int i = 0; i < 7; ++i)
	{
		st.push(a[i]);
		cout << "push--- min "<<st.getMin()<<" max "<<st.getMax()<<endl;
	}
	
	while(st.empty() == false)
	{
		cout << "pop--- min "<<st.getMin()<<" max "<<st.getMax()<<endl;
		st.pop();
	}

	getchar();
	return 0;
}
#endif

