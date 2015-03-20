#include <vector>
#include <iostream>
using namespace std;


vector<int> merge(vector<int> &vec,const vector<int>& left, const vector<int>& right);

vector<int> mergesort(vector<int>& vec)
{
    if(vec.size() <= 1)
    {
        return vec;
    }
    
    vector<int>::iterator middle = vec.begin() + (vec.size() / 2);
 
    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());
 
    left = mergesort(left);
    right = mergesort(right);
 
    return merge(vec,left, right);
}


vector<int> merge(vector<int> &vec,const vector<int>& left, const vector<int>& right)
{
    vector<int> result;
    int li = 0, ri = 0;
 
    while(li < left.size() && ri < right.size())
    {
        if(left[li] < right[ri])
        {
            result.push_back(left[li]);
            li++;
        }
        else
        {
            result.push_back(right[ri]);
            ri++;
        }
    }

    while(li < left.size())
    {
        result.push_back(left[li]);
        li++;
    }
 
    while(ri < right.size())
    {
        result.push_back(right[ri]);
        ri++;
    }
     
	vec = result;				
	return vec;
}


int main()
{
  int a[] = {3,2,8,5,1,7,6,4};
  vector<int> v (a, a + sizeof(a) / sizeof(int) );
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
  mergesort(v);
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  cout << endl;
  
}
