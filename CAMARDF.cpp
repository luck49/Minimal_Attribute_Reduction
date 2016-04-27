#include<iostream>
#include "matrix.cpp"
using namespace std;
extern class Reduct reduct,MinReduct;
void CAMARDF(class matrix& DF){
//额外说明：此算法实现周杰的最小约简求取算法。 
//输入:不存在包含关系的析取式组
//输出:最小约简
//处理：搜索最小约简，使用拓展律进行宽度剪枝,使用问题与解空间的比率深度剪枝 
	class matrix Sig;
//Sig矩阵的存储处理：第一行为属性在DT中的下标，
//					第二行为属性在DF的下标，
//					第三行为属性的出现次数
	computeSIG(Sig,DF);//计算属性出现的频率，并按降序排列
	int i=0;
	while ((Sig.mat(3,i)>1 && i<Sig.row)||i==0){
		//深度剪枝 
		if reduct.length+1==minReduct.length
			return;
		//临时约简存储中加入最大出现次数的属性，实质上为贪心算法 
		reduct.attribute(sig_attr(1,i))=1;
		reduct.length++;
		//开始深度递归，删除含有该元素的所有析取式 
		class matrix tempDF=DF;
		tempDF.deleteDisjunction(Sig.mat(2,i)); 
		if(tempDF.line==0){
			if(reduct.length<minReduct.length)
				minReduct=reduct;
		}
		else{
			CAMARDF(tempDF);
		} 
		//宽度搜索剪枝，析取矩阵删除该元素
		bool flag=DF.deleteAttribute(Sig.mat(2,i));
		if(flag){//存在析取式为空
			reduct.attribute(Sig.mat(1,i))=0;
        	reduct.length--;
			return;
		}
		reduct.attribute(Sig.mat(1,i))=0;
    	reduct.length--;
    	i=i+1;	
	}
	
}
