#include<iostream>
using namespace std;

void print6(int n) {
	// Write your code here
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cout << j << " ";
		}
        cout << endl;
	}

}
void print7(int n){
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cout << " * ";
		}
		// for(int k=1;k<=i;k++){
		// 	cout << "* ";
		// }
        cout << endl;
	}
}
void print14(int n){
    for (int i = 0; i <= n; i++){
       for (char ch = 'A'; ch <= 'A' + i ; ch++)
       {
            cout<< ch << " ";
       }
       cout << endl;
    }
    
}
void print17(int n){
    for(int i=0; i<n; i++){
        //spaces
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        
        //characters
        char ch ='A';
        int breakpoint = (2*i+1)/2;
        for(int j=1; j<=2*i+1; j++ ){
            cout << ch;
            if(j <= breakpoint) ch++;
            else ch--;
        }
        //spaces
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
        


}
int main(){
    int n ;
    cin >> n;
    print17(n);

}