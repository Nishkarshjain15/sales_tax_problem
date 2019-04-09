// 10 per on all except - books, food, medical 
// 5% - import tax on all imported goods
#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;

int main()
{
	int i,j,n,k,total;
	float x,tax;
	vector <string> v;
	vector <float> ans;
	string temp1,temp2;

	cin>>n;
	while(n--)
	{
		getline(cin,temp1);
		v.push_back(temp1);
	}

	//get all the cost first



	float totaltax = 0;
	float totalvalue = 0;
	for(i=0; i<v.size(); i++)
	{
		temp1 = v[i];
		reverse(temp1.begin(), temp1.end());

		stringstream ss(temp1);
		ss>>x; // x will store cost from each line

		//now check whether imported word exists in temp1
		if(temp1.find("imported") != string::npos)
		{
			//"imported" word is present
			// now check for food
			if(temp1.find("chocolate") != string::npos)
				tax = 0.05 * x;
			else
				tax = 0.15 * x; 
		}
		else
		{// for non imported goods
			
			//for chocolate, pills, books no tax
			if(temp1.find("chocolate") !=string::npos || temp1.find("books") != string::npos
				|| temp1.find("pills") !=string::npos )
				tax = x;
			else
				tax = 0.10 * x;
		}

		totalvalue += (tax + x); 
		totaltax += tax;
		ans.push_back(x + tax);
	}

	//ip imported bottle of perfume at 27.99 
	//op imported bottle of perfume: 32.19
	for(i=0;i<v.size();i++)
	{
		temp1 = v[i];
		j = temp1.find("at");
		temp2 = temp1.substr(0,j-1);
		cout<<temp2<<": "<<ans[i]<<endl;
	}

	cout<<"Sales Taxes: "<<totaltax<<endl;
	cout<<"Total: "<<totalvalue<<endl;


}
