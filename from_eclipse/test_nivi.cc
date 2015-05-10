/*
 * test_nivi.cc
 *
 *  Created on: Aug 5, 2014
 */
#include<iostream>
#include<bitset>
using namespace std;
int random_nums[] = {0xbf, 0x1e, 0xcc, 0x7f, 0xe4, 0x6b, 0x18, 0x80, 0x98, 0xcf, 0x2a, 0x0a, 0x8b,0xda, 0x3d, 0x50, 0xe7, 0xc3, 0x25, 0xd7, 0x4b, 0x32, 0x3f, 0xbc, 0xab};
//bitset<8> num_bits = {0xbf, 0x1e, 0xcc, 0x7f, 0xe4, 0x6b, 0x18, 0x80, 0x98, 0xcf, 0x2a, 0x0a, 0x8b,0xda, 0x3d, 0x50, 0xe7, 0xc3, 0x25, 0xd7, 0x4b, 0x32, 0x3f, 0xbc, 0xab};
int main()
{
	bitset<8> old = random_nums[0];
	bitset<2> infobit {0};

	bitset<2> zero_infobit{0}, left_infobit{1}, right_infobit{2}, inv_infobit{3};
	//cout<<right_infobit<<endl;
	for (unsigned int i = 1; i < sizeof(random_nums)/sizeof(int); i++) {
		bitset<8> x = random_nums[i];
		bitset<8> x_left = (x << 1) | (x >> 7) ;
		bitset<8> x_right = x >> 1 | (x << 7);
		bitset<8> x_inv = ~x;

		int _diff = (x ^ old).count();
		int diff = _diff +  (infobit ^ zero_infobit).count();
		int _left_diff = (x_left ^ old).count();
		int left_diff = _left_diff + (infobit ^ left_infobit).count();
		int _right_diff = (x_right ^ old).count();
		int right_diff = _right_diff + (infobit ^ right_infobit).count();
		int _inv_diff = (x_inv ^ old).count();
		int inv_diff = _inv_diff + (infobit ^ inv_infobit).count();


		if (diff <= left_diff && diff <= right_diff && diff <=inv_diff) {
			infobit = zero_infobit;
			old = x;
			//cout<<"selecting regular";
		} else if (left_diff <= diff && left_diff <= right_diff && left_diff <= inv_diff) {
			infobit = left_infobit;
			old = x_left;
			//cout<<"selecting left";
		} else if (right_diff <= diff && right_diff <= left_diff && right_diff <= inv_diff) {
			infobit = right_infobit;
			old = x_right;
			//cout<<"selecting right";
		} else {
			infobit = inv_infobit;
			old = x_inv;
			//cout<<"selecting inv";
		}
		//cout<<endl;
		cout<<hex<<random_nums[i]<<"\t "<<x<<"\t "<<_diff<<" "<<(_diff < 4?"<":">") <<" 4\t ";
		if (infobit == zero_infobit) {
			cout<<infobit<<"\t "<<diff;
		}
		cout<<endl;

		cout<<"left\t "<<x_left<<"\t "<<_left_diff<<" "<<(_left_diff<4?"<":">")<<" 4\t ";
		if (infobit == left_infobit)
			cout<<infobit<<"\t "<<left_diff;
		cout<<endl;

		cout<<"right\t "<<x_right<<"\t "<<_right_diff<<" "<<(_right_diff<4?"<":">")<<" 4\t ";
		if (infobit == right_infobit)
			cout<<infobit<<"\t "<<right_diff;
		cout<<endl;
		cout<<"inv\t "<<x_inv<<"\t "<<_inv_diff<<" "<<(_inv_diff<4?"<":">")<<" 4\t ";
		if (infobit == inv_infobit)
			cout<<infobit<<"\t "<<inv_diff;
		cout<<endl<<endl;


	}
	cout<<endl;
}
