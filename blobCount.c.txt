#include <stdio.h>

int srch();
int main()
{
    int r , c , i , j;
    scanf("%d %d" , &r , &c);
    char grid[r][c];
    for(i=0 ; i<r ; i++){
        for(j=0 ; j<c ; j++){
            grid[i][j] = ' ';
        }
    }

    int rw , cl;
    scanf("%d" , &rw);
    if(rw >= 0){
        scanf("%d" , &cl);
    }
    
    while(rw >= 0){
        grid[rw][cl] = '*';
        scanf("%d" , &rw);
        if(rw >= 0){
            scanf("%d" , &cl);
        }
    }
    
    int save[r*c];
    int index = 0;
    for(i=0 ; i<r ; i++){
        for(j=0 ; j<c ; j++){
            if(grid[i][j] == '*'){
                grid[i][j] = ' ';
                int count = srch(r , c , grid , i , j , 1);
                save[index] = count;
                index++;
            }
        }
    }
    
    printf("%d " , index);
    for(j=0 ; j<index-1 ; j++){
        for(i=0 ; i<index-1 ; i++){
            if(save[i]>save[i+1]){
            int temp;
            temp = save[i];
            save[i] = save[i+1];
            save[i+1] = temp;
            }
	  }
    }
    for(i=0 ; i<index-1 ; i++){
        printf("%d " , save[i]);
    }
	printf("%d" , save[index-1]);
}

int srch(int r , int c , char arr[r][c] , int i , int j , int cnt)
{
    for(int y=-1 ; y<=1 ; y++){
        for(int x=-1 ; x<=1 ; x++){    
            if(i + y >= r)
                continue;
            if(i + y < 0)
                continue;
            if(j + x >= c)
                continue;
            if(j + x < 0)
                continue;
            if(arr[i+y][j+x] == '*'){
                arr[i+y][j+x] = ' ';
                cnt = srch(r , c , arr , i+y , j+x , cnt+1);
            } 
        }
    }
    return cnt;
}