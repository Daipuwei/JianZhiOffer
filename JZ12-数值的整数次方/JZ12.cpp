#include <iostream>
#include <cmath>
using namespace std;

class Solution {
	public:
		
		bool equal(double m,double n){
			return fabs(m-n) < 0.000001;
		} 
		
		double Power_unsigned(double base, int exponent){
			if(exponent == 0){
				return 1.0;
			}else if(exponent == 1){
				return base;
			}else{
				double result = this->Power_unsigned(base,exponent >> 1);
				result *= result;
				if(exponent & 0x1 == 1){ // exponentÎªÆæÊý 
					result *= base; 
				}
				return result;
			}
		}
		
	    double Power(double base, int exponent) {
	    	if(exponent == 0 && this->equal(base,0.0)){
	    		return 0.0;
			}
			bool flag = (exponent < 0 )? true:false;
			unsigned int abs_exponent = (unsigned int)(exponent);
			if(flag){
				abs_exponent = (unsigned int)(-exponent);
			}
			
			double result = this->Power_unsigned(base,abs_exponent);
			if(flag){
				result = 1.0 / result;
			}
			return result;
	    }
	    
};

int main(){
	double m;
	int n;
	Solution s;
	while(cin>>m>>n){
		cout<<s.Power(m,n)<<endl;	
	}
	
	return 0;
} 
