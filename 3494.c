#include <stdio.h>
#include <stack>
using namespace std;
int m, n;
int matrix[2002][2002];
int num1[2002][2002];
int num2[2002][2002];
int temp[2002];
typedef pair<int, int> pii;
stack<pii> s;

void work(){
    int i, j;
    for(i = m-1; i > 0; i--){
        for(j = 0; j < n; j++){
            if(matrix[i][j] != 0 && matrix[i-1][j] != 0){
                matrix[i-1][j] += matrix[i][j];
            }
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(s.empty()){
                if(matrix[i][j] != 0)
                    s.push(make_pair(matrix[i][j], j));
                continue;
            }
            if(s.top().first > matrix[i][j]){
                num1[i][s.top().second] = j - s.top().second;
                s.pop();
                j--;
            }
            else{
                s.push(make_pair(matrix[i][j], j));
            }
        }
        while(!s.empty()){
            num1[i][s.top().second] = n - s.top().second;
            s.pop();
        }
    }
    for(i = 0; i < m; i++){
        for(j = n-1; j >= 0; j--){
            if(s.empty()){
                if(matrix[i][j] != 0)
                    s.push(make_pair(matrix[i][j], j));
                continue;
            }
            if(s.top().first > matrix[i][j]){
                num2[i][s.top().second] = s.top().second - j;
                s.pop();
                j++;
            }
            else{
                s.push(make_pair(matrix[i][j], j));
            }
        }
        while(!s.empty()){
            num2[i][s.top().second] = s.top().second+1;
            s.pop();
        }
    }
    int max = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            int temp = matrix[i][j] * (num1[i][j]+num2[i][j]-1);
            if(temp > max){
                max = temp;
            }
        }
    }
    printf("%d\n", max);
}

int main(){
    while(scanf("%d %d\n", &m, &n) != EOF){
        int i, j;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                scanf("%d", &matrix[i][j]);
            }
        }
        work();
    }
    return 0;
}