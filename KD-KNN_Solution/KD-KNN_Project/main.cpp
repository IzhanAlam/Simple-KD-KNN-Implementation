//including the neccessary folders
#include "Header.h"


//Example of building and searching KD tree

/*
	//This is to store the x and y of the two files into a vector of doubles used to build tree
	for (int i = 0; i < Grid.size(); i++)
	{
		pts.push_back({ Grid[i].x, Grid[i].y });
	}
	

		for (int i = 0; i < Points.size(); i++)
	{
		inter_pts.push_back({ Points[i].x,Points[i].y });
	}

		cout << "Building kdTree~~~~~~~~~~~~~" << endl;

	KDTree *kdtree = new KDTree;

	for (int i = 0; i < pts.size(); i++)
	{
		kdtree->add(pts.at(i));
	}

	//------------------------------------------------------------------


	points knn_pts;

	//This is to search the kd tree for the nearest points

	for (unsigned int i = 0; i < inter_pts.size(); i++)
	{
		//search the tree
		vec res_p = kdtree->search(inter_pts.at(i));

		if (res_p.size() > 0)
		{
			knn_pts.push_back(inter_pts.at(i));
			knn_pts.push_back(res_p);
		}


	}

	//This is to store the X and Y into a vector of doubles where even is x, and odd is y
	vec xyKnown, xyUnknown;
	for (unsigned int idx = 0; idx < knn_pts.size(); idx++)
	{
		//The odd contains the x and y of the known points
		if (idx % 2 != 0)
		{
			for (vec::const_iterator i = knn_pts.at(idx).begin(); i != knn_pts.at(idx).end(); ++i)
			{
				xyKnown.push_back(*i);
			}
		}
		//Unknwown points
		if (idx % 2 == 0)
		{
			for (vec::const_iterator i = knn_pts.at(idx).begin(); i != knn_pts.at(idx).end(); ++i)
			{
				xyUnknown.push_back(*i);
			}
		}

	}

	//This is to seperate the x and y from the previous for loop to their own vectors

	vec X, Y, Z;
	for (int i = 0; i < xyKnown.size(); i++)
	{
		if (i % 2 == 0)
		{
			X.push_back(xyKnown[i]);
		}
		if (i % 2 != 0)
		{
			Y.push_back(xyKnown[i]);
		}
	}



*/