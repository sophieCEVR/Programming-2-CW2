/* 
 * File:   Inventory.cpp
 * Author: 100021268
 * 
 * Created on 15 March 2018, 14:18
 */

#include "Inventory.h"
#include <string>
#include <cstdlib>
using namespace std;

Inventory::Inventory(){}

Inventory::Inventory(const Inventory& orig) {}//constructor using another inventory


//method to add a pointer to a singular StockItem object to the inventory
inline void Inventory::add(StockItem*stockitem){
    InventoryList.push_back(stockitem);
}

//toString method allows to easily display entire inventory list
inline void Inventory::toString(){
    for(StockItem*stockitem : InventoryList){
        cout << *stockitem << endl;
    }
}

//sorts the inventory by unit price in increasing order, can be changed to decreasing by simply flipping the < operand to >
 inline void Inventory::sortByUnitPriceAsc(){
     InventoryList.sort([](StockItem*a, StockItem*b) {return a->unitprice < b->unitprice;});
 } 
 

 //finds the item with the largest stock held (accounts for multiple items with the highest stock number)
 inline void Inventory::largestStock(){
    list<StockItem*> result;
    for(StockItem*stockitem : InventoryList){
        if(result.empty()){
            result.push_back(stockitem);
        }
        else if(stockitem->getNumberheld()==result.front()->getNumberheld()){//accounts for more than one result
            result.push_back(stockitem);
        }
        else if(stockitem->getNumberheld()>result.front()->getNumberheld()){
            result.clear();
            result.push_back(stockitem);     
        }
    }
    cout << "Stock item(s) with the largest amount of stock held : " << endl;
    for(StockItem*s : result){ 
        cout << *s << endl;
    }
 }

 /*Checks for NPN Transistors within the inventory. 
  * returns both how many different NPN transistors are in stock 
  * and how many total NPN Transistors are in stock
  */
inline void Inventory::NPNTransistorCheck(){
    int counter = 0;
    int totalStock = 0;
    for(StockItem*stockitem : InventoryList){
        if (stockitem->getType().compare("transistor")==0 && stockitem->getOther().compare("NPN")==0){
            counter++;
            totalStock = totalStock + stockitem->getNumberheld();
        }
    }
    cout << "Total NPN Transistors types in stock \n" << counter << endl; 
    cout << "Amount of NPN Transistors in stock  \n" << totalStock << endl; 
}
 
 

 /*returns the total resistance of all resistors in stock 
  * (finds the resistance for each resistor type stock item then times this 
  * by the stock number held for this item, then adds these totals together
  * to give total resistance for ALL resistors.
  */
 inline void Inventory::totalResistance(){

     string resistanceString = "";
     char currentChar = ' ';
     string endString = "";
     double thisResist = 0;
     double totalResistance = 0;
     int multiplier = 1;
     int stock = 0;

     for(StockItem*stockitem : InventoryList){
         if (stockitem->getType().compare("resistor")==0){
             resistanceString = stockitem->getOther();
             int runs = resistanceString.length();
             for(int i = 0; i < runs; i++){
                 currentChar = resistanceString.front();
                 if(currentChar=='0'){
                     endString.push_back('0');
                 }
                 else if(currentChar=='K'){
                     multiplier = 1000;
                     endString.push_back('.');
                 }
                 else if(currentChar=='M'){
                     multiplier = 1000000;
                     endString.push_back('.');
                 }
                 else if(currentChar=='R'){
                     multiplier = 1;
                     endString.push_back('.');
                 }
                 else{
                     endString.push_back(currentChar);
                 }
                 resistanceString.erase(0,1);
             }
             thisResist = stod(endString);
             stock = stockitem->getNumberheld();
             thisResist = (thisResist*multiplier*stock);
             endString = "";
         }
         totalResistance = (totalResistance + thisResist);
         thisResist=0;
     }
     cout << std::fixed;
     cout << "Total Resistance of all resistors in stock  \n" << totalResistance << " Ohms" << endl;
 }
     
//Returns the amount of items which have a unit price above given price
inline void Inventory::unitPricesAbove(int price){
        int counter=0;
        for(StockItem*stockitem : InventoryList){
            if(stockitem->getUnitprice()>price){
                counter++; 
            }
        }
        cout << "Amount of stock items with a unit price above 10p \n" << counter << endl;
}

Inventory::~Inventory() {}

