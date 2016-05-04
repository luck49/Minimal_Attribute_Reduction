#include<iostream>
class Reduct{
// 约简类,有属性组、长度两个属性
// 属性组为约简、长度为约简长度
public:
	int length;//约简长度
	int array_size;
    int* attribute;//约简中包含的属性（为一属性数组）
    Reduct(){
    	length=0;
		array_size=0;
    	attribute=NULL;
	}
    Reduct(int num_attr,int len){//构造函数，输入决策表中属性个数，约简长度
		length=len;
		array_size=num_attr;
		attribute=new int[array_size];
		for(int i=0;i<len;i++)
			attribute[i]=0;
    }
    void update(Reduct* red){
		length=red->length;
		for(int i=0;i<array_size;i++){
			attribute[i]=red->attribute[i];
		}
	}
	void disp(){
		for(int i=0;i<array_size;i++){
			if(attribute[i]==1)
				printf("%d ",i+1);
		}
		putchar(10);
	} 
};
    
