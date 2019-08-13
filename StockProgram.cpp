/* 
 * File:   StockProgam.cpp
 * Author: 100021268
 *
 * Created on 15 March 2018, 11:36
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Inventory.h"
#include "StockItem.h"
using namespace std;

int main(int argc, char** argv){
    Inventory inventory;
    int count = 0;
    ifstream myfile ("inventory.txt");
    if (myfile.is_open())
    {
        while ( myfile.peek()!=EOF)
        {   
            count++;                      
            StockItem*stockItem = new StockItem();
            myfile >> stockItem;
            inventory.add(stockItem);
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file" << endl; 
    }
    
    cout << "Inventory as read " << endl; 
    inventory.toString();
    
    //Question 1 - Print a list of the inventory, sorted in order of increasing price.
    cout << "Inventory sorted by unit price in increasing order " << endl; 
    inventory.sortByUnitPriceAsc();
    inventory.toString();
    
    //Question 2 - What is the component with the largest number of components in stock?
    inventory.largestStock();
    
    //Question 3 - How many NPN transistors does Chartlins have in stock?
    inventory.NPNTransistorCheck();
    
    //Question 4 - What is the total resistance of all of the resistors in stock?
    inventory.totalResistance();            
    
    //Question 5 - How man stock items have unit prices above 10p?
    inventory.unitPricesAbove(10); 
    
    return EXIT_SUCCESS;
}