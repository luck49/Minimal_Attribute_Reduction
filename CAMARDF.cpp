#include "Reduct.h"
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
extern class Reduct* reduct,*minReduct;
void computeSIG(MatrixXd& Sig,MatrixXd& DF);
void delete_disjunction(MatrixXd& DF,int index,int times);
void delete_attribute(MatrixXd& DF,int index);
extern int node_num;
void CAMARDF(MatrixXd& DF){
//额外说明：此算法实现周杰的最小约简求取算法。 
//输入:不存在包含关系的析取式组
//输出:最小约简
//处理：搜索最小约简，使用拓展律进行宽度剪枝,使用问题与解空间的比率深度剪枝 

//Sig矩阵的存储处理：第一行为属性在DT中的下标，
//					第二行为属性的出现次数
//					涉及操作：根据Sig第一行中的DT属性索引搜索DF中的属性索引

	MatrixXd Sig(2,DF.cols());
	computeSIG(Sig,DF);//计算属性出现的频率，并按降序排列
	//cout<<Sig<<endl;
	int i=0;
	while ((Sig(1,i)>1 && i<Sig.cols())||i==0){
		//深度剪枝 
		//临时约简存储中加入最大出现次数的属性，实质上为贪心算法求取近似的最小约简，从而剪枝
		if(reduct->length+1==minReduct->length){
				return ;
		}
		int index=(int)Sig(0,i);
		int index0;
		for(int i=0;i<DF.cols();i++){
			if(DF(0,i)==index){
				index0=i;//更新DT属性索引为DF属性索引
				break;
			}
		}
		node_num++;
		reduct->attribute[index]=1;
		reduct->length++;
		//开始深度递归，删除含有该元素的所有析取式 
		MatrixXd tempDF(DF);
		delete_disjunction(tempDF,index0,(int)Sig(1,i)); //删除析取矩阵中含有该属性的析取式
		if(tempDF.rows()==1){
			if(reduct->length<minReduct->length){
				//printf("reduct length: %d minReduct length: %d \n",reduct->length,minReduct->length);
				minReduct->update(reduct);
				printf("Getting new result, Change the minReduct:");
				minReduct->disp();
			}
		}
		else{
			CAMARDF(tempDF);
		}
		//宽度搜索剪枝，析取矩阵删除该元素
		delete_attribute(DF,index0);
		bool flag=false;//检查是否存在析取式为空
		for(int i=1;i<DF.rowwise().any().rows();i++){
			if(DF.rowwise().any()(i,0)==0)
				flag=true;
		}
		if(flag){//存在空析取式，终止循环（宽度剪枝）
			reduct->attribute[index]=0;//删除该属性，结束搜索 
        	reduct->length--;
			return;
		}
		reduct->attribute[index]=0;
    	reduct->length--;
    	i=i+1;
	}
}
void delete_disjunction(MatrixXd& DF,int index,int times){
	//输入：一个析取矩阵,属性在DT中的索引，属性出现的次数
	//输出：一个析取矩阵
	//处理：根据DT中的属性索引搜索DF中的属性索引，删除包含指定属性的行（析取式）
	MatrixXd tempDF(DF.rows()-times,DF.cols());
	int temp_index=1;
	tempDF.row(0)=DF.row(0);
	for(int i=1;i<DF.rows();i++){
		if(DF(i,index)==0){
			tempDF.row(temp_index++)=DF.row(i);
		}
	}
	DF.resize(tempDF.rows(),tempDF.cols());
	DF=tempDF;
}

void delete_attribute(MatrixXd& DF,int index){
	//输入：一个析取矩阵,属性在DT中的索引
	//输出：一个析取矩阵
	//处理：根据给定的DT属性索引搜索得到DF索引，后删除析取矩阵中该属性的列
	
	//使得需要删除的列是最后一列
	for(int i=index;i<DF.cols()-1;i++){
		DF.col(i)=DF.col(i+1);
	}//删除一列
	MatrixXd tempDF(DF.rows(),DF.cols()-1);
	tempDF=DF.block(0,0,DF.rows(),DF.cols()-1);
	DF.resize(tempDF.rows(),tempDF.cols());
	DF=tempDF;
}
