struct node{
    int st;
    int end;
    int s;
};
void initialize(vector<int> &A, int &ptr1, int &ptr2, int j){
    while( j < A.size()){
        if (a[j]>0){
            sum = a[j];
            ptr1 = j;
            ptr2 = j+1;
            break;
        }
        j++;
    }   
}
vector<int> Solution::maxset(vector<int> &A)
{
int ptr1=0, ptr2=1, j=0;
struct node** a = new node*[10000];
float sum=0.0;
initialize(&A, &ptr1, &ptr2, 0)

sum = a[ptr1];
int temp = sum;
int itr = 0;
for (int i=0; i<A.size(); i++){
    sum = sum + a[ptr2];
    if (temp  >  sum){
        a[itr]->st = ptr1;
        a[itr]->end = ptr2;
        a[itr]->s = temp;
        initialize(&A, &ptr1, &ptr2, ptr2+1)
    }
    
    temp = sum;
}