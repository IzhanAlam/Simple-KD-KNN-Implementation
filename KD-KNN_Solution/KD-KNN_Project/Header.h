#pragma once
// including all the necessary #includes
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <math.h>


//Creating some typedefs
typedef vector<vector<double>> points;
typedef vector<double> vec;

//Structure for the node of the kd tree
struct KDNode {
	int axis; //to get the axis
	KDNode *left; //the left node of the tree
	KDNode *right; //the right node of the tree
	vec data; // a vector of doubles to contain the data
};


//Class to create the kd tree
class KDTree {
private:
	int k;
	double best_dist;
	vec best_guess;
	//nearesr neighbour search
	void knn(KDNode *node, vec q);
	//insert a new point
	KDNode *insert(KDNode *node, vec data, int level);

	//get the distance between two vectors
	double distance(vec q, vec p);


public:
	//default constructor
	KDTree();

	KDNode *root;

	vec search(vec data);

	int add(vec data);

};

void buildTree();