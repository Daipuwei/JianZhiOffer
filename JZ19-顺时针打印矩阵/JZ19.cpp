#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    vector<int> printMatrix(vector<vector<int> > matrix) {
			vector<int> result;
			if(matrix.size() == 0){
				return result;
			}
			int row1 = 0, row2 = matrix.size();
			int col1 = 0, col2 = matrix[0].size();
			while(1){
				for(int i = col1 ; i < col2 ; i++){
					result.push_back(matrix[row1][i]);
				}
				row1++;
				if(row1 >= row2){
					break;
				}
				
				for(int i = row1 ; i < row2 ; i++){
					result.push_back(matrix[i][col2-1]);
				}
				col2--;
				if(col2 <= col1){
					break;
				}
				
				for(int i = col2-1 ; i >= col1 ; i--){
					result.push_back(matrix[row2-1][i]);
				}
				row2--;
				if(row2 <= row1){
					break;
				}
				
				for(int i = row2-1 ; i >= row1 ; i--){
					result.push_back(matrix[i][col1]);
				}
				col1++;
				if(col1 >= col2){
					break;
				}
			}
			return result; 
	    }
};

int main(){
	int n;
	while(cin>>n){
		vector<vector<int> > matrix;
		for(int i = 0; i < n ; i++){
			vector<int> array(n);
			for(int j = 0 ; j < n ; j++){
				cin>>array[j];
			}
			matrix.push_back(array);
		}
		Solution s;
		vector<int> array = s.printMatrix(matrix);
		for(int i = 0 ; i < array.size() ; i++){
			cout<<array[i]<<" ";
		}	
	} 
	
	return 0;
}
