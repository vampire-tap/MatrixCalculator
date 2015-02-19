#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#define MAX 10
using namespace std;

int main () {
  string line;
  char * pch;
  char * str;
  int count=0;
  ifstream myfile ("myfile.txt");
  int rc=0;
	int matrices[MAX][MAX][MAX];
    int first[10][10];  //first matrix
	int rows[MAX]={};
	int r=0;
	int cols[MAX]={};
	int c=0;
	int second[10][10]; //second matrix
	int third[10][10];
	int sum2[10][10];
	int sum[10][10]; //the sum matrix
	int multiply[10][10];//the resultant of the multiplication of first and second
	int mandadd[10][10];//the resultant of (multiplication of the first and second) + (third)
	int sum1 = 0;//sum calculated during the multiplication of matrices
	int mc=0;

  if (myfile.is_open())
  {
	  cout << "READING ALL THE MATRICES IN THE FILE\n" << endl;
    while ( getline (myfile,line) )
    {
     // cout << line << '\n';
	  char *dup = strdup(line.c_str());
	  if (count%2==0){///////////////////
		  pch = strtok(dup, "x");
	   while (pch != NULL)
	  {
		if (rc%2==1){
		cols[c]=atoi(pch);
		//printf("Adding in cols %d\n",atoi(pch));
		c++;
		}
		if (rc%2==0){
		 rows[r]=atoi(pch);
		 //printf("Adding in rows %d\n",atoi(pch));
		 r++;
		}
	    //printf ("%d\n",atoi(pch));
	    pch = strtok (NULL, "x");
		rc++;
      }
	  }////////////////////////////
	  if (count%2==1){
		  pch = strtok(dup, ";");
	    while (pch != NULL)
	  {
	   // printf ("%s\n",pch);

        for (int j=0; j < rows[mc] ; j++) {
		for (int k = 0; k < cols[mc] ; k++) {
			matrices[mc][j][k]=atoi(pch);
	}
	    }
	    pch = strtok (NULL, ";");

      }
		mc++;
	  }/////////////////////
      free(dup);

    count++;
    }
    myfile.close();

	for (int i=0; i<mc;i++){
		printf("MATRIX %d\n",i);
	    for (int j=0; j < rows[i] ; j++) {
			//printf("MATRIX %d-->rows are %d\n",i,rows[i]);
			for (int k = 0; k < cols[i] ; k++) {
				//printf("MATRIX %d-->cols are %d\n",i,cols[i]);
				cout << matrices[i][j][k] << "\t";
		        cout << endl;
			}
		}
	}
//////////////////////////////////////////////////////////
	printf("\n\nUNIT TEST #1\n");
	printf("ADDING THE FIRST TWO MATRICES\n\n");
	for (int i=0; i<1;i++){
		//printf("MATRIX %d\n",i);
	    for (int j=0; j < rows[i] ; j++) {
			//printf("MATRIX %d-->rows are %d\n",i,rows[i]);
			for (int k = 0; k < cols[i] ; k++) {
				//printf("MATRIX %d-->cols are %d\n",i,cols[i]);
				first[j][k]= matrices[i][j][k];
			}
		}
	}
	for (int i=1; i<2;i++){
		//printf("MATRIX %d\n",i);
	    for (int j=0; j < rows[i] ; j++) {
			//printf("MATRIX %d-->rows are %d\n",i,rows[i]);
			for (int k = 0; k < cols[i] ; k++) {
				//printf("MATRIX %d-->cols are %d\n",i,cols[i]);
				second[j][k]= matrices[i][j][k];
			}
		}
	}
	if(rows[0]==rows[1] && cols[0]==cols[1]){
    for (int c = 0; c < rows[0]; c++)
	for (int d = 0; d < cols[0]; d++)
		sum[c][d] = first[c][d] + second[c][d];

	cout << "\nSum of first two matrices:-\n";

	for (int c = 0; c < rows[0]; c++)
	{
		for (int d = 0; d < cols[0]; d++)
			cout << sum[c][d] << "\t";

		cout << endl;
	}}
	else{
		printf("\nERROR: THE ORDER OF THE MATRICES NEED TO BE SAME FOR ADDITION TO BE POSSIBLE\n\n");
	}
////////////////////////////////////////////////////////////
	printf("\n\nUNIT TEST #2\n");
	printf("MULTIPLICATION OF THE FIRST TWO MATRICES\n");


	if(cols[0]==rows[1]){

	for (int c = 0; c < rows[0]; c++)
	{
		for (int d = 0; d < cols[1]; d++)
		{
			for (int k = 0; k < cols[0]; k++)
			{
				sum1 = sum1 + first[c][k] * second[k][d];
			}

			multiply[c][d] = sum1;
			sum1 = 0;
		}
	}


	cout << "Product of the two matrices:-\n";

	for (int c = 0; c < rows[0]; c++)
	{
		for (int d = 0; d < cols[1]; d++)
			cout << multiply[c][d] << "\t";

		cout << endl;
	}}
	else{
		printf("\nERROR: THE COLUMNS OF THE FIRST MATRIX MUST BE EQUAL TO THE NUMBER OF ROWS OF THE SECOND MATRIX \n");
	}



///////////////////////////////////////////////////////////
	printf("\n\nUNIT TEST #3\n");
	printf("\MULTIPLYING THE FIRST TWO MATRICES AND THEN ADDING THE THIRD ONE\n");

	for (int i=2; i<3;i++){
		//printf("MATRIX %d\n",i);
	    for (int j=0; j < rows[i] ; j++) {
			//printf("MATRIX %d-->rows are %d\n",i,rows[i]);
			for (int k = 0; k < cols[i] ; k++) {
				//printf("MATRIX %d-->cols are %d\n",i,cols[i]);
				third[j][k]= matrices[i][j][k];
			}
		}
	}


	if(rows[0]==rows[2] && cols[1]==cols[2]){
    for (int c = 0; c < rows[2]; c++)
	for (int d = 0; d < cols[2]; d++)
		sum2[c][d] = third[c][d] + multiply[c][d];

	cout << "\nTHE SUM IS:-\n";

	for (int c = 0; c < rows[2]; c++)
	{
		for (int d = 0; d < cols[2]; d++)
			cout << sum2[c][d] << "\t";

		cout << endl;
	}}
	else{
		printf("\n\nERROR: THE ORDER OF THE MATRICES NEED TO BE SAME FOR ADDITION TO BE POSSIBLE\n\n\n");
	}
//////////////////////////////////////////////////////////
  }
   else cout << "Unable to open file";
  _getch();
  return 0;
}
