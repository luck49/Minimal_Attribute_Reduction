#include<iostream>
#include"matrix.h"
using namespace std;
void computeSIG(class matrix& Sig,const class matrix& DF){
	 Sig=*(new matrix(3,DF.row));
	 Sig.mat.row(1)=DF.mat.row(1);//存储DT属性序
	 for(int i=0;i<Sig.row;i++){//计算出现频率 
	 	Sig.mat(2,i)=i;
	 	Sig.mat(3,i)=0;
	 	for(int j=1;j<DF.line;j++)
	 		Sig.mat(3,i)+=DF.mat(j,i);
	 }
	 //依据属性出现的频率对属性选择排序
	 int index;
	 MatrixXd temp(3,1);
	 for(int i=0;i<DF.row;i++){
	 	index=i;
	 	for(int j=i+1;j<DF.row;j++){
	 		if(Sig.mat(3,index)<Sig.mat(3,j))
	 			index=j;
		 }
		 if(index!=i){
		 	temp=Sig.mat.col(index);
		 	Sig.mat.col(index)=Sig.mat.col(i);
		 	Sig.mat.col(i)=temp;
		 } 
	 }
}
