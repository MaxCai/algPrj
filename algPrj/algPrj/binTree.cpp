/*
**ye.cai
**2015.4.8
**二叉树的几个操作
*/

template<class T>
struct Node
{
	T data;
	Node *lPtr;
	Node *rPtr;
};


/*
**@1
**根节点到某个节点的距离
*/
template<class T>
int DistFromRootToNode(Node<T> *root, Node<T> *node)
{
	if(root == NULL)
		return -1;

	if(root == node)
		return 0;

	int l_dist = DistFromRootToNode(root->lPtr, node);
	int r_dist = DistFromRootToNode(root->rPtr, node);

	if(l_dist >= 0)
		return l_dist + 1;
	else if(r_dist >= 0)
		return r_dist + 1;
	else
		return -1;
}

/*
**@2
**两个节点的最低公共父节点
*/
template<class T>
Node<T>* Parent(Node<T> *root, Node<T> *node_1, Node<T> *node_2)
{
	if(root == NULL)
		return NULL;

	if(root == node_1 || root == node_2)
	{
		return root;
	}

	Node<T> *l_pa = Parent(root->lPtr, node_1, node_2);
	Node<T> *r_pa = Parent(root->rPtr, node_1, node_2);

	if(l_pa && r_pa)
		return root;
	else
		return l_pa ? l_pa : r_pa; 
}

/*
**@3
**两个节点间的距离
*/
template<class T>
int DistBetweenNodes(Node<T> *root, Node<T> *node_1, Node<T> *node_2)
{
	if(root == NULL || node_1 == NULL || node_2 == NULL)
		return 0;

	Node<T> *pa = Parent(root, node_1, node_2);

	return DistFromRootToNode(root, node_1) + DistFromRootToNode(root, node_2) - 2 * DistFromRootToNode(root, pa);
}

/*
**@4
**树中节点间的最大距离
*/
template<class T>
int MaxDistInTree(Node<T> *root, int &depth)
{
	if(root == NULL)
	{
		depth = -1;
		return -1;
	}

	int l_depth;
	int r_depth;
	int l_maxDist = MaxDistInTree(root->lPtr, l_depth);
	int r_maxDist = MaxDistInTree(root->rPtr, r_depth);

	if(l_depth > r_depth)
		depth = l_depth + 1;
	else
		depth = r_depth + 1;
	return  max(max(l_maxDist, r_maxDist), l_depth + r_depth + 2);
}