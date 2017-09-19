#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stdio.h>
#include <stdlib.h>	
#include <string>
using namespace std;

int main (int argc, char* argv[]) {
	/*********** START : Read input from txt file **********/
	int num_of_items,knapsack_capacity;
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
	// for(int i =0;i<num_of_items;i++){
	// 	cout << itemWeight[i] << ' ';
	// }
    //read Item Profit line from input
    while(getline(seperateLine2, line3, ',')) {
    		itemProfit[i++] = atoi(line3.c_str()); 
		}
	/***********   END : Read input from txt file **********/
		int B[num_of_items+1][knapsack_capacity+1];
		
        for(int w = 0;w<= knapsack_capacity;w++){ // row 0 (empty Knapsack)
            B[0][w] = 0;
        }

        for (int k = 1; k <= num_of_items; k++) // row  1 to n
        {

            B[k][0] = 0; // element in column 0 (no profit for w = 0)
            for(int w = 1;w<= knapsack_capacity;w++){ // elements in columns 1 to W

                if((itemWeight[k-1] <= w ) && (B[k-1][w- itemWeight[k-1]]) + itemProfit[k-1] > B[k-1][w]){

                    B[k][w] = B[k-1][w- itemWeight[k-1]] + itemProfit[k-1];
                }
                else{

                    B[k][w] = B[k-1][w];
                }
        }
        }


        cout << "----------------------------------------------------------------------------------------------------------------------------------------"<< endl;
        cout << "\t\t" << "Dynamic Programming matrix" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------"<< endl;
        for (int i = 0; i <= num_of_items; ++i)
        {
        	for (int j = 0; j <= knapsack_capacity; ++j)
        	{
                cout << setw(4) << setfill(' ') << static_cast<int>(B[i][j]);
        	}
        	cout << endl;
        }
        cout << "-------------------------------------------------------------------------------------------------------------------------------"<< endl;
        int index = knapsack_capacity;
        int item = num_of_items;
        //Print Final Result
        cout << "Profit  =>  " << B[num_of_items][knapsack_capacity] << endl << endl;
        cout << "Item Id      Item Weight    Item Value"<<endl; 
        cout << "--------------------------------------------" << endl;
        while(index > 0){
            if(B[item-1][index] != B[item][index]){
                cout << "  " << item <<  "\t\t" << itemWeight[item - 1] << "\t\t" << itemProfit[item-1] << endl;
                item = item - 1;
                index = index - itemWeight[item];
            }
            else{
                item = item - 1;                
            }
        }
        cout << "--------------------------------------------" << endl;
}