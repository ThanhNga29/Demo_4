#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;
int n, a[100][100];
vector<pair<int,int> > Dscanh;
vector<int> Dske[100];
void Nhap(){
	ifstream filein("TH1-2_input.txt");
	string s, tam;
	getline(filein, s);
	n = stoi(s);
	while(getline(filein, s)){
		stringstream st(s);
		vector<int> v;
		while(st >> tam){ 
			v.push_back(stoi(tam));
		}
		int d = v[0];
		for(int i = 1; i < v.size(); i++){
			a[d][v[i]] = 1;
		}
	}
}
bool Ktrahuong(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] != a[j][i]) return 0;
		}
	}
	return 1;
}
int main(){
	Nhap();
	if(Ktrahuong()){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(a[i][j]==1 && i < j){
					Dscanh.push_back({i, j});
					Dske[i].push_back(j);
					Dske[j].push_back(i); 
				}
			}
		}
		cout << "---**Do thi da nhap la do thi vo huong **--\n";
	}
	else{
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(a[i][j]){
					Dscanh.push_back({i, j});
					Dske[i].push_back(j);
				}
			}
		}
		cout << "\n--** Do thi da nhap la do thi co huong **--\n";
	}
	cout << "<--** Danh sach canh **-->\n";
	for(pair<int,int> p : Dscanh){
		cout << p.first << " " << p.second << endl;
	}
	cout << "<--** Ma tran ke **-->\n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "<--** Danh sach ke **-->\n";
	for(int i = 1; i <= n; i++){
		cout << i << ":";
		for(int x : Dske[i]){
			cout << x << " ";
		}
		cout << endl;
	}
	if(Ktrahuong()){
		cout<<"\n <--** Bac cua do thi vo huong **-->\n";
		for(int i = 1; i<=n;i++){
		int dem = 0;
		for(int x : Dske[i]){
			dem++;
		}
		cout << i << ":" << dem << endl;
		}
	}
	else{
		cout<<"\n <--** Bac cua do thi co huong **--> \n";
		for(int i = 1; i <= n; i++){
			int bacra = 0, bacvao = 0;
			for(int j = 1; j <= n; j++){ 
				bacra += a[i][j]; bacvao += a[j][i];
			}
			cout << i << " Ban bac ra : " << bacra << ", Ban bac vao : " << bacvao << endl;
		}
	}
}
