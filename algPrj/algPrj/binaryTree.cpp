/************************************************************************
**ye.cai
**2015.3.26
**二叉查找树的创建、增加、删除及从小到大按顺序输出
************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template<class T>
struct tNode
{
	T data;
	tNode *lPtr;
	tNode *rPtr;

	tNode():lPtr(NULL), rPtr(NULL)
	{
	}
	tNode(const T &t):lPtr(NULL), rPtr(NULL),data(t)
	{

	}

	~tNode()
	{
		/*if (lPtr)
		{
			delete lPtr;
			lPtr = NULL;
		}

		if(rPtr)
		{
			delete rPtr;
			rPtr = NULL;
		}*/
	}
};

template<class T>
class bintree
{
public:
	bintree():root(NULL){}
	bintree(T *array, int n);
	~bintree();
	void insert(const T &t);
	bool exits(const T &t);
	void remove(const T &t);
	void output(vector<T> &lst);
private:
	tNode<T> *root;
};

template<class T>
bintree<T>::bintree(T *array, int n)
:root(NULL)
{
	for(int i = 0; i < n; ++i)
	{
		insert(array[i]);
	}
}

template<class T>
bintree<T>::~bintree()
{
	if(root == NULL)
		return;

	stack<tNode<T> *> stk;
	stk.push(root);
	while(stk.empty() == false )//先序遍历删除元素
	{
		tNode<T> *cur = stk.top();
		stk.pop();

		if(cur->rPtr)
			stk.push(cur->rPtr);
		if(cur->lPtr)
			stk.push(cur->lPtr);

		cout<<"del "<<cur->data<<endl;
		delete cur;
	}

	root = NULL;
}

template<class T>
void bintree<T>::insert(const T &t)
{
	if(root == NULL)
	{
		root = new tNode<T>(t);
		return;
	}

	tNode<T> *cur = root;
	tNode<T> *n = new tNode<T>(t);
	while (cur)
	{
		if(t < cur->data)
		{
			if(cur->lPtr)
				cur = cur->lPtr;
			else
			{
				cur->lPtr = n;
				break;
			}
		}
		else
		{
			if(cur->rPtr)	
				cur = cur->rPtr;
			else
			{
				cur->rPtr = n;
				break;
			}
		}
	}	
}

template<class T>
bool bintree<T>::exits(const T &t)
{
	tNode<T> *cur = root;
	while(cur)
	{
		if(cur->data == t)
			return true;
		else if(t < cur->data)
			cur = cur->lPtr;
		else
			cur = cur->rPtr;
	}

	return false;
}

template<class T>
void bintree<T>::remove(const T &t)
{
	//?????
}

template<class T>
void bintree<T>::output(vector<T> &lst)//中序遍历
{
	stack<tNode<T> *> stk;
	tNode<T> *cur = root;
	while(cur || stk.empty() == false)
	{
		while(cur)
		{
			stk.push(cur);
			cur = cur->lPtr;
		}

		tNode<T> *n = stk.top();
		lst.push_back(n->data);
		stk.pop();

		cur = n->rPtr;
	}
}