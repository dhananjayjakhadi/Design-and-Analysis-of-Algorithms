#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class GraphNode{
public:
	string label;
	int rank;
	double distance;
	GraphNode(string ,int,double);
	bool operator<(const GraphNode &c1) const;

};

GraphNode::GraphNode(string labelIn,int rankIn,double distanceIn){
	label = labelIn;
	rank = rankIn;
	distance = distanceIn;
}
bool GraphNode::operator<(const GraphNode &c1) const
{
	return !(distance < c1.distance);
}


int main (int argc, char* argv[]) {

	int num_of_nodes;
	ifstream fp;
	fp.open(argv[1]);
	string input;
	string line;
	getline(fp,line);
	int line_num;
	while ( fp ) {
		input += line;
		line_num++;
		getline(fp,line);
		input += ",";

	}
	num_of_nodes = line_num;
	double graph[num_of_nodes][num_of_nodes];
	for(int i =0;i<num_of_nodes;i++){
		for(int j =0;j<num_of_nodes;j++){
			graph[i][j] = DBL_MAX;
		}
	}
	stringstream seperateLine(input);
	string digit;
	int row  = 0, col = 0;
	while(getline(seperateLine, digit, ',')) {
		double val = atof(digit.c_str());
		if(val == -99)
		graph[row][col++] = LONG_MAX;
		else
		graph[row][col++] = val;
		if(row == line_num){
			row++;
			col = 0;
		}
	}
	vector<GraphNode> minHeap;
	double distance[num_of_nodes];
	//initialize all distance to infinity
	minHeap.push_back(GraphNode("s",0,0));
	distance[0] = 0;
	for(int i =1;i < num_of_nodes;i++){
		minHeap.push_back(GraphNode("s",i,LONG_MAX));
		distance[i] = LONG_MAX;
	}
	make_heap(minHeap.begin(), minHeap.end());

	//GraphNode
	while(!minHeap.empty()){
		GraphNode v = minHeap.front();
		int node_rank = v.rank;
		pop_heap(minHeap.begin(),minHeap.end());
		minHeap.pop_back();
		for(int i =0;i<num_of_nodes;i++){
			if(graph[node_rank][i] > 0){
				distance[i] = min(distance[i],distance[node_rank] + graph[node_rank][i]);
				int j;
				for ( j=0; i<minHeap.size(); j++){
					if(minHeap[j].rank == i){
						minHeap[j].distance = distance[i];
						break;
					}
					make_heap(minHeap.begin(), minHeap.end());
				}
			}
		}
	}

	for(int i =1;i<num_of_nodes;i++){
		cout<< "Shortest distance of node S" << i << " from S0 is  =>  " ;
		if(distance[i] == LONG_MAX)
		cout << "No Path" << endl;
		else
		cout << distance[i] << endl;
	}
	return 0;
}
