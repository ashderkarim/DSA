#include<iostream>
using namespace std;
void TowerofHanoi(int n, string src, string helper, string dest) {
	if(n == 1) {
		cout<<"Transfer disc "<<n<<" from "<<src<<" to "<<dest<<".\n";
		return;
	}
	TowerofHanoi(n - 1, src, dest, helper);
	cout<<"Transfer disc "<<n<<" from "<<src<<" to "<<dest<<".\n\n";
	cin.ignore();
	TowerofHanoi(n - 1, helper, src, dest);
}
int main() {
	int discs;
	cout<<"\nEnter number of discs for this game: ";
	cin>>discs;
	system("cls");
	cout<<"\n";
	TowerofHanoi(discs, "A", "B", "C");
	return 0;
}