#include<iostream>
using namespace std;
class Reduct{
// 约简类,有属性组、长度两个属性
// 属性组为约简、长度为约简长度
public:
	int length;//约简长度
    int* attribute;//约简中包含的属性（为一属性数组）
    Reduct(){
    	length=0;
    	attribute=NULL;
	}
    Reduct(int num_attr,const int len){//构造函数，输入决策表中属性个数，约简长度
		length=len;
		attribute=new int[len];
		for(int i=0;i<len;i++)
			attribute[i]=0;
    }
    ~Reduct(){
    	delete[] attribute;
	}
    Reduct(const class Reduct& Red){
    	length=Red.length;
    	attribute=Red.attribute;
	}
};
    
