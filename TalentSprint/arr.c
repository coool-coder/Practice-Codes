int** performOps(int **A, int m, int n, int *len1, int *len2) {
    int i, j;
    *len1 = m;
    *len2 = n;
    int **B = (int **)malloc((*len1) * sizeof(int *));
    for (i = 0; i < *len1; i++) {
        B[i] = (int *)malloc((*len2) * sizeof(int));
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            B[i][n - 1 - j] = A[i][j];
        }
    }
    return B;
}

int main(){
    int a[1000][1000]={[[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]};
    int B[1000][1000];
    B =  performOps(a, 4, 5, );
}
