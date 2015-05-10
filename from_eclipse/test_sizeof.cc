/*
 * test_sizeof.cc
 *
 *  Created on: Aug 5, 2014
 *      Author: syerramreddy
 */
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	//const char *s = "siva";
	char s[] = "siva";
	cout<<"sizeof(s)="<<sizeof(s)<<",strlen(s)="<<strlen(s)<<endl;
}


