#include <iostream>
#include <Eigen/Dense>
using Eigen::MatrixXd;
class matrix{
public:	
	int line;//矩阵行数 
	int row;//矩阵列数 
	MatrixXd mat;//矩阵
	matrix(){
		line=0;
		row=0;
	}
	matrix(int x,int y){//矩阵构造函数 
		if(x>0&&y>0){
			line=x;
			row=y;
		}
		mat.resize(x,y);
	}
	matrix(const class matrix& m){
		line=m.line;
		row=m.row;
		mat=m.mat;
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
	void deleteDisjunction(int select_attribute){
		//输入：指定属性的DF下标索引
		//处理：将对象中的矩阵存储的含有该属性的析取式(从后往前)删除
		//输出：无 
		int time=0;
		for(int i=1;i<line;i++)
			if(mat(i,select_attribute)!=0)
				time++;
		MatrixXd tempMat(line-time,row);
		int j=0;
		for(int i=1;i<line;i++){
			if(mat(i,select_attribute)==0)
				tempMat.row(j++)=mat.row(i);
		}
		line=line-time; 
		mat=tempMat;
	}
	bool deleteAttribute(int select_attribute){
		//输入：指定属性的DF下标索引
		//处理：对于对象中的矩阵存储的含有该属性的析取式进行处理（删除该属性） 
		//输出：是否含有空的析取式 ：flag=true表示含有空析取式，否则表示没有 
		bool flag=false;
		for(int i=1;i<line;i++){
			if(mat(i,select_attribute)!=0){
				mat(i,select_attribute)=0;
				for(int j=0;j<row;j++){ 
					flag=flag|(bool)mat(i,j);//只要有一个为1，那么就表明该析取式不为空 
					if(flag) break;
				}
				if(!flag){//当前析取式为空 
					flag=true;
					return flag;
				} 
			}
		}
	}
};
//int main()
//{
//    matrix m(2,2);
//    m.mat(0,0) = 3;
//    m.mat(1,0) = 2.5;
//   	m.mat(0,1) = -1;
//    m.mat(1,1) = m.mat(1,0) + m.mat(0,1);
//    std::cout <<"mat\n"<< m.mat << std::endl;
//    std::cout <<"mat\n"<< m.mat << std::endl;
//    std::cout<< "mat block\n"<<m.mat.block(0,0,1,1)<<std::endl;
//    std::cout<< "mat col\n"<<m.mat.col(1)<<std::endl;
//    std::cout<<"mat row 0\n"<<m.mat.row(0)<<std::endl;
////    m.mat.row(0)=m.mat.row(1);
////    std::cout<< "mat row 0\n"<<m.mat.row(0)<<std::endl;
////    m.deleteLine(0);
////    std::cout <<"mat\n"<< m.mat << std::endl;
//	m.deleteRow(0);
//	std::cout <<"mat\n"<< m.mat << std::endl;
//    return 0;
//}

