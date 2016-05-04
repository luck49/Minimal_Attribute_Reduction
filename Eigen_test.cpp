//这个程序主要用以Eigen矩阵的功能使用测试，因为刚开始不习惯row表示行col表示列，特意自己写了个类，用line表示行，row表示列，以更好的完成过渡
#include <iostream>
#include <Eigen/Dense>
using Eigen::MatrixXd;
class Matx{
public:	
	int line;//矩阵行数 
	int row;//矩阵列数 
	MatrixXd mat;//矩阵

	Matx(int x,int y){//矩阵构造函数 
		if(x>0&&y>0){
			line=x;
			row=y;
		}
		mat.resize(x,y);
	}
	void deleteLine(int select_line){
		//输入:指定行的下标索引 
		//处理：删除本类中矩阵中指定的行 
		//输出：无
		MatrixXd tempMat;
		line=line-1;
		tempMat.resize(line,row);
		int j=0;
		for(int i=0;i<=line;i++)
			if(i==select_line)
				continue;
			else tempMat.row(j++)=mat.row(i);
		this->mat=tempMat;
	}
	void deleteRow(int select_row){
		//输入:指定列的下标索引 
		//处理：删除本类中矩阵中指定的列 
		//输出：无
		MatrixXd tempMat;
		row=row-1;
		tempMat.resize(line,row);
		int j=0;
		for(int i=0;i<=row;i++)
			if(i==select_row)
				continue;
			else tempMat.col(j++)=mat.col(i);
		this->mat=tempMat;
	}
};
int main()
{
    Matx m(2,2);
    m.mat(0,0) = 3;
    m.mat(1,0) = 2.5;
   	m.mat(0,1) = -1;
    m.mat(1,1) = m.mat(1,0) + m.mat(0,1);
    std::cout <<"mat\n"<< m.mat << std::endl;
    std::cout<< "mat block\n"<<m.mat.block(0,0,1,1)<<std::endl;
    std::cout<< "mat col\n"<<m.mat.col(1)<<std::endl;
    std::cout<<"mat row 0\n"<<m.mat.row(0)<<std::endl;
//    m.mat.row(0)=m.mat.row(1);
//    std::cout<< "mat row 0\n"<<m.mat.row(0)<<std::endl;
//    m.deleteLine(0);
//    std::cout <<"mat\n"<< m.mat << std::endl;
	m.deleteRow(0);
	std::cout <<"mat\n"<< m.mat << std::endl;
    return 0;
}
