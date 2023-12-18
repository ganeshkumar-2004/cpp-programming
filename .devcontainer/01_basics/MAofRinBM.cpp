#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> NSL(int arr[], int n)
{
     vector<int> v(n);
     stack<pair<int, int>> s;
     for (int i = 0; i < n; i++)
     {
          while (!s.empty() && s.top().first >= arr[i])
          {
               s.pop();
          }
          if (s.empty())
               v[i] = -1;
          else
               v[i] = s.top().second;

          s.push({arr[i], i});
     }
     return v;
}
vector<int> NSR(int arr[], int n)
{
     vector<int> v(n);
     stack<pair<int, int>> s;
     for (int i = n - 1; i >= 0; i--)
     {
          while (!s.empty() && s.top().first >= arr[i])
          {
               s.pop();
          }
          if (s.empty())
               v[i] = 4;
          else
               v[i] = s.top().second;

          s.push({arr[i], i});
     }
     return v;
}
int MAH(int arr[], int n)
{
     vector<int> Right = NSR(arr, n);
     vector<int> Left = NSL(arr, n);
     int Width[n];
     for (int i = 0; i < n; i++)
     {
          Width[i] = Right[i] - Left[i] - 1;
     }
     int Area[n];
     for (int i = 0; i < n; i++)
     {
          Area[i] = arr[i] * Width[i];
     }
     int max = -1;
     for (int i = 0; i < n; i++)
     {
          if (max <= Area[i])
               max = Area[i];
     }
     return max;
}
// int max(int a, int b){
//      if(a>b)
//        return a;
//      else 
//        return b;
// }


int main()
{
      int arr[4][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
      int n = 4;
      // _____For the Test Only______
     //  for (int i = 0; i < n; i++)
     //  {
     //       for (int j = 0; j < n; j++)
     //       {
     //            cout << arr[i][j] << " ";
     //       }
     //       cout << endl;
     //  }
     // cout << endl;
//  ____This is the mathod without loop______
//       int R1[n];
//       for (int j = 0; j < n; j++)
//       {
//            R1[j] = arr[0][j];
//       }
//        for (int i = 0; i < n; i++)
//       {
//            cout << R1[i] << " ";
//       }

//       cout << endl;
//       int maxA = MAH(R1, 4);
//       cout << maxA<< endl;
      
//       int R2[n];
//       for (int i = 1; i < 2; i++)
//       {
//            for (int j = 0; j < n; j++)
//            {
//                 if (arr[i][j] == 0)
//                      R2[j] = 0;
//                 else
//                      R2[j] = R1[j] + arr[i][j];
//            }
//       }
//       for (int i = 0; i < n; i++)
//       {
//            cout << R2[i] << " ";
//       }
      
//      cout<<endl;
//      maxA=max(maxA,MAH(R2,n));
//      cout<<maxA<<endl;
//       int R3[n];
//       for (int i = 2; i < 3; i++)
//       {
//            for (int j = 0; j < n; j++)
//            {
//                 if (arr[i][j] == 0)
//                      R3[j] = 0;
//                 else
//                      R3[j] = R2[j] + arr[i][j];
//            }
//       }
//       for (int i = 0; i < n; i++)
//       {
//            cout << R3[i] << " ";
//       }
//      cout<<endl;
//      maxA=max(maxA,MAH(R3,n));
//      cout<<maxA<<endl;
//      cout<<maxA<<endl;
//       int R4[n];
//       for (int i = 3; i < 4; i++)
//       {
//            for (int j = 0; j < n; j++)
//            {
//                 if (arr[i][j] == 0)
//                      R4[j] = 0;
//                 else
//                      R4[j] = R2[j] + arr[i][j];
//            }
//       }
//       for (int i = 0; i < n; i++)
//       {
//            cout << R4[i] << " ";
//       }
//      cout<<endl;
//      maxA=max(maxA,MAH(R4,n));
//      cout<<maxA<<endl;
//      return 0;
// }
//______Second mathod of finding Maximum Area of a Recrangle of Binary Matrix_____ 
 int R1[n];
      for (int j = 0; j < n; j++)
      {
           R1[j] = arr[0][j];
      }

      int maxA = MAH(R1, 4);
      for (int i = 1; i < n; i++)
      {
          for (int j = 0; j < n; j++)
          {
               if(arr[i][j]==0)
                 R1[j]=0;
               else
                 R1[j]=R1[j]+arr[i][j];
          }
          maxA=max(maxA,MAH(R1,n));
      }
      cout<<"Maximum Area of Ractangle in Binary Matrix  :  ";
      cout<<maxA;
      return 0;
}