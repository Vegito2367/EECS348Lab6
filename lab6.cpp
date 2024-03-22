#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int** createArray(int rows, int cols) {
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

void deleteArray(int** arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

string readFile(string filename,string (&lines)[8])
{
  int i = 0;
  string line;
  ifstream myfile (filename);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      lines[i]=line;
      i++;
    }
    myfile.close();
  }
  
}

void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void addMatrix(int **matrix1, int **matrix2, int n) {
    int** result = createArray(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix(result, n);
}

void multiplyMatrix(int **matrix1, int **matrix2, int n) {
    int** result = createArray(n, n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        for (int k=0;k<n;k++)
        {
          result[i][j]+=matrix1[i][k]*matrix2[k][j];
        }
      }
      
    }
    
    printMatrix(result, n);
}

void transposeMatrix(int **matrix, int n) {
    int** result = createArray(n, n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        result[i][j]=matrix[j][i];
      }
    }
    printMatrix(result, n);
}

void SubtractionMatrix(int **matrix1, int **matrix2, int n) {
    int** result = createArray(n, n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        result[i][j]=matrix1[i][j]-matrix2[i][j];
      }
    }
    printMatrix(result, n);
}

void UpdateElement(int **matrix, int row, int col, int value, int n) {
    matrix[row][col]=value;
    printMatrix(matrix, n);
}

void MaxValue(int** matrix, int n) {
    int max=matrix[0][0];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if(matrix[i][j]>max)
          max=matrix[i][j];
      }
    }
    cout<<max<<endl;
}

int main()
{
  string lines[8];
  string filename="input.txt";
  
  readFile(filename,lines);

  
  int size=stoi(lines[0]);

  int **matrix1 = createArray(size,size);
  int **matrix2 = createArray(size,size);
  for (int i = 1;i<7;i++)
  { 
      int startindex=0;
      string myStr=lines[i]+" ";
      int spaceIndex=0;
      int arrlen=0;
            int num=0;
            while(myStr.length()>1)
            {
              startindex=0;
              spaceIndex=myStr.find(" ");
              num=stoi(myStr.substr(startindex,spaceIndex-startindex));
              if(i<4)
                matrix1[i-1][arrlen]=num;
              else
                matrix2[i-4][arrlen]=num;

              arrlen++;
              startindex=spaceIndex+1;
              myStr=myStr.substr(startindex);
            }
  }


  std::cout<<endl;
  transposeMatrix(matrix1,size);


  return 0;
}