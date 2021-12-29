public class segmentree  
{  
final int MAX_SIZE = 100;      
int t[] = new int[MAX_SIZE]; 
int lazy[] = new int[MAX_SIZE];   
void updateRangeUtil(int currNode, int x, int y, int s, int e, int val)  
{  

if (lazy[currNode] != 0)  
{  
t[currNode] += (y - x + 1) * lazy[currNode];  
 
if (x != y)  
{  

lazy[2 * currNode + 1] += lazy[currNode];  
lazy[2 * currNode + 2] += lazy[currNode];  
}  

lazy[currNode] = 0;  
}  

if (x > y || x > e || y < s)  
{  
return;  
}  

if (x >= s && y <= e)  
{  

t[currNode] += (y - x + 1) * val;  

if (x != y)  
{  

lazy[2 * currNode + 1] += val;  
lazy[2 * currNode + 2] += val;  
}  
return;  
}  
 
int mid = (x + y) / 2;  
updateRangeUtil(2 * currNode + 1, x, mid, s, e, val);  
updateRangeUtil(2 * currNode + 2, mid + 1, y, s, e, val);  
 
t[currNode] = t[2 * currNode + 1] + t[2 * currNode + 2];  
}  

void updateRange(int n, int x, int y, int val)   
{  
updateRangeUtil(0, 0, n - 1, x, y, val);  
}  
 
int getSumUtil(int x, int y, int s, int e, int si)  
{  

if (lazy[si] != 0)  
{  

t[si] += (y - x + 1) * lazy[si];  

if (x != y)  
{  

lazy[2 * si + 1] += lazy[si];  
lazy[2 * si + 2] += lazy[si];  
}  
 
lazy[si] = 0;  
}  

if (x > y || x > e || y < s)  
{  
return 0;  
}  

if (x >= s && y <= e)  
{  
return t[si];  
}  

int mid = (x + y) / 2;  
return getSumUtil(x, mid, s, e, 2 * si + 1) +  
getSumUtil(mid + 1, y, s, e, 2 * si + 2);  
}  

int getSum(int s, int x, int y)  
{  

if (x < 0 || y > s - 1 || x > y)  
{  
System.out.println("Input is Invalid");  
return -1;  
}  
return getSumUtil(0, s - 1, x, y, 0);  
}  
  
void constructSTUtil(int a[], int x, int y, int si)  
{  

if (x > y)  
{  
return;  
}  

if (x == y)  
{  
t[si] = a[x];  
return;  
}  

int m = (x + y) / 2;  
constructSTUtil(a, x, m, 2 * si + 1);  
constructSTUtil(a, m + 1, y, 2* si + 2);  
t[si] = t[2 * si + 1] + t[2 * si + 2];  
}  

void constructST(int a[], int s)  
{  

constructSTUtil(a, 0, s - 1, 0);  
}  
 
public static void main(String argvs[])  
{  
int a[] = {2, 4, 7, 10, 12, 13};  
int s = a.length;  

segmentree tObj = new segmentree();  
 
tObj.constructST(a, s);  
 
System.out.println("The sum of the values in the given range is: " +  
tObj.getSum(s, 1, 4));  

tObj.updateRange(s, 1, 5, 7);  

System.out.println("The sum of the values, after updation, in the given range is: " +  
tObj.getSum(s, 1, 4));  
}  
}  