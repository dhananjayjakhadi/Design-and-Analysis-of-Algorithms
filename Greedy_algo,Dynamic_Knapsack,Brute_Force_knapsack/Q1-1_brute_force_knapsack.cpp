#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Item{
	public:
		int itemId;
		int itemWeight;
		int itemValue;
		Item(int,int ,int);
		void PrintItem();
};

Item::Item(int a,int b,int c){
			itemId = a;
			itemWeight = b;
			itemValue = c;
	}
void Item::PrintItem(){
			cout << itemId << "\t\t"<< itemWeight << "\t\t" << 	itemValue << endl;
	}

class Knapsack{
	public:
		vector<Item> items;
		double totalWeight;
		double totalValue;
		Knapsack();
		int getTotalWeight();
		int getTotalValue();
};

Knapsack::Knapsack(){
		totalWeight = 0;
		totalValue = 0;
		}

int Knapsack::getTotalValue(){
	return totalValue;
}

int  Knapsack::getTotalWeight(){
	return totalWeight;
}

vector<Item> allItems;
int selectedKnapsackId = -1;
int profit = INT_MIN;
int num_of_items,knapsack_capacity;

vector<Knapsack> KnapsackCollection;

void generateAllCombinationsHelper(vector<Knapsack> &KnapsackCollection, Knapsack &k, int index[], int start, int end){
	KnapsackCollection.push_back(k);
	if(k.getTotalWeight() <= knapsack_capacity && profit < k.getTotalValue()) {
		profit = k.getTotalValue();
		selectedKnapsackId = KnapsackCollection.size() - 1;
	}

	for(int i =start;i<end; i++){
		k.items.push_back(allItems[i]);
		//add weight and value
		k.totalWeight += allItems[i].itemWeight;
		k.totalValue += allItems[i].itemValue;
		generateAllCombinationsHelper(KnapsackCollection,k,index,i+1,end);

		k.totalWeight -= k.items[k.items.size()-1].itemWeight;
		k.totalValue -= k.items[k.items.size()-1].itemValue;
		k.items.pop_back();
	}
}

void generateAllCombinations(int index[], int arrLength){

	Knapsack k;
	generateAllCombinationsHelper(KnapsackCollection, k, index, 0, arrLength);
}

int main (int argc, char* argv[]) {

	ifstream fp;
    fp.open(argv[1]);
    string input;
    string line1;
    string line2;
    string line3;
    string line4;
    getline(fp,line1);
    getline(fp,line2);
    getline(fp,line3);
    getline(fp,line4);
    num_of_items = atoi(line1.c_str());
    knapsack_capacity = atoi(line4.c_str());
    int itemWeight[num_of_items];
    int itemProfit[num_of_items];
    stringstream seperateLine1(line2);
    stringstream seperateLine2(line3);
    int i =0;
    //read Item weight Line from input
    while(getline(seperateLine1, line2, ',')) {
    		itemWeight[i++] = atoi(line2.c_str());
		}
	i =0;
    //read Item Profit line from input
    while(getline(seperateLine2, line3, ',')) {
    		itemProfit[i++] = atoi(line3.c_str());
		}

	//create all item objects
		for(int i =1;i<=num_of_items;i++){
			allItems.push_back(Item(i,itemWeight[i-1],itemProfit[i-1]));
		}
		int index[num_of_items];
		for(int i =0;i<num_of_items;i++){
			index[i] = i+1;
		}
		generateAllCombinations(index, num_of_items);
		cout << "\n\n*****************BruteForce Approch Result*****************\n" << endl;
		cout << endl;
		cout << "Profit  =>  " << profit << endl << endl;
		cout << "Item Id      Item Weight    Item Value"<<endl;
		cout << "--------------------------------------------" << endl;
 		for (int i = 0; i < KnapsackCollection[selectedKnapsackId].items.size(); ++i)
		{
			KnapsackCollection[selectedKnapsackId].items[i].PrintItem();
		}
		cout << "--------------------------------------------" << endl;
		cout << "\n\n*****************BruteForce Approch Result*****************\n" << endl;

	}
