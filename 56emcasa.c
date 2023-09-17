/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comparar(const void* a,const void* b){
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    qsort(intervals,intervalsSize,sizeof(int*),comparar);

    int** ret= (int**)malloc(sizeof(int*)*intervalsSize);
    if (intervals[0] != NULL){
        ret[0] = intervals[0];
    }

    int j = 1;
    
    for(int i = 1;i < intervalsSize;i++){
        if(intervals[i][0] <= ret[j-1][1]){
            ret[j-1][1] = intervals[i][1]>ret[j-1][1]?intervals[i][1]:ret[j-1][1];
        }
        else{
            ret[j++] = intervals[i];
        }
    }

    *returnSize = j;
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i = 0;i < *returnSize;i++){
        (*returnColumnSizes)[i] = 2;
    }

   
    return ret;
}
