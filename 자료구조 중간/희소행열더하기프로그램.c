#include <stdio.h>

typedef struct{
    int row;        //행 
    int col;        //열 
    int value;      //값 
} element;

typedef struct{
    element a[100];     //a라는 이름의 각 행 구조체 100개 선언 
    int rows;       //행의 개수 
    int cols;       //열의 개수 
    int terms;      //항의 개수 
} SparseMatrix;

int main(void){                         
    SparseMatrix tableA, tableB, tableC, tableD;    //희소행렬 구조체 2개 선언    C는 합한희소행렬, D는 tmp희소행렬
    
//    tablesA.a[0].row = 1;
    int n, m;
    scanf("%d %d", &n, &m);     //두 희소행렬의 행 개수와 열 개수입력 //좌표크기설정  
    tableA.rows, tableB.rows = n;
    tableA.cols, tableB.cols = m;
    
    int s;
    scanf("%d", &s);        //첫번째 희소행렬의 항의 개수 입력
    tableA.terms = s;
    for(int i = 0; i < s; i++){
        scanf("%d %d %d", tableA.a[i].row, tableA.a[i].col, tableA.a[i].value); //s번반복 - 첫번째희소행렬의 행 열 값 입력 
    }
    
    int t;
    scanf("%d", &t);    //두번째 희소행렬의 항의 개수 입력
    tableB.terms = t;
    for(int i = 0; i < t; t++){
        scanf("%d %d %d", tableB.a[i].row, tableB.a[i].col, tableB.a[i].value); //t번반복 - 두번째희소행렬의 행 열 값 입력 
    }
    
    //tableC의 항개수 구하기 : tableA의 항개수와 tableB의 항개수를 비교해 큰쪽을 tableC의 항개수로두고 
    //아닌쪽의 항개수만큼 반복해서 두 희소행렬의 행과 열을 비교하여 서로 다른경우 tableC의 항개수+1 
    int left;
    if(tableA.terms > tableB.terms){
        tableC.terms = tableA.terms;
        left = tableB.terms;
    } else if(tableB.terms > tableA.terms || tableB.terms == tableA.terms){
        tableC.terms = tableB.terms;
        left = tableA.terms;
    }
    
    for(int i = 0; i < left; i++){
        if(tableA.a[i].row != tableB.a[i].row || tableA.a[i].col != tableB.a[i].col){
            tableC.terms += 1;
        }
    }
    //만약 두 구조체의 같은 항의 행과 열이 같다면 값을 더하여 새 구조체에 저장
    //=만약 tableA와 tableB의 같은 항의 row와 col이 같다면 value를 더해서 tableC의 value에저장
    
    //두 구조체의 항의개수를 비교해서 큰쪽을 기준으로, 큰쪽의 항의개수만큼 반복: 작은쪽의 행과열이 큰쪽의 행과열과 같다면 value를 더해서 저장
    if(tableA.terms > tableB.terms){
        tableC = tableA;
        tableD = tableB;
    } else if(tableB.terms > tableA.terms || tableB.terms == tableA.terms){
        tableC = tableB;
        tableD = tableA;
    }
    
    for(int i = 0; i < tableC.terms; i++){
        for(int j = 0; j < tableD.terms; j++){
                if(tableD.a[j].row == tableC.a[i].row && tableD.a[j].col == tableC.a[i].col){
                tableC.a[i].value += tableD.a[j].value;
            }
        }
    }
    
    //합한 희소행렬의 항개수와 행 열 값 출력 
    printf("%d\n", tableC.terms);
    
    for(int i = 0; i < tableC.terms; i++){
        printf("%d %d %d\n", tableC.a[i].row, tableC.a[i].col, tableC.a[i].value);
    }
  
    return 0;
}