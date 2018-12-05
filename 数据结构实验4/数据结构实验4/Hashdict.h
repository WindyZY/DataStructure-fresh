/****************************************
Author:ÖÜÑþ201730685202
Date:2018-12-02
Description:Implement for hashing using three kinds of probing
*****************************************/

#pragma once
#ifndef HASHDICT_H
#define HASHDICT_H

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// Dictionary implemented with a hash table

#include"ADT.h"
#include"KVpair.h"
#include<iostream>
#include<ctime>
#include<stdlib.h>

template <typename Key, typename E>
class hashdict : public Dictionary<Key, E> {
private:
	KVpair<Key, E>* HT;   // The hash table
	int M;        // Size of HT
	int currcnt;  // The current number of elements in HT
	Key EMPTYKEY; // User-supplied key value for an empty slot

	int p(Key K, int i) const // Probe using linear probing
	{
		return i;
	}

	int h(int x) const { return x % M; } // Poor hash function
	int h(char* x) const { // Hash function for character keys
		int i, sum;
		for (sum = 0, i = 0; x[i] != '\0'; i++) sum += (int)x[i];
		return sum % M;
	}

	int H2(int x) {//Hash function used in probing for int keys
		return (x + 1)%(M - 2);
	}

	int H2(char* x) const {//Hash function used in probing for character keys
		int i, sum;
		for (sum = 0, i = 0; x[i] != '\0'; i++)
			sum += (int)x[i];
		return (sum + 1) % (M - 2);
	}

	int p(Key k, int i) {//Used for probing
		/*cout << "1.LinearProbe  2.QuadraicProbe  3.PseudorandomProbe" << endl;
		int probe;
		cin >> probe;
		switch (probe)
		{
		case 1:
			return i;
			break;
		case 2:
			return i*H2(k);
			break;
		case 3:
			return rand();
			break;
		default:
			cout << "WRONG!" << endl;
			return -1;
		}*/

		return i;//Linear Probing
		//return i*H2(k);//Quadraic Probing
		//return rand();//Pseudorandom Probing
	}

	// Insert e into hash table HT
	void hashInsert(const Key& k, const E& e) {
		int home;                     // Home position for e
		int pos = home = h(k);        // Init probe sequence
		for (int i = 1; EMPTYKEY != (HT[pos]).key(); i++) {
			pos = (home + p(k, i)) % M; // probe
			//Assert(k != (HT[pos]).key(), "Duplicates not allowed");
			if (k == (HT[pos]).key())
				cout << "Duplicates not allowed!" << endl;
		}
		KVpair<Key, E> temp(k, e);
		HT[pos] = temp;
	}
	
	// Search for the record with Key K
	E hashSearch(const Key& k) const {
		int home;              // Home position for k
		int pos = home = h(k); // Initial position is home slot
		for (int i = 1; (k != (HT[pos]).key()) &&
			(EMPTYKEY != (HT[pos]).key()); i++)
			pos = (home + p(k, i)) % M; // Next on probe sequence
		if (k == (HT[pos]).key()) {    // Found it
			cout << "The position of the record is " << pos << endl;
			return (HT[pos]).value();
		}
		else return NULL;            // k not in hash table
	}

public:
	hashdict(int sz, Key k) { // "k" defines an empty slot
		M = sz;
		EMPTYKEY = k;
		currcnt = 0;
		HT = new KVpair<Key, E>[sz]; // Make HT of size sz
		for (int i = 0; i<M; i++)
			(HT[i]).setKey(EMPTYKEY); // Initialize HT
	}

	~hashdict() { delete HT; }

	// Find some record with key value "K"
	E find(const Key& k) const
	{
		return hashSearch(k);
	}

	int size() { return currcnt; } // Number stored in table
								   
	void insert(const Key& k, const E& it) {// Insert element "it" with Key "k" into the dictionary.
		//Assert(currcnt < M, "Hash table is full");
		if (currcnt >= M)
		{
			cout << "Hash table is full!" << endl;
			exit(1);
		}
			
		hashInsert(k, it);
		currcnt++;
	}

	// remove not implemented
	E remove(const Key& K) { 
		if (K == EMPTYKEY)
			return NULL;
		int pos = h(K);
		for (int i = 0; i < size(); i++)
		{
			if (HT[pos].key() == K)  //Remove it when found
			{
				cout << "Already removed " << pos << ":" << HT[pos].key() << "--";
				HT[pos].setKey(EMPTYKEY);  //Set the slot as empty
				currcnt--;
				return HT[pos].value();   //Return the value
			}
			pos = (h(K) + p(K, i)) % M;  //Check the next position
		}
	}

	E removeAny() {  // Remove the first element
		//Assert(currcnt != 0, "Hash table is empty");
		if (currcnt == 0)
		{
			cout << "Hash table is empty!" << endl;
			return NULL;
		}
			
		int i;
		for (i = 0; i<M; i++)
			if ((HT[i]).key() != EMPTYKEY) { //Find the first slot that is not empty
				cout << "Already removed " << i << ":" << HT[i].key() << "--";
				//Remove it
				(HT[i]).setKey(EMPTYKEY);
				currcnt--;
				return (HT[i]).value();
			}
	}

	void clear() { // Clear the dictionary
		for (int i = 0; i<M; i++) (HT[i]).setKey(EMPTYKEY);
		currcnt = 0;
	}
	
	void print() {  //Print the hash table
		cout << "The hash table is:" << endl;
		for (int i = 0; i < M; i++) {
			if (HT[i].key() == -1)
				cout << i << ":" << "EMPTY!" << endl;
			else
				cout << i << ":" << HT[i].key() << "--" << HT[i].value() << endl;
		}
	}
};

#endif // !HASHDICT_H
