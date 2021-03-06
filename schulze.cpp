#include <iostream>

using namespace std;
#define C 5

void print(int A[C][C])
{
  cout<<endl;
  for(int i=0;i<C;i++)
    {
      for(int j=0;j<C;j++)
	cout<<A[i][j]<<' ';
      cout<<endl;
    }
}
int max(int a,int b)
{
  if(a>b)
    return a;
  else
    return b;
}

int min(int a,int b)
{
  if(a<b)
    return a;
  else return b;
}


int main()
{
  int n;
  int p[C][C],d[C][C]={0};

  cin>>n; //number of votes

  for(int k=0;k<n;k++)
    {
      char vote[C];
      cin>>vote;
      int flag = 0;
      for(int i=0;i<C;i++)
	  for(int j=i+1;j<C;j++)
	    if(vote[i]==vote[j])
	      flag=1;//repeated vote
      if(flag==0)
	for(int i=0;i<C;i++)
	  for(int j=i+1;j<C;j++)
	    d[vote[i]-'A'][vote[j]-'A']++;
    }
   print(d);
  
  for(int i=0;i<C;i++)
	  for(int j=0;j<C;j++)
	    if(i!=j && d[i][j]>=d[j][i])
	      p[i][j]=d[i][j];
	    else
	      p[i][j]=0;

  // print(p);

  for(int i=0;i<C;i++)
    for(int j=0;j<C;j++)
      if(i!=j)
	for(int k=0;k<C;k++)
	  if(i!=k && j!=k)
	    p[j][k] = max(p[j][k],min(p[j][i],p[i][k]));
  print(p);

  char Result[C];
  for(int i=0;i<C;i++)
    {
      int zeroes = 0;
      for(int j=0;j<C;j++)
	if(p[i][j]==0)
	  zeroes++;
    
      Result[zeroes-1]=('A'+i);
    }
  cout<<Result<<endl;
}
