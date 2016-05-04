#include <Eigen/Dense>
using namespace Eigen;
void computeSIG(MatrixXd& Sig,MatrixXd& DF){
	 Sig.row(0)=DF.row(0);//存储DF的属性序
	 for(int i=0;i<DF.cols();i++){//计算出现频率 
	 	Sig(1,i)=0;
	 	for(int j=1;j<DF.rows();j++)
	 		Sig(1,i)+=DF(j,i);
	 }
	 //依据属性出现的频率对属性进行选择排序
	 int subscript;
	 for(int i=0;i<Sig.cols();i++){
	 	subscript=i;
	 	for(int j=i+1;j<DF.cols();j++){
	 		if(Sig(1,subscript)<Sig(1,j))
	 			subscript=j;
		 }
		MatrixXd temp=Sig.col(0);
		 if(subscript!=i){
			Sig.col(subscript).swap(Sig.col(i));
		 } 
	 }
}
