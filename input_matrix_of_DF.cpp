#include<fstream>
#include<ctype.h>
#include <Eigen/Dense>
#include "matrix.cpp"
using Eigen::MatrixXd;
using namespace std;
/*
输入：一个txt文件，第一行包含着析取矩阵的规模大小；从第二行开始为析取矩阵的内容 
输出：一个析取矩阵（以matrix类定义的方式存储） 
处理： 将析取矩阵读入到内存 
*/
class matrix& input(char* filename)
{
	ifstream fin;
	fin.open(filename,ios::in);
	if(fin.bad()){
		printf("error in file reading -- from 'input.cpp'\n!");
		exit(0);
	}
	int line=0,row=0;//记录矩阵的行数和列数 
	fin>>line>>row;//输入析取矩阵的行数和列数
	class matrix *amat=new matrix(line,row); 
	for(int i=0;i<line;i++){
		for(int j=0;j<row;j++){
			fin>>amat->mat(i,j);
		}
	}
	fin.close();
	return *amat;
}
int main()
{
	class matrix amat=input("breast_w_matrix.txt");
	cout<<"get matrix successfully! \n"<<amat.mat<<endl;
//	delete &amat;
	return 0;
}
