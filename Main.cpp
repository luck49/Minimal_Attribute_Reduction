#include <iostream>
#include <Eigen/Dense>
#include "Reduct.h"
using namespace Eigen;  
using namespace std;
int input(MatrixXd& mat,const char* filename);
void CAMARDF(MatrixXd& DF);
class Reduct *reduct,*minReduct;
int main(int argc, char** argv) {
	MatrixXd DF;
	int num_attr=input(DF,"breast_w_matrix.txt");
	cout<<"program had got matrix from textfile successfully! \n";
	reduct=new Reduct(num_attr,0);
	minReduct=new Reduct(num_attr,DF.cols());
	CAMARDF(DF);
	cout<<"success in getting the reduct!\n";
	minReduct->disp();
	system("pause");
	return 0;
}

