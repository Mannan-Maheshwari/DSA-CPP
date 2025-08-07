#include<iostream>
#include<climits>
using namespace std;

int countDigit(int n) {
        int w = 0;
        while(n>0){
           w = w +1;
           n = n/10;
        }
    return w;
    }

    int reverse(int x) {
        int revN =0;
        while(x>0){
            int lastdigit = x%10;
            x = x/10;
            revN = (revN*10) + lastdigit;
        }
        
    }

        bool isPalindrome(int x) {
        if (x<0) return false;
        int revN = 0;
        int dup =x;
        while(x!=0){
            int lastdigit = x%10;
            x = x/10;

            if (revN > INT_MAX/10 || revN < INT_MIN/10)
                return 0;
            revN = (revN*10) + lastdigit;
            
        }
        return revN == dup;
    }

int main(){
    cout <<  isPalindrome(122);
}

