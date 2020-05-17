//including the neccessary folders
#include "Header.h"


//Default constructor, set the root of kd tree to null
KDTree::KDTree()
{
	root = NULL;
};

//Add to the kd tree the new data
int KDTree::add(vec data)
{
	k = data.size();
	if (root == NULL)
	{
		root = new KDNode;
		root->axis = 0;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		insert(root, data, root->axis);
	}
	return 1;
};

//Insert a point to the kd tree which sundivides the node
KDNode *KDTree::insert(KDNode *node, vec data, int level)
{
	if (node == NULL)
	{
		node = new KDNode;

		if (level == k)
		{
			node->axis = 0;
		}
		else
		{
			node->axis = level;
		}

		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}

	else
	{
		if (node->data == data)
		{
			return node;
		}

		if (data.at(node->axis) <= node->data.at(node->axis))
		{
			node->left = insert(node->left, data, node->axis + 1);
		}

		else
		{
			node->right = insert(node->right, data, node->axis + 1);
		}
	}

	return node;
};

//Function which will search the kd tree to find closest point
vec KDTree::search(vec data)
{

	best_dist = 1e300;
	knn(root, data);
	return best_guess;
};


//Uses the knn algorithm to find the closest
void KDTree::knn(KDNode *node, vec q)
{
	if (!node) return;

	double dist = distance(q, node->data);

	if (dist < best_dist)

	{
		best_guess = node->data;
		best_dist = dist;
	}


	KDNode *nearestN;
	KDNode *farN;

	//Check the closest 
	if (q.at(node->axis) < node->data.at(node->axis))
	{
		nearestN = node->left;
	}
	else
	{
		nearestN = node->right;
	}

	if (q.at(node->axis) < node->data.at(node->axis))
	{
		farN = node->right;
	}
	else
	{
		farN = node->left;
	}


	knn(nearestN, q);

	if (abs(q.at(node->axis) - node->data.at(node->axis) >= best_dist))
	{
		return;

	}

	knn(farN, q);
};


//To find the distance between two points
double KDTree::distance(vec q, vec p)
{
	double v = 0;

	for (int i = 0; i < k; i++)
	{
		v += pow(q[i] - p[i], 2);
	}

	return abs(sqrt(v));
};
