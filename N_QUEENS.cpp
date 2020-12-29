#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

int temp;

bool isValid(vector<int> Placed){
	
	for(int i = 0; i < Placed.size()-1; i++){
		for(int j = i+1; j<Placed.size(); j++){
			if((Placed[i] == Placed[j]) || abs((Placed[i]-Placed[j]))==abs(i-j) ) {/*cout<<"INVALID\n";*/ return false;}
		}
	}

	// cout<<"VALID\n";
	return true;
}


void recursive(int N, int r, vector<int> &Placed, vector<int> &Final){

	// cout<<"ENTERED RECURSIVE\n";
	if(r == N){
		Final.insert(Final.end(), Placed.begin(), Placed.end());
		// cout<<"INSERTED\n";
	}
	else{

		for(int col = 0; col< N; col++){
			Placed.emplace_back(col);
			// cout<<"EMPLACED "<<col<<"\n";
			if(isValid(Placed)){
				recursive(N,r+1,Placed,Final);
			}
			Placed.erase(Placed.end()-1);

		}
	}
}

int main(){

	int T, N;
	std::cin>>T;
	while(T-- ){

		std::cin>>N;
		std::vector<int> Placed;
		std::vector<int> Final;

		// cout<<"HELLO1\n";

		recursive(N, 0,Placed,Final);

		// cout<<"HELLO2\n";

		cout<<Final.size()/N<<"\n";

		for(int i= 0; i< Final.size(); i+=N){


				 // GRID PRINTING FUNCTION
				for(int j  = 0; j<N;j++){
					for(int k = 0; k<N; k++){
						if(k == Final[i+j])	cout<<"X ";
						else cout<<". ";
					}
					cout<<"\n";
				}
				cout<<"\n\n\n";

			// cout<<Final[i]<<"\n";

		}

	}
}